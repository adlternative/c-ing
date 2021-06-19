#include<iostream>  
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<stdexcept>
using namespace std;

class TextQuery{
public:
    typedef vector<string>::size_type line_no;
    void read_file(ifstream &is){
        store_file(is);     //读取并保存输入文件
        build_map();     //创建关联单词与行号的容器
    }
    set<line_no> run_query(const string&) const;    //根据输入的字符串，在map中查找，返回一个set集合，里面包含了该字符串在文件的所有行号
    line_no size() const {return lines_of_text.size();}
    string text_line(line_no) const;     //以行号为输入参数，返回该行的字符串
private:
    void store_file(ifstream&);
    void build_map();
    vector<string> lines_of_text;    //容器lines_of_text保存文本的副本
    map<string,set<line_no> > word_map;    //first存的是单词，second存的是set集合，里面是单词所在的所有行号
};


void TextQuery::store_file(ifstream &is)    //将文本文件读入内存保存在lines_of_text容器中
{
    string textline;
    while(getline(is,textline))     //逐行存入vector
    lines_of_text.push_back(textline);
}


void::TextQuery::build_map()
{
    for(line_no line_num = 0; line_num != lines_of_text.size(); ++line_num)
    {
        istringstream line(lines_of_text[line_num]);    //将vector中的文件内容逐行提取出来
        string word;
        while(line >> word)     //将每行字符串分解成单词，插入到map中，键是单词，值是行号
        word_map[word].insert(line_num);     //*********word_map[word]返回的是右值，是一个set对象，insert()函数是set的函数********
    }
}


set<TextQuery::line_no> TextQuery::run_query(const string &query_word) const
{
    map<string,set<line_no> >::const_iterator loc = word_map.find(query_word);
    if(loc == word_map.end())
        return set<line_no>();
    else
        return loc->second;
}


string TextQuery::text_line(line_no line) const
{
    if(line < lines_of_text.size())
        return lines_of_text[line];
    throw std::out_of_range("line number out of range");
}


string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr == 1) ? word : word + ending;
}


void print_results(const set<TextQuery::line_no>& locs ,const string& sought, const TextQuery &file)
{
    typedef set<TextQuery::line_no> line_nums;
    line_nums::size_type size = locs.size();    //set集合的大小即是该单词出现的次数
    cout<<"\n"<<sought<<" occurs "<<size<<" "<<make_plural(size,"time","s") <<endl;
    line_nums::const_iterator it = locs.begin();
    for(;it != locs.end(); ++it)
        cout<<"\t(line"<<(*it)+1<<")"<<file.text_line(*it)<<endl;    //原行号从0开始，+1进行修正
}


class Query_base{
    friend class Query; //接口只提供给Query使用，用户和派生类只能通过Query句柄使用Query_base类
protected:
    typedef TextQuery::line_no line_no;
    virtual ~Query_base(){}
private:
    //eval returns the |set| of lines that this Query matches
    virtual std::set<line_no> eval(const TextQuery&) const = 0;
    //display prints the query
    virtual std::ostream& display(std::ostream& = std::cout) const = 0;
};

class WordQuery: public Query_base{
    friend class Query;
    WordQuery(const std::string &s): query_word(s) {}
    std::set<line_no> eval(const TextQuery &t) const {return t.run_query(query_word);}
    std::ostream& display(std::ostream &os) const {return os<<query_word;}
    std::string query_word;
};

class Query{
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);

public:
    Query(const std::string& word): q(new WordQuery(word)), use(new std::size_t(1)) { }
    Query(const Query &c): q(c.q), use(c.use) {++*use;}
    ~Query() {decr_use();}

    Query& operator=(const Query&);
    std::set<TextQuery::line_no> eval(const TextQuery &t) const {return q->eval(t);}
    std::ostream &display(std::ostream &os) const {return q->display(os);}

private:
    Query(Query_base * query): q(query), use(new std::size_t(1)) {} //我们不希望普通用户代码定义Query_base对象。因为是private权限，操作符必须是友元
    Query_base * q;
    std::size_t *use;
    void decr_use()
    {
        if(--*use == 0)
        {
            delete q;
            delete use;
        }
    }
};

inline std::ostream& operator<<(std::ostream &os, const Query &q)
{
    return q.display(os);
}

class NotQuery: public Query_base{
    friend Query operator~(const Query&);
    NotQuery(Query q): query(q){}
    std::set<line_no> eval(const TextQuery &) const;
    std::ostream& display(std::ostream &os) const {return os<<"~("<<query<<")";}
    const Query query;              //why const?
};

class BinaryQuery: public Query_base{   //未实现eval函数，因此是一个抽象类
protected:
    BinaryQuery(Query left, Query right, std::string op): lhs(left), rhs(right), oper(op) {}
    std::ostream& display(std::ostream &os) const {return os<<"("<<lhs<<" "<<oper<<" "<<rhs<<")";}
    const Query lhs, rhs;
    const std::string oper;
};

class AndQuery: public BinaryQuery{
    friend Query operator&(const Query&, const Query &);
    AndQuery(Query left, Query right): BinaryQuery(left, right, "&") {}
    std::set<line_no> eval(const TextQuery&) const;
};


class OrQuery: public BinaryQuery{
    friend Query operator|(const Query&, const Query&);
    OrQuery(Query left, Query right): BinaryQuery(left, right, "|") {}
    std::set<line_no> eval(const TextQuery&) const;
};

set<TextQuery::line_no> OrQuery::eval(const TextQuery& file)const
{
    set<line_no> right = rhs.eval(file),
             ret_lines = lhs.eval(file);
    ret_lines.insert(right.begin(), right.end());
    return ret_lines;
}

set<TextQuery::line_no> AndQuery::eval(const TextQuery& file) const
{
    set<line_no> left = lhs.eval(file),
                right = rhs.eval(file);
    set<line_no> ret_lines;
    set_intersection(left.begin(), left.end(), right.begin(), right.end(), inserter(ret_lines, ret_lines.begin())); //调用STL库函数进行容器的交集操作
    return ret_lines;
}

set<TextQuery::line_no> NotQuery::eval(const TextQuery& file) const     //const引用的对象，只能访问对象的const成员，所以size函数必须是const类型的
{
    set<TextQuery::line_no> has_val = query.eval(file);
    set<line_no> ret_lines;
    for(TextQuery::line_no n = 0; n != file.size(); ++n)
        if(has_val.find(n) == has_val.end())
            ret_lines.insert(n);
    return ret_lines;
}


inline Query operator~(const Query &oper) 
{
    return new NotQuery(oper);              //等价于Query_base * tmp = new NotQuery(oper); return Query(tmp);
}

inline Query operator|(const Query &lhs, const Query &rhs)
{
    return new OrQuery(lhs,rhs);
}

inline Query operator&(const Query &lhs, const Query &rhs)
{
    return new AndQuery(rhs,lhs);
}


int main()
{
    ifstream infile;
    infile.open("a.txt");
    if(!infile)
    {
        std::cout<<"Cannot open file"<<std::endl;
        exit(1);
    }
    TextQuery tq;
    tq.read_file(infile);

        /* 该处填写要查找的内容逻辑表达式 */
        //set<TextQuery::line_no> locs = tq.run_query(s);
        //Query q = ~(Query("today") & Query("API"));
        Query q = Query("aaa") |Query("adl");
        set<TextQuery::line_no> locs = q.eval(tq);
        string s = "#";
        print_results(locs,s,tq);
 return 0;
}
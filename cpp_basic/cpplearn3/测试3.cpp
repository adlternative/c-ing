#include <iostream>
#include<fstream>
#include<sstream>
#include <string>
#include<cassert>
#include <vector>
#include"../cpplearn2/Sales_data.h"
#include"../cpplearn2/Sales_item.h"
#include<list>
#include<deque>
#include<array>
#include<forward_list>
#include<unistd.h>
#include<stack>
#include<queue>

using namespace std;
// istream&sad(istream&is)
// {
//     int a;
//     do{
//         is>>a;
//         if(is.rdstate()&is.eofbit){
//             cout<<"eof"<<endl;
//             is.clear(~cin.eofbit);
//             is.clear();
//         }else if(is.rdstate()&is.failbit){
//             cout<<"fail"<<endl;
//             is.clear(~cin.failbit);
//         }else if(is.rdstate()&is.badbit){
//             cout<<"bad"<<endl;
//             is.clear(~cin.badbit);
//         }else if(is.rdstate()&is.goodbit){
//             cout<<"good"<<endl;
//         }
//             // is.clear();
            
//     }while(!(is.rdstate()&is.eofbit));
//         cout<<"bye"<<endl;
//     return is;
// }
istream&streamFunc(istream&in)
{
    string s;
    while(in>>s){
        cout<<s<<" ";
    }
    cout<<endl;
    in.clear();
    return in;
}
int main(int argc,char **argv)
{
    stack<char>s;
    string ok;
    string str;
    cin>>str;
    bool flag=0;
    for (auto &i : str)
    {
        s.push(i);
        if(i=='('){
            flag=1;
        }
        if(i==')'&&flag){
            while(s.top()!='('){
                s.pop();
            }
            s.pop();
            flag=false;
            s.push('*');
        }
    }
    while(!s.empty()){
        // ok.push_back(s.top());
        ok.insert(ok.begin(),s.top());
        s.pop();
    }
    // for(auto &i:ok){
    //     cout<<i;
    // }
    cout<<ok<<endl;
    // deque<int>deq;
    // stack<int>stk(deq);
    // stack<string,vector<string>>str_stk;
    // vector<string>svec;
    // stack<string,vector<string>>str_strk2(svec);
    // priority_queue<int>pq;
    // // int i=42;
    // // string s=to_string(i);
    // // double d=stod(s);
    // vector<string>v;
    // v.push_back("14");
    // v.push_back("15");
    // v.push_back("13");
    // v.push_back("12");
    // int count=0;
    // for (auto &i : v)
    // {
    //     size_t p=0;
    //     int getint=stoi(i,&p);
    //     // if(p!=0){
    //     //     cerr<<"!!";
    //     //     continue;
    //     // }else {
    //         count+=getint;
    //     // }
    // }
    // cout<<count<<endl;
    
    // vector<string>v;
    // string str;
    // string cond("pqdflkjhgbiyt");
    // ifstream is("a.txt");
    // string::size_type pos=0;
    // string::size_type maxsize=0;
    // string maxstring;
    // while(is>>str){
    //     if((pos=str.find_first_of(cond))==str.npos){
    //         v.push_back(str);
    //         if(str.size()>maxsize){
    //             maxstring.assign(str);
    //         }
    //     }
    // }
    // cout<<maxstring<<endl;


    // string s("asdl143sjewipqfjLEJIDL319879");
    // string num("1234567890");
    // vector<char>vc;
    // vector<char>vi;
    // string::size_type pos=0;
    //     while((pos=s.find_first_of(num,pos))!=s.npos){
    //         vi.push_back(s[pos]);
    //         // cout<<pos<<endl;
    //         pos++;
    //     }
    //     pos=0;
    //      while((pos=s.find_first_not_of(num,pos))!=s.npos){
    //         vc.push_back(s[pos]);
    //         pos++;
    //     }       
    
    //    for(auto &i:vc){
    //     cout<<i<<endl;
    // }
    //    for(auto &i:vi){
    //     cout<<i<<endl;
    // }
    // string s1("AdL");char c;
    // // s1.insert(0,"Mr");
    // // s1.append("III");
    // s1.insert(0,"ms");
    // s1.insert(s1.size(),"JR.");
    // cout<<s1;
    // string numbers("0123456789"),name("r2d2");
    // auto pos=name.find_first_of(numbers);
    // cout<<pos<<endl;
    // string dept("024a3");
    // auto pos2 =dept.find_first_not_of(numbers);
    // cout<<pos2<<endl;

    // s1.reserve(100);
    // while(cin>>c)
    //     s1.push_back(c);
    // cout<<s1;
    // string s("hello world");
    // string s4=s.substr(0,5);
    // string s5=s.substr(6,11);
    // cout<<s4<<" "<<s5;
    // vector<int>v;
    // while(1){
    //     v.push_back(1);
    //     cout<<v.size()<<" "<<v.capacity()<<endl;
    //     usleep(100);
    // }
    // v.reserve(10);
    // v.capacity ();
    // v.shrink_to_fit();
    // list<int>l1={0,1,2,3,4,5,6,7,8,9};
    // auto iter=l1.begin();
    // while(iter!=l1.end()){
    //     if(*iter%2){
    //         iter=l1.insert(iter,*iter);
    //         iter++;
    //         iter++;
    //     }else
    //         iter=l1.erase(iter);
    // }
    // forward_list<int >fl={0,1,2,3,4,5,6,7,8,9};
    // auto b_iter=fl.before_begin();
    // auto iter=fl.begin();
    // while(iter!=fl.end()){
    //     if(*iter%2){
    //         iter=fl.insert_after(b_iter,*iter);
    //         // cout<<*iter;
    //         b_iter=iter;
    //         iter++;
    //         iter++;
    //         // cout<<"?";
    //     }else{
    //         iter=fl.erase_after(b_iter);
    //         // cout<<"!";
    //     }
    // }
    //    for(auto &i:fl){
    //     cout<<i<<endl;
    // }
    // forward_list<int>fl(10,2);
    // fl.push_front(3);
    // fl.push_front(5);
    // fl.push_front(7);
    // fl.push_front(8);
    // auto bb=fl.before_begin();
    // auto b=fl.begin();
    // while(b!=fl.end()){
    //     if((*b%2)==1){
    //         b=fl.erase_after(bb);
    //     }
    //     else{
    //         bb=b;
    //         b++;
    //     }
    // }
    //     for(auto &i:fl){
    //     cout<<i<<endl;
    // }
    // forward_list<string>fls;
    // string a("aa");
    // string b("bbbb");
    // string f("f");
    // string in("in");
    // string no("no");
    // auto  fbb=fls.before_begin();
    // fls.insert_after(fbb,10,b);
    // // fls.push_front(b);
    // fls.push_front(f);
    // auto fb=fls.begin();
    // while(fb!=fls.end()&&*fb!=f){
    //         fb++;
    //         fbb++;
    // }    
    // if(fb==fls.end()){
    //     fls.insert_after(fbb,no);
    // }else{
    //     fls.insert_after(fbb,in);
    // }
    // for(auto &i:fls){
    //     cout<<i<<endl;
    // }

    // list<int> ll(19,2);
    // ll.insert(ll.begin(),3,3);
    // vector<int>iv{1,2,3,4,5,5,6,7};
    // vector<int>::iterator iter=iv.begin(),mid=iv.begin()+iv.size()/2;
    // while(iter!=mid){
    //     if(*iter==3){
    //         iv.insert(iter,2*3);
    //     }
    //     iter++;
    // }
    // for(auto &i:ll){
    //     cout<<i<<endl;
    // }
        
    // vector<int>::difference_type count=iv.end()-iv,begin();
    // vector<int>::iterator mid=(iter+count);

    // list<int >l{1,2,3,4,5,6,7,8,9,10};
    // deque<int>j,o;
    // string str;
    // vector<string>v;
    // auto iter=v.begin();
    // while(cin>>str){
    //     iter=v.insert(iter,str);
    // }

    // for (auto &i : l)
    // {
    //     if(i%2==0){
    //         j.push_back(i);
    //     }else{
    //         o.push_back(i);
    //     }
    // }
    // for(auto &i:v){
    //     cout<<i<<endl;
    // }
    // string str;deque<string>d;
    // list<string>l;
    // while(cin>>str){
    //     l.push_back(str);
    // }
    // while(cin>>str){
    //     // d.insert(d.begin(),str);
    //     d.push_back(str);
    // }
    // vector<int>v={1,2,3,4};
    // auto iter =v.begin();
    // v.emplace(iter,2);
    // for (auto &i : l)
    // {
    //     cout<<i<<endl;
    // }
    // list<const char*>lcc(10,"sad");
    // vector<string>vs(10,"a");
    // vs.assign(lcc.cbegin(),lcc.cend());
    // for (auto &i : vs)
    // {
    //     cout<<i<<endl;
    // }
    
    // array<int,42>a;
    // array<string,10>b;
    // array<string,10>::size_type i;
    // vector<int> c{1,2,3,4,5,6,7,8,9,0};
    // auto p=c.begin()+7;
    // cout<<*p<<" "<<&p<<endl;
    // vector<int> d{10,9,8,7,6,5,2,3,4,2};
    // c=d;
    // cout<<*p<<" "<<&p<<endl;
    // ++p;
    // cout<<*p<<" "<<&p<<endl;
    // c={1,2};//a={1,2};
    // list<int> seq(10);
    // vector<int >::iterator it;
    // vector<int>::difference_type count;
    // list<string>::iterator lsit;
    // list<string>::difference_type lscount;
    // const list<string>a={"a","s","d"};
    // auto it1=a.rbegin();//std::reverse_iterator<std::__cxx11::list<std::__cxx11::string>::const_iterator> it1
    // auto it1=a.begin();//std::__cxx11::list<std::__cxx11::string>::const_iterator it1
    // list<int >lst1(10,2);
    // lst1.push_back(1);
    // list<int >::iterator iter1=lst1.begin();
    // list<int >::iterator iter2=lst1.end();
    // while(iter1!=iter2){
    //     iter1++;
    // }
    // list<deque<int>>l;   
    // vector<int>v(10,2);
    // v.push_back(1);
    
    // for(vector<int>::iterator it=v.end()-1;it!=v.begin()-1;it--)
    // {
    //     cout<<*it<<endl;
    // }
    // for(vector<int>::reverse_iterator it=v.end()-1;it!=v.begin()-1;it--)
    // {
    //     cout<<*it<<endl;
    // }
    // ofstream out("file1",ofstream::out|ofstream::app);
    // out.close();
    // cout<<"hi"<<flush;

    // cout<<"hi"<<ends;
    // cout<<unitbuf;
    // cout<<nounitbuf;
    // cin.tie(&cout);
    // ostream*old_tie =cin.tie(nullptr);
    // cin.tie(&cerr);
    // cin.tie(old_tie);
    // ifstream input(argv[1]);
    // ofstream output(argv[2]);
    // Sales_data total;
    // if(read(input,total)){
    //     Sales_data trans;
    //     while(read(input,trans)){
    //         if(trans.isbn()==total.isbn()){
    //             total.combine(trans);
    //         }else{
    //             print(output,total)<<endl;
    //             total=trans;
    //         }
    //     }
    //     print(output,total)<<endl;
    // }else
    //     cerr<<"no data?!"<<endl;
    // string ifile("a");
    // ifstream in(ifile);
    // ofstream out;
    // out.open(ifile+".copy");
    // if(out){puts("打开成功");}
    // in.close();
    // in.open(ifile+"2");
    // struct PersonInfo{
    //     string name;
    //     vector<string>pthones;
    // };
    // string line,word;
    // vector<PersonInfo>people;
    // while(getline(cin,line)){
    //     PersonInfo info;
    //     istringstream record(line);
    //     record>>info.name;
    //     while(record>>word)
    //         info.pthones.push_back(word);
    //     people.push_back(info);
    // }
    
    // vector<string>v;
    // string temp;

    // istringstream recod;
    // for(auto p=argv+1;p!=argv+argc;++p){
    //     ifstream input(*p);
    //     if(input){
    //         while(getline(input,temp)/*input>>temp*/){
    //             // v.push_back(temp);
    //             recod.clear();   //修改，将record的状态复位
    //             recod.str(temp);
    //             string s;
    //             // cout<<temp<<endl;
    //             while(recod>>s){
    //                 // cout<<s<<endl;
    //                 v.push_back(s);
    //             }
    //         }
                    
                
    //     }else
    //         cerr<<" could not open:"+string(*p);
    // }
    // for (auto &str : v)
    // {
    //     cout<<str<<endl;
    // }
    

    // sad(cin);
    // istream qain,qaout;
    // ofstream out1,out2;
    // // ostream a,b;
    // // out 1=out2;
    // ofstream print(ofstream);//？
    // // ofstream printt(out1);
    // // out2= print(out2);
    // // strm::iostate;
    // int ival,a;
    // cin>>ival;
    // auto old_state =cin.rdstate();
    // cin.clear();
    // cin>>a;
    // cin.setstate(old_state);
    // cin.clear(cin.rdstate()&~cin.failbit&~cin.badbit);

    // cout<<ival;


}
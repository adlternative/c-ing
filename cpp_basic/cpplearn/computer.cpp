#include <iostream>
using namespace std;
class CPU
{

public:
    CPU();
    ~CPU();
    virtual void calculate() = 0;
};
void CPU::calculate()
{
    cout << "我计算" << endl;
}

CPU::CPU()
{
}
CPU::~CPU()
{
}
class CPU2 : public CPU
{

public:
    CPU2();
    ~CPU2();
    virtual void calculate()
    {
        cout << "wosuan" << endl;
    }
};

CPU2::CPU2()
{
}

CPU2::~CPU2()
{
}

class Memory 
{
public:
    virtual void storage() = 0;
    Memory();
    ~Memory();
};
void Memory::storage()
{
    cout << "我存储" << endl;
}

Memory::Memory()
{
}

Memory::~Memory()
{
}
class Memory2:public Memory
{
private:
public:
    virtual void storage()
    {
        cout << "wocun" << endl;
    }
    Memory2();
    ~Memory2();
};

Memory2::Memory2()
{
}

Memory2::~Memory2()
{
}

class VideoCard
{
public:
    virtual void display() = 0;
    VideoCard();
    ~VideoCard();
};
void VideoCard::display()
{
    cout << "我显示" << endl;
}
VideoCard::VideoCard()
{
}

VideoCard::~VideoCard()
{
}
class VideoCard2 :public VideoCard
{
private:
    /* data */
public:
    virtual void display()
    {
        cout << "woxian" << endl;
    }
    VideoCard2();
    ~VideoCard2();
};

VideoCard2::VideoCard2()
{
}

VideoCard2::~VideoCard2()
{
}

ostream &operator<<(ostream &cout, Memory &m)
{
    m.storage();
    cout << "ok";
    return cout;
}
ostream &operator<<(ostream &cout, VideoCard &vc)
{
    vc.display();
    cout << "ok2";
    return cout;
}
ostream &operator<<(ostream &cout, CPU &c)
{
    c.calculate();
    cout << "ok3";
    return cout;
}
class Computer
{
private:
    CPU *c;
    VideoCard *vcd;
    Memory *m;

public:
    Computer(CPU *cpu, VideoCard *vc, Memory *my)
    {
        c = cpu;
        vcd = vc;
        m = my;
    }
~Computer()
{
    if(c!=NULL)
    {
        delete c;
        c=NULL;
    }
    if(vcd!=NULL)
    {
        delete vcd;
        vcd=NULL;
    }
    if(m!=NULL)
    {
        delete m;
        m=NULL;
    }

}
    void work()
    {
        m->storage();
        c->calculate();
        vcd->display();
    }
};
void test01()
{
    CPU*c=new CPU2;
    VideoCard*vc=new VideoCard2;
    Memory*m=new Memory2;
    Computer*computer=new Computer(c,vc,m);
    computer->work();
    delete computer;

}
int main()
{
    test01();
}
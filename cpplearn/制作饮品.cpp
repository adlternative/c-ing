#include<iostream>
using namespace std;

class AbstractDrinking
{
public:
    virtual void Boil()=0;
    virtual void Brew()=0;
    virtual void PourInCup()=0;
    virtual void PutSomething()=0;
    void makeDrink()
    {
        Boil();
        Brew();
        PourInCup();
        PutSomething();
    }
public:
    AbstractDrinking();
    ~AbstractDrinking();
};

AbstractDrinking::AbstractDrinking()
{
}

AbstractDrinking::~AbstractDrinking()
{
}
class Coffee    :public AbstractDrinking
{
public:
    virtual void Boil()
    {
        cout<<"shui"<<endl;
    }
    virtual void Brew()
    {
        cout<<"piaokafei"<<endl;
    }
    virtual void PourInCup()
    {
        cout<<"daoru"<<endl;
    }
    virtual void PutSomething()
    {
        cout<<"tangheniunai"<<endl;
    }
};
class Tea    :public AbstractDrinking
{
public:
    Tea();
    ~Tea();
    virtual void Boil()
    {
        cout<<"daoshui"<<endl;
    }
    virtual void Brew()
    {
        cout<<"piaochaye"<<endl;
    }
    virtual void PourInCup()
    {
        cout<<"2daoru"<<endl;
    }
    virtual void PutSomething()
    {
        cout<<"fangrurenniao"<<endl;
    }
};
Tea::Tea()
{
}

Tea::~Tea()
{
}
void doWork(AbstractDrinking*abs)
{
    abs->makeDrink();
    delete abs;
}
void test01()
{
    doWork(new Coffee);
}
void test02()
{
    doWork(new Tea);
}

int main()
{
    test01();
    test02();

}
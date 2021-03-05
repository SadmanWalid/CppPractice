#include<iostream>
#include <string>
using namespace std;

class LogicGate // Base Class
{
    public:
     LogicGate(string name)
     {
         label=name;
     }
     string getLabel()
     {
         return label;
     }
     bool getOutput()
     {
         output=performGateLogic();
         return output;
     }
     virtual bool performGateLogic()
     {
         cout<<"Error!!!Form base class";
         return 0;   
     }
     virtual void setNextPin(bool source)
    {
        cout<<"Error!!!setNextPin base"<<endl;
    }

     protected:
     string label;
     bool output;

};

class BinaryGate: public LogicGate //derived class from LogicGate class
{
    public:
    BinaryGate(string name):LogicGate(name)
    {
        pinATaken=false;
        pinBTaken=false;
    }
    bool getPinA()
    {
        if(pinATaken==false)
        {
            cout<<"Enter Pin A value for Logic gate "<<getLabel()<<endl;
            cin>>pinA;
            pinATaken=true;
        }
        return pinA;
    }
    bool getPinB()
    {
        if(pinBTaken==false)
        {
            cout<<"Enter Pin B value for logic gate "<<getLabel()<<endl;
            cin>>pinB;
            pinBTaken=true;
        }
        return pinB;
    }
    virtual void setNextPin(bool source)
    {
        if(pinATaken==false)
        {
            pinA=source;
            pinATaken=true;
        }
        else if(pinBTaken==false)
        {
            pinB=source;
            pinBTaken=true;
        }

    }

    protected:
    bool pinA;
    bool pinATaken;
    bool pinB;
    bool pinBTaken;

};

class UnaryGate: public LogicGate //derived class from LogicGate class
{
    public:
    UnaryGate(string name):LogicGate(name)
    {
        pinTaken=false;
    }
    bool getPin()
    {
        if(pinTaken==false)
        {
            cout<<"Enter Pin  value for Logic gate "<< getLabel()<<endl;
            cin>>pin;
            pinTaken=true;
        }
        return pin;
    }
    virtual void setNextPin(bool source)
    {
        if(pinTaken==false)
        {
            pin=source;
            pinTaken=true;
        }
    }
    protected:
    bool pin;
    bool pinTaken;

};

class AndGate: public BinaryGate //derived class from BinaryGate class
{
  public:
    AndGate(string name): BinaryGate(name)
    {}
    virtual bool performGateLogic()
    {
        bool a=getPinA();
        bool b=getPinB();
        if(a==1&&b==1)
         return true;
        else
         return false;
    }
};

class OrGate: public BinaryGate //derived class from BinaryGate class
{
    OrGate(string name):BinaryGate(name)
    {}
    virtual bool performGetLogic()
    {
        bool a=getPinA();
        bool b=getPinB();
        if(a==1 || b==1)
         return true;
        else 
         return false;
    }
};

class NotGate :public UnaryGate //derived class from unaryGate class
{
    public:
    NotGate(string name): UnaryGate(name)
    {}
    virtual bool performGateLogic()
    {
        bool a=getPin();
        if (a==1)
         return false;
        else if(a==0)
         return true; 
      return 0;   
    }
};


int main()
{
    NotGate gatetest (" gatetest ");
    bool result=gatetest.getOutput();
    cout<<"result: "<<result;
    return 0;
}
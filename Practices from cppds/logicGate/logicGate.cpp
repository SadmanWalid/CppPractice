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
     bool getOutput() //return output
     {
         output=performGateLogic();
         return output;
     }
     virtual bool performGateLogic() 
     {
         cout<<"Error!!!Form base class"<<endl;
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
     void setNextPin(bool source)
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
     void setNextPin(bool source)
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
    public:

    OrGate(string name):BinaryGate(name)
    {}
    virtual bool performGateLogic()
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
class NorGate : public BinaryGate //NorGate implementation
{
  public:
  NorGate(string name):BinaryGate(name)
  {}
  bool performGateLogic()
  {
      bool a=getPinA();
      bool b=getPinB();
      if(a==0 && b==0)
        return true;
      else if(a==1 || b==1)
       return false;
    return 0;
  }


};

class Connector
{
    private:
     LogicGate *fromGate, *toGate;
    public:
     Connector(LogicGate *gateFromWhereInputCome, LogicGate *gateTowhereInputGO)
     {
         fromGate=gateFromWhereInputCome;
         toGate=gateTowhereInputGO;
         toGate->setNextPin(fromGate->getOutput());
     }
     LogicGate *getFrom()
     {
         return fromGate;
     }
     LogicGate *GetTo()
     {
         return toGate;
     }

};
int main()
{   //creating gate objects
    AndGate and1("AND1"); 
    AndGate and2("AND2");
    OrGate or1("OR1");
    //assigning valuw to and gates
    bool and1A,and1B,and2A,and2B;
    cout<<"Enter value for pinA of "<<and1.getLabel()<<": ";
    cin>>and1A;
    cout<<"Enter value for pinb of "<<and1.getLabel()<<": ";
    cin>>and1B;
    cout<<"Enter value for pinA of "<<and2.getLabel()<<": ";
    cin>>and2A;
    cout<<"Enter value for pinB of "<<and2.getLabel()<<": ";
    cin>>and2B;
    and1.setNextPin(and1A);
    and1.setNextPin(and1B);
    and2.setNextPin(and2A);
    and2.setNextPin(and2B);

    //making connection
    Connector c1(&and1,&or1);
    Connector c2(&and2,&or1);

    bool result=or1.getOutput();

    cout<<and1.getLabel()<<" : pinA:"<<and1.getPinA()<<" || pinB:"<<and1.getPinB()<<endl;
    cout<<and2.getLabel()<<" : pinA:"<<and2.getPinA()<<" || pinB:"<<and2.getPinB()<<endl;

    cout<<"result: "<<result;


    return 0;
}
#include <iostream>

using namespace std;




int gcf(int top, int bottom) //find greatest common factor between two intiger numbers. Euclid’s Algorithm states that the greatest common divisor of two integers m and n is n if n divides m evenly. However, if n does not divide m evenly, then the answer is the greatest common divisor of n and the remainder of m divided by n. 
{
    while (top % bottom != 0)
    {
        int newTop = bottom;
        int newBottom = top % bottom;
        top = newTop;
        bottom = newBottom;
    }
    return bottom;
}

class Fraction //fraction class
{

    int num, de;

public:
    Fraction(int top = 0, int bottom = 1) //constructor
    {
        //to do zero checking for denominator
        int greatestCommonFactor = gcf(top, bottom);
        num = top / greatestCommonFactor;
        de = bottom / greatestCommonFactor;
        cout << num << "/" << de << endl;
    }
    Fraction addition(Fraction one, Fraction two) // addition as class function
    {
        int newNum = one.num * two.de + one.de * two.num;
        int newDe = one.de * two.de;
        return Fraction(newNum, newDe);
    }
    void show() //print as class function
    {
        cout << "Fraction :" << num << "/" << de << endl;
    }
    friend ostream &operator<<(ostream &display, const Fraction frac);     //friend function to overload operator << to display fraction
    friend Fraction operator+(const Fraction frac1, const Fraction frac2); //friend function to overload operator +
    friend Fraction operator-(const Fraction frac1, const Fraction frac2); //friend function to overload operator -
    friend Fraction operator*(const Fraction frac1, const Fraction frac2); //friend function to overload operator *
    friend Fraction operator/(const Fraction frac1, const Fraction frac2); //friend function to overload operator /
    friend void operator==(const Fraction frac1, const Fraction frac2);//friend function to overload operator == to compare is two function are equal
    friend void operator>=(const Fraction frac1,const Fraction frac2); // to overload >= operator
    friend void operator<=(const Fraction frac1,const Fraction frac2); // to overload <= operator
}; 
ostream &operator<<(ostream &display, const Fraction frac) // operator << overloading
{
    display << "Fraction :" << frac.num << "/" << frac.de;
    return display;
}

Fraction operator+(const Fraction frac1, const Fraction frac2) //operator + overloading
{
    
    int newNum= frac1.num * frac2.de + frac1.de * frac2.num;
    int newDe = frac1.de * frac2.de;
    return Fraction(newNum,newDe);
}

Fraction operator-(const Fraction frac1, const Fraction frac2) //operator - overloading
{
    
    int newNum = frac1.num * frac2.de - frac1.de * frac2.num;
    int newDe = frac1.de * frac2.de;
    return Fraction(newNum,newDe);
}
Fraction operator*(const Fraction frac1, const Fraction frac2) //operator * overloading
{
   
    int newNum = frac1.num * frac2.num;
    int newDe = frac1.de * frac2.de;
    return Fraction(newNum,newDe);
}

Fraction operator/(const Fraction frac1, const Fraction frac2) //operator / overloading
{
   
    int newNum = frac1.num * frac2.de;
    int newDe = frac1.de * frac2.num;
    return Fraction(newNum,newDe);
}
void operator==(const Fraction frac1, const Fraction frac2) // operator == overloading
{
  int num1=frac1.num*frac2.de;
  int num2=frac2.num*frac1.de;
  if(num1==num2)
   cout<<"they are equal"<<endl;
  else
   cout<<"They are not equal"<<endl;
}

void operator>=(const Fraction frac1,const Fraction frac2)// operator >= overloading
{
    int fracOne=frac1.num*frac2.de;
    int fracTwo=frac2.num*frac1.de;

    if (fracOne>fracTwo)
      cout<<"Fraction "<<frac1.num<<"/"<<frac1.de<<" is bigger than "<<frac2.num<<"/"<<frac2.de<<endl;
    else if (fracTwo>fracOne)
      cout<<"Fraction "<<frac2.num<<"/"<<frac2.de<<" is bigger than "<<frac1.num<<"/"<<frac1.de<<endl;
    else
       cout<<"They are equal"<<endl;
}
void operator<=(const Fraction frac1,const Fraction frac2)// operator <= overloading
{
    int fracOne=frac1.num*frac2.de;
    int fracTwo=frac2.num*frac1.de;

    if (fracOne<fracTwo)
      cout<<"Fraction "<<frac1.num<<"/"<<frac1.de<<" is smaller than "<<frac2.num<<"/"<<frac2.de<<endl;
    else if (fracTwo<fracOne)
      cout<<"Fraction "<<frac2.num<<"/"<<frac2.de<<" is smaller than "<<frac1.num<<"/"<<frac1.de<<endl;
    else
       cout<<"They are equal"<<endl;
}
int main() //main function
{
    Fraction fr1(5, 15);
    Fraction fr2(5, 15);
    Fraction fr3;
    //fr3=fr3.addition(fr1,fr2);
    fr3 = fr1 /fr2;
    cout << fr3<<endl;
    fr1<=fr2;
    fr1>=fr2;
    

    return 0;
}

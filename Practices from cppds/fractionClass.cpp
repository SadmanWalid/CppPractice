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
};
ostream &operator<<(ostream &display, const Fraction frac) // operator << overloading
{
    display << "Fraction :" << frac.num << "/" << frac.de;
    return display;
}

Fraction operator+(const Fraction frac1, const Fraction frac2) //operator + overloading
{
    Fraction newFrac;
    newFrac.num = frac1.num * frac2.de + frac1.de * frac2.num;
    newFrac.de = frac1.de * frac2.de;
    return newFrac;
}

Fraction operator-(const Fraction frac1, const Fraction frac2) //operator - overloading
{
    Fraction newFrac;
    newFrac.num = frac1.num * frac2.de - frac1.de * frac2.num;
    newFrac.de = frac1.de * frac2.de;
    return newFrac;
}

Fraction operator*(const Fraction frac1, const Fraction frac2) //operator * overloading
{
    Fraction newFrac;
    newFrac.num = frac1.num * frac2.num;
    newFrac.de = frac1.de * frac2.de;
    return newFrac;
}

Fraction operator/(const Fraction frac1, const Fraction frac2) //operator / overloading
{
    Fraction newFrac;
    newFrac.num = frac1.num * frac2.de;
    newFrac.de = frac1.de * frac2.num;
    return newFrac;
}

int main() //main function
{
    Fraction fr1(12, 9);
    Fraction fr2(3, 4);
    Fraction fr3;
    //fr3=fr3.addition(fr1,fr2);
    fr3 = fr1 * fr2;
    cout << fr3;

    return 0;
}

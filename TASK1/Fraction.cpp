/*1) Construct the fraction class for the rational numbers. It should have overloaded compound assingment and arithmetical operators following the rules we discussed in the class,
 getters and setters, << and >> operators, constructors and assingment operator. You should always have simplified version of the fraction after all the operations. Write the function to convert the fraction into the "double" type. Please verify that all of your implemented operations work properly before sending the solution. */



#pragma once
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Fraction{
private:
    int n;
    int d;
public:
    // Setter
    void setNumerator(int n){
        this -> n = n;
    }
    void setDenominator(int d){
        this -> d = d;
    }
    // Getter
    int getNumerator(){
        return n;
    }
    int getDenominator(){
        return d;
    }
    /* Constructor */
    Fraction(){                 // Default Constructor 
        n = 0;
        d = 1;
    }
    Fraction(int n, int d){
        if (d == 0){
            cout << "ERROR:  ATTEMPING TO DIVIDE BY ZERO." << endl;   // Return announcement when denominator is 0.
            exit(0);
        }
        this -> n  = n;
        this -> d = d;
        ReduceFraction(this->n, this->d);
    }
    /*Destructor*/
    ~Fraction(){}
    /* Use Euclidean algorithm to find greatest common divisor */
    int gcd(int a, int b){
        int temp;

    a = abs(a);
    b = abs(b);

    if (b > a) {
        temp = a;
        a = b;
        b = temp;
    }

    while(b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }

    return a;
    }

    /* Reduce fractional number function */
    void ReduceFraction(int n, int d){
        this->n = n / gcd (n,d);
        this->d = d / gcd (n,d);    
    }
    /* Function convert Fraction to Double */
    double convertFractionToDouble(){
        return (double)this->n / (double)this->d;
    }
    /* Arithmetical Operators: +, -, *, / */
    Fraction operator +(Fraction frac)
    {
        Fraction result;
        result.setNumerator(this->n * frac.getDenominator() + frac.getNumerator() * this->d);
        result.setDenominator(this->d * frac.getDenominator());
        result.ReduceFraction(result.getNumerator(),result.getDenominator());
        return result;
    }
    Fraction operator -(Fraction frac){
        Fraction result;
        result.setNumerator(this->n * frac.getDenominator() - frac.getNumerator() * this->d);
        result.setDenominator(this->d * frac.getDenominator());
        result.ReduceFraction(result.getNumerator(),result.getDenominator());
        return result;
    };
    Fraction operator *(Fraction frac){
        Fraction result;
        result.setNumerator(this->n * frac.getNumerator());
        result.setDenominator(this->d * frac.getDenominator());
        result.ReduceFraction(result.getNumerator(),result.getDenominator());
        return result;
    };
    Fraction operator /(Fraction frac){
        Fraction result;
        result.setNumerator(this->n * frac.getDenominator());
        result.setDenominator(this->d * frac.getNumerator());
        result.ReduceFraction(result.getNumerator(),result.getDenominator());
        return result;
    };
    /* Assignment operator :+= , -=, *=, /=, ++, -- */
    Fraction operator +=(Fraction frac){
        this->n =  this->n * frac.getDenominator() + frac.getNumerator() * this->d;
        this->d = this->d * frac.getDenominator();
        ReduceFraction(this->n, this->d);
        return *this;
    }
    Fraction operator -=(Fraction frac){
        this->n =  this->n * frac.getDenominator() - frac.getNumerator() * this->d;
        this->d = this->d * frac.getDenominator();
        ReduceFraction(this->n, this->d);
        return *this;
    }
    Fraction operator *=(Fraction frac){
        this->n = this->n * frac.getNumerator();
        this->d = this->d * frac.getDenominator();
        ReduceFraction(this->n, this->d);
        return *this;
    }
    Fraction operator /=(Fraction frac){
        this->n = this->n * frac.getDenominator();
        this->d = this->d * frac.getNumerator();
        ReduceFraction(this->n, this->d);
        return *this;
    }
    Fraction operator ++(){
        this->n = this->n + this->d;
        ReduceFraction(this->n, this->d);
        return *this;
    }
    Fraction operator --(){
        this->n = this->n - this->d;
        ReduceFraction(this->n, this->d);
        return *this;
    }
    /* Arithmetic operator: <, >, <=, >=, ==, != */
    bool operator < (Fraction frac) {
        return ((this->n * frac.getDenominator() - frac.getNumerator() * this->d) < 0);
    }
    bool operator > (Fraction frac){
        return ((this->n * frac.getDenominator() - frac.getNumerator() * this->d) > 0);
    }
    bool operator == (Fraction frac){
        return ((this->n * frac.getDenominator() - frac.getNumerator() * this->d) == 0);
    }
    bool operator != (Fraction frac){
        return ((this->n * frac.getDenominator() - frac.getNumerator() * this->d) != 0);
    }
    bool operator <= (Fraction frac){
        return ((this->n * frac.getDenominator() - frac.getNumerator() * this->d) <= 0);
    }
    bool operator >= (Fraction frac){
        return ((this->n * frac.getDenominator() - frac.getNumerator() * this->d) >= 0);
    }
};
/* Ostream operator overloading << */
ostream& operator<<(ostream &cout, Fraction &Fraction) {
	cout << Fraction.getNumerator() << "/" << Fraction.getDenominator();
	return cout;
    }
/* Istream operator overloading << */
istream &operator>>(istream &cin, Fraction &Fraction) {
    int n, d;
    
    cin >> n >> d;

    Fraction.setNumerator(n);
    Fraction.setDenominator(d);
    if (Fraction.getDenominator() == 0){
        cout << "ERROR:  ATTEMPING TO DIVIDE BY ZERO." << endl;  // Return announcement when denominator is 0.
            exit(0);
    }
    if (!cin) {
        n = 0;
        d = 1;
    }
    return cin;
}

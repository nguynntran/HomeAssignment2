#include <iostream>
#include <cmath>

using namespace std;

/* Base class Figure */ 
class Figure{
public:
/* Virtual method (functions) for calculating and display perimeter, area of figure */
    virtual double Perimeter() = 0;
    virtual double Area() = 0;
    virtual void display(){
        cout << "Perimeter: " << Perimeter() << endl;
        cout << "Area: " << Area() << endl;
    }
};

/* Derived Class : Triangle */
class Triangle : public Figure{
private:
    double s1;
    double s2;
    double s3;
public:
/* Constructor */
    Triangle(){}
    Triangle(double s1, double s2, double s3){
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
    }
/* Getters */
    double getSideTriangle1(){
        return s1;
    }
    double getSideTriangle2(){
        return s2;
    }
    double getSideTriangle3(){
        return s3;
    }
/* Setters */
    void setSideTriangle1(double s1){
        this->s1 = s1;
    }
    void setSideTriangle2(double s2){
        this->s2 = s2;
    }
    void setSideTriangle3(double s3){
        this->s3 = s3;
    }
/* Method(Function) for calculating perimeter and area */
    double Perimeter(){
        return s1 + s2 + s3;
    }
    double Area(){
        double p = (s1 + s2 + s3) / 2.0;
        return sqrt(p * (p - s1) * (p - s2) * (p - s3));
    }

/* Derived Class : Rectangle */
};
class Rectangle : public Figure{
private: 
    double length;
    double width;
public:
/* Constructors */
    Rectangle(){}
    Rectangle(double length, double width){
        this->length = length;
        this->width = width;
    }
/* Getters */
    double getLength(){
        return length;
    }
    double getWidth(){
        return width;
    }
/* Setters */
    void setLength(double length){
        this->length = length;
    }
    void setWidth(double width){
        this->width = width;
    }
/* Method(Function) for calculating perimeter and area */
    double Perimeter(){
        return (length + width) * 2.0;
    }
    double Area(){
        return length * width;
    }
};
/* Derived Class : Circle */
class Circle : public Figure{
private:
    double rad;
    double dia;
public:
/* Constructors */
    Circle(){}
    Circle(double rad){
        this->rad  = rad;
    }
/* Getters */
    double getRadius(){
        return rad;
    }
    double getDiameter(){
        dia = rad * 2.0;
        return dia;
    }
/* Setter */
    void setRadius(double rad){
        this->rad = rad;
    }
/* Method(Function) for calculating perimeter and area */
    double Perimeter(){
        return 2.0 * 3.14 * rad;
    }
    double Area(){
        return 3.14 * pow(rad,2);
    }
};


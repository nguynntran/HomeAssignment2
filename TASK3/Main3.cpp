#include "Figure.cpp"

int main(){
    Triangle triangle(3.0, 4.0, 5.0);

    Rectangle rectangle(8.0, 6.0);

    Circle circle(5.0);

    cout << "Perimeter and Area of this triangle: " << endl;
    triangle.display();

    cout << "Perimeter and Area of this rectangle: " << endl;
    rectangle.display();
    
    cout << "Perimeter and Area of this circle: " << endl;
    circle.display();
    
}
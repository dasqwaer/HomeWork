#include <iostream> 
#include <string.h>
class Figure {    
    private:
        const double pi = 3.14159265358979323846; // значение Пи
    public:
        const double getPi () {return pi;};
        virtual double aria () = 0;
};
class Parallelogram: public Figure {
    private:
        int m_width;
        int m_height;
    public:
        Parallelogram (int a, int b) : m_width(a), m_height(b) {

        }   
        double aria () {
            return m_width*m_height;
        }
};
class Circle: public Figure {
    private:
        int m_radius;
    public:
        Circle (int r) : m_radius(r) {

        }
        double aria () {
            return getPi ()*m_radius*m_radius;
        }
};
class Rectangle: public Parallelogram {
    private:
        int m_width;
        int m_height;
    public:
        Rectangle (int a, int b) : m_width(a), m_height(b), Parallelogram(a,b) {

        }   
        double aria () {
            return m_width*m_height;
        }
};
class Square: public Parallelogram {
    private:
        int m_width;
        
    public:
        Square (int a) : m_width(a), Parallelogram(a,a) {

        }   
        double aria () {
            return m_width*m_width;
        }
};
class Rhombus: public Parallelogram {
    private:
        int m_width;
        int m_height;
    public:
        Rhombus (int a, int b) : m_width(a), m_height(b), Parallelogram(a,b) {

        }   
        double aria () {
            return m_width*m_height;
        }
};
int main()
{
    Parallelogram parallelogram(2,15);
    Circle circle (2);
    Rectangle rectangle (4,5);
    Square square (3);
    Rhombus rhombus (8,7);
    Figure *figure1 = &parallelogram;
    Figure *figure2 = &circle;
    Figure *figure3 = &rectangle;
    Figure *figure4 = &square;
    Figure *figure5 = &rhombus;
    std::cout << figure1->aria () << std::endl;
    std::cout << figure2->aria () << std::endl;
    std::cout << figure3->aria () << std::endl;
    std::cout << figure4->aria () << std::endl;
    std::cout << figure5->aria () << std::endl;
 
    return 0;
}

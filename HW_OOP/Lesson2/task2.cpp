#include <iostream>
#include <string.h>
using namespace std;
class Fruit {
    private:
        string m_name;
        string m_color;
    public:
        Fruit () {}
        void set_name(string name) {m_name = name;}
        void set_color(string color) {m_color = color;}
        string getName() const {return m_name ;}
        string getColor() const {return m_color; }
};
class Apple: public Fruit {
    private:

    public:
        Apple (string color) {
            set_name("apple");
            set_color (color);
        }
};
class Banana: public Fruit {
    private:

    public:
        Banana (string color = "yellow") {
            set_name ("banana");
            set_color(color) ;
        }
};

class GrannySmith: public Apple {
    private:

    public:
        GrannySmith ()
        : Apple ("green") {
            set_name ("Granny Smith apple");
        }
       
};

int main() {
    Apple a("red");
    Banana b;
    GrannySmith c;
    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
    return 0;
}

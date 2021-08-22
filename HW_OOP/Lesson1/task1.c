#include <iostream>
#include <cmath>
class Power
{
private:
    int m_number_one = 0;
    int m_number_two = 0;
    
public:
    void set (int number_one, int number_two) {
        m_number_one = number_one;
        m_number_two = number_two;
    }
    int calculate () {
       std::cout << "Power: " << pow(m_number_one,m_number_two) << '\n';
        return 0;
    }

};

int main()
{
    Power one;
    one.calculate();
    one.set(4, 5);
    one.calculate();
    Power two;
    two.set(2,18);
    two.calculate();
    
    return 0;
}

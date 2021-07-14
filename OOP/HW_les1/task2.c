#include <iostream>
#include <cmath>
#include <cstdint>
class RGBA
{
private:
    std::uint8_t m_red = 0;
    std::uint8_t m_green = 0;
    std::uint8_t m_blue = 0;
    std::uint8_t m_alpha = 255;
    
public:
    RGBA  (int red = 0 ,int green = 0 ,int blue = 0,int alpha = 255) {
        m_red = red;
        m_green = green;
        m_blue = blue;
        m_alpha = alpha;
    }    
    
    void print () {
        std::cout << "m_red: " << m_red << "\n";
        std::cout << "m_green: " << m_green << "\n";
        std::cout << "m_blue: " << m_blue << "\n";
        std::cout << "m_alpha: " << m_alpha << "\n";
    }

};


int main()
{
    RGBA tv;
    tv.print ();
  
    RGBA tc (97,98,99,100);
    tc.print ();

    
    return 0;
}


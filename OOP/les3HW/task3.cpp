	
#include <iostream>
 
class Fraction
{
private:
    int m_numerator;
    int m_denominator;
public:
    Fraction(int x=0, int y=1): m_numerator(x), m_denominator(y) {
        reduce ();
    }
    static int GCD (int a, int b) {
		return (b == 0) ? (a > 0 ? a : -a) : GCD (b, a % b);
	}
 
	void reduce() {
		int gcd = Fraction::GCD(m_numerator, m_denominator);
		m_numerator /= gcd;
		m_denominator /= gcd;
	}
    friend std::ostream& operator<< (std::ostream &out, const Fraction &fraction);
    friend Fraction operator*(const Fraction &f1, const Fraction &f2);
	friend Fraction operator*(const Fraction &f1, int value);
	friend Fraction operator*(int value, const Fraction &f1);
    friend Fraction operator+(const Fraction &f1, const Fraction &f2);
	friend Fraction operator+(const Fraction &f1, int value);
	friend Fraction operator+(int value, const Fraction &f1);
    friend Fraction operator-(const Fraction &f1, const Fraction &f2);
	friend Fraction operator-(const Fraction &f1, int value);
	friend Fraction operator-(int value, const Fraction &f1);
};
 
std::ostream& operator<< (std::ostream &out, const Fraction &fraction) {
    
    if (fraction.m_denominator == 0) {
            out << "Error enter. The denominator of the fraction must not be zero.";
        return out;
    }
    if (fraction.m_denominator == 1) {
        out << fraction.m_numerator;
        return out;
    }
    out << fraction.m_numerator << "/" << fraction.m_denominator;
 
    return out;
}
Fraction operator*(const Fraction &f1, const Fraction &f2) {
	return Fraction(f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator);
}
 
Fraction operator*(const Fraction &f1, int value) {
	return Fraction(f1.m_numerator * value, f1.m_denominator);
}
 
Fraction operator*(int value, const Fraction &f1) {
	return Fraction(f1.m_numerator * value, f1.m_denominator);
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++
Fraction operator+(const Fraction &f1, const Fraction &f2) {
    if (f1.m_denominator == f2.m_denominator) {
	    return Fraction(f1.m_numerator + f2.m_numerator, f1.m_denominator);
    }
     if ((f1.m_denominator>f2.m_denominator)&&((f1.m_denominator%f2.m_denominator))==0) {
	    return Fraction(f1.m_numerator + f2.m_numerator*(f1.m_denominator/f2.m_denominator), f1.m_denominator);
    }
     if ((f2.m_denominator>f1.m_denominator)&&((f2.m_denominator%f1.m_denominator))==0) {
	    return Fraction(f2.m_numerator + f1.m_numerator*(f2.m_denominator/f1.m_denominator), f2.m_denominator);
    }
	return Fraction(f1.m_numerator* f2.m_denominator+ f2.m_numerator* f1.m_denominator, f1.m_denominator * f2.m_denominator);
}
 
Fraction operator+(const Fraction &f1, int value) {
	return Fraction(f1.m_numerator + value*f1.m_denominator, f1.m_denominator);
}
 
Fraction operator+(int value, const Fraction &f1) {
	return Fraction(f1.m_numerator + value*f1.m_denominator, f1.m_denominator);
}
//----------------------------------------------------------------
Fraction operator-(const Fraction &f1, const Fraction &f2) {
    if (f1.m_denominator == f2.m_denominator) {
	    return Fraction(f1.m_numerator - f2.m_numerator, f1.m_denominator);
    }
    if ((f1.m_denominator>f2.m_denominator)&&((f1.m_denominator%f2.m_denominator))==0) {
	    return Fraction(f1.m_numerator - f2.m_numerator*(f1.m_denominator/f2.m_denominator), f1.m_denominator);
    }
    if ((f2.m_denominator>f1.m_denominator)&&((f2.m_denominator%f1.m_denominator))==0) {
        return Fraction(f1.m_numerator*(f2.m_denominator/f1.m_denominator)-f2.m_numerator, f2.m_denominator);
    }
	return Fraction(f1.m_numerator* f2.m_denominator - f2.m_numerator* f1.m_denominator, f1.m_denominator * f2.m_denominator);
}
 
Fraction operator-(const Fraction &f1, int value) {
	return Fraction(f1.m_numerator - value*f1.m_denominator, f1.m_denominator);
}
 
Fraction operator-(int value, const Fraction &f1) {
	return Fraction(value*f1.m_denominator-f1.m_numerator, f1.m_denominator);
}
int main() {
    Fraction f1(3,15);
    Fraction f2(4,6);
    std::cout << f1 << " " << f2 << std::endl;
    Fraction f3 = (3-f2+f1)*5;
    std::cout << f3 << std::endl;
    return 0;
}

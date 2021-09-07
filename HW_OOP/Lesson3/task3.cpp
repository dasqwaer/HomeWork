	
#include <iostream>
 
class Fraction
{
private:
    int m_numerator;
    int m_denominator;
public:
    Fraction(): m_numerator(0), m_denominator(1) {
    }
    Fraction(int x): m_numerator(x), m_denominator(1) {
    }
    Fraction(int x, int y): m_numerator(x), m_denominator(y) {
        chek ();
        reduce ();
    }
    static int GCD (int a, int b) {
		return (b == 0) ? (a > 0 ? a : -a) : GCD (b, a % b);
	}
    void chek () const {
        if (m_denominator == 0) {
            std::cout << "The denominator cannot be zero" << std::endl;
            exit(1);
        }
    }
	void reduce() {
		int gcd = Fraction::GCD(m_numerator, m_denominator);
		m_numerator /= gcd;
		m_denominator /= gcd;
        if (m_denominator < 0) {
            m_denominator *= -1;
            m_numerator *= -1;
        }
	}
    int toInt () const {
        return m_numerator/m_denominator;
    }
    double toReal () const {
        return double (m_numerator)/m_denominator;
    }
    Fraction getInverse () const {
        return Fraction (m_denominator, m_numerator);
    }
    friend std::ostream& operator<< (std::ostream &out, const Fraction &fraction);
    friend Fraction operator*(const Fraction &f1, const Fraction &f2);
	friend Fraction operator*(const Fraction &f1, int value);
	friend Fraction operator*(int value, const Fraction &f1);
    friend Fraction operator/(const Fraction &f1, const Fraction &f2);
	friend Fraction operator/(const Fraction &f1, int value);
	friend Fraction operator/(int value, const Fraction &f1);
    friend Fraction operator+(const Fraction &f1, const Fraction &f2);
	friend Fraction operator+(const Fraction &f1, int value);
	friend Fraction operator+(int value, const Fraction &f1);
    friend Fraction operator-(const Fraction &f1, const Fraction &f2);
	friend Fraction operator-(const Fraction &f1, int value);
	friend Fraction operator-(int value, const Fraction &f1);
    Fraction operator-() const;
    bool operator==(const Fraction &f1) const;
    bool operator!=(const Fraction &f1) const;
    bool operator<(const Fraction &f1) const;
    bool operator<=(const Fraction &f1) const;
    bool operator>(const Fraction &f1) const;
    bool operator>=(const Fraction &f1) const;
    Fraction operator+=(const Fraction &f1);
    Fraction operator-=(const Fraction &f1);
    Fraction operator*=(const Fraction &f1);
    Fraction operator/=(const Fraction &f1);
    Fraction operator++();
    Fraction operator++(int);
    Fraction operator--();
    Fraction operator--(int);
};
 
std::ostream& operator<< (std::ostream &out, const Fraction &fraction) {
    
    if (fraction.m_denominator == 0) {
            out << "Error enter. The denominator of the fraction must not be zero." << std::endl;
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
////////////////////////////////
Fraction operator/(const Fraction &f1, const Fraction &f2) {
	return Fraction(f1.m_numerator * f2.m_denominator, f1.m_denominator * f2.m_numerator);
}
 
Fraction operator/(const Fraction &f1, int value) {
	return Fraction(f1.m_numerator, f1.m_denominator * value);
}
 
Fraction operator/(int value, const Fraction &f1) {
	return Fraction(f1.m_denominator * value, f1.m_numerator);
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
//-()-()-()-()-()-()-()
Fraction Fraction::operator-() const {
    return Fraction (-m_numerator,m_denominator);
}
//== == == == == == == == == == == == 
bool Fraction::operator==(const Fraction &f1) const {
    return m_numerator==f1.m_numerator&&m_denominator==f1.m_denominator;
}
bool Fraction::operator!=(const Fraction &f1) const {
    return !(*this == f1);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<
bool Fraction::operator<(const Fraction &f1) const {
    return (toReal() < f1.toReal());
}
//<=<=<=<=<=<=<=<=<=<=
bool Fraction::operator<=(const Fraction &f1) const {
    return (*this<f1 || *this == f1);
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>
bool Fraction::operator>(const Fraction &f1) const {
    return (toReal() > f1.toReal());
}
//>=>=>=>=>=>=>=>=>=
bool Fraction::operator>=(const Fraction &f1) const {
    return (*this>f1 || *this == f1);
}
//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
Fraction Fraction::operator+=(const Fraction &f1) {
    *this = *this+f1;
    return *this;
}
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
Fraction Fraction::operator-=(const Fraction &f1) {
    *this = *this-f1;
    return *this;
}
//*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=
Fraction Fraction::operator*=(const Fraction &f1) {
    *this = *this*f1;
    return *this;
}
///=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/
Fraction Fraction::operator/=(const Fraction &f1) {
    *this = *this/f1;
    return *this;    
}
//++()++()++()++()++()++()++()++()
Fraction Fraction::operator++() {
    m_numerator += m_denominator;
    chek ();
    reduce ();
    return *this;
}
//++(int)++(int)++(int)++(int)++(int)
Fraction Fraction::operator++(int) {
    Fraction old_value (*this);
    ++*this;
    return old_value;
}
//--()--()--()--()--()--()--()--()--()
Fraction Fraction::operator--() {
    m_numerator -= m_denominator;
    chek ();
    reduce ();
    return *this;
}
//--(int)--(int)--(int)--(int)--(int)
Fraction Fraction::operator--(int) {
    Fraction old_value (*this);
    --*this;
    return old_value;
}
int main() {
    Fraction f1(41,42);
    Fraction f2(123,126);
    if (f1==f2) {
        std::cout << "Fraction equal" <<std::endl;
    }
    --f2;
    std::cout << f1 << " " << f2 << " " << f1/f2 << std::endl;
    Fraction f3 = (3-f2+f1)*5;
    
    std::cout << -f3 << std::endl;
    
    return 0;
}

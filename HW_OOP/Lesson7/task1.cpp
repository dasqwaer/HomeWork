#include <iostream>
#include <memory>
class Date {
    private:
        int m_day;  
        int m_month;
        int m_year;
    public:
        Date (int d=11,int m=9, int y=2001):m_day(d),m_month(m),m_year(y) {
            std::cout << "Item acquired\n";
        }
        ~Date () {
            std::cout << "Item destroyed\n";
        }
        void setDay(int day) { 
            m_day = day; 
        } 
        void setMonth(int month) { 
            m_month = month; 
        }
        void setYear(int year) { 
            m_year = year; 
        }
        int getDay() const { 
            return m_day; 
        }
        int getMonth() const { 
            return m_month; 
        } 
        int getYear() const { 
            return m_year; 
        }
        friend std::ostream& operator<<(std::ostream& out, Date& date) {
		out << date.m_day << "/" << date.m_month << "/" << date.m_year;
		return out;
	} 
};
int main () {
    std::unique_ptr <Date> today = std::make_unique<Date>(16,9,2021);
    std::unique_ptr <Date> date = std::make_unique<Date>();
    std::cout << today->getDay()<< "\n";
    std::cout << today->getMonth() << "\n";
    std::cout << today->getYear() << "\n";
    std::cout << "today:" << *today << '\n';
    date = std::move (today);
    if (today == nullptr)
        std::cout << "today null" << "\n";
    if (date == nullptr)
        std::cout << "date null" << '\n';
    else 
        std::cout << "date:" <<  *date << "\n";
       return 0;
}

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
Date& useLastDate (Date &date1, Date &date2)
{
	if (date1.getYear()==date2.getYear()) {
	    if (date1.getMonth()==date2.getMonth()) {
	        if (date1.getDay()==date2.getDay()) {
                std::cout << "the dates match";
                return date1;
            }
            else 
                return ((date1.getDay())>(date2.getDay()) ? date1 : date2);
        }
        else
            return ((date1.getMonth())>(date2.getMonth()) ? date1 : date2);
    } 
    else 
        return ((date1.getYear())>(date2.getYear()) ? date1 : date2);
}
void swat (std::unique_ptr<Date> date1, std::unique_ptr<Date> date2) {
    std::unique_ptr <Date> temp;
    temp = std::move(date1);
    date1 = std::move(date2);
        //std::cout << *date1;
    date2 = std::move(temp);
        //std::cout << *date2;
        //Не знаю я как передать адреса этих умных указателей, а целиком если передавать, 
        //то они уничтожаются на выходе этой функции исполняя своё прямое назначение
        //но времени больше нет, поэтому если можно при проверке не просто скажите, что 
        //задача не решена, это я знаю.Покажите пожалуйста какой то вариант её решения.
        //я понимаю всю ценность самостоятельного просветления, но тогда не три дня между
        //уроками нужно. Я удивляюсь почему на GeekBrains не принято показывать ответ, типо 
        //не решил ты ну и фиг с тобой, а мы пошли дальше
}
int main () {
    std::unique_ptr <Date> date1 = std::make_unique<Date>(16,9,2021);
    std::unique_ptr <Date> date2 = std::make_unique<Date>();
    

    std::cout << useLastDate (*date1, *date2) << "\n";
    std::cout << "date1: " << *date2 << "\n";
    swat (std::move(date1),std::move(date2));
    if (date1)
        std::cout << *date1 << "\n";   
       return 0;
}

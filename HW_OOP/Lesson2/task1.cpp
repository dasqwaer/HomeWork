#include <iostream>
#include <string.h>
using namespace std;
class Person {
    private:
        string m_name = {"no_name"};
        int m_age = 17;
        char m_gender = 'N' ;
        int m_weight = 42;
        static int m_counter_person;
    public:
        Person () {
            m_counter_person++;
        }
        void set_name(string name) {m_name = name;}
        void show_name() const {cout << "Name person is: "<< m_name << endl; }
        void set_age(int age) {m_age=age;}
        void show_age() const {cout <<"Age person "<< m_name <<" is: "<< m_age << endl; }
        void set_gender(int gender) {m_gender=gender;}
        void show_gender() const {cout << "Gender person "<< m_name <<" is: "<< m_gender << endl; }
        void set_weight(int weight) {m_weight=weight;}
        void show_weight() const {cout << "Weight person "<< m_name <<" is: "<<  m_weight << endl; }
        void show_counter() const {
            cout << "Number of person: "<< m_counter_person << endl;
        }
        void new_person () {
            cin >> m_name >> m_age >> m_gender >> m_weight;
        }
        void show_person () const {
            cout << "Person " << m_counter_person << endl;
            cout << "name: " << m_name << endl;
            cout << "age: " << m_age << endl;
            cout << "weight: " << m_weight << endl;
            cout << "gender: " << m_gender << endl;
        }
        ~Person () {
            m_counter_person--;
            cout << "~Person " << m_counter_person << endl;
        }
};

int Person::m_counter_person = 0;
class Student: public Person {
    private:
        static int m_counter_st;
        int m_year_of_stady = 0;
        public:
            Student () {
                m_counter_st++;
            }
            void set_year_of_stady(int year_of_stady) {
                m_year_of_stady=year_of_stady;
            }
            void show_year_of_stady () const {
                cout << m_year_of_stady << endl;
            }
            void show_student () const {
                cout << "Student " << m_counter_st << endl;
                show_person ();
                cout << "year of stady: " << m_year_of_stady << endl;
            }
            void add_yearOfStady (int year = 1) {
                m_year_of_stady = year;
            }
            ~Student () {
                m_counter_st--;
                cout << "~Student " << m_counter_st << endl;
            }
};
int Student::m_counter_st = 0;
int main() {
    Person *p_person;
    Person person1;
    Student student;
    person1.new_person ();
    person1.show_person ();
    p_person = &person1;
    p_person->set_age(5);
    p_person = &student;
    p_person->set_age(10);
    person1.show_age();
    student.show_age();
    student.set_name("Poll");
    person1.show_name();
    student.show_counter();
    student.add_yearOfStady (3);
    Student student1;
    student.show_student ();
    student1.show_student ();
    cout << "\n";
return 0;
}

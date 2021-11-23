#include <iostream>
#include <string>
#include <optional>
#include <tuple>
#include <vector>
#include <fstream>
/*Создайте структуру Person с 3 полями: фамилия, имя, отчество. Поле отчество должно быть
опционального типа, т.к. не у всех людей есть отчество. Перегрузите оператор вывода данных
для этой структуры. Также перегрузите операторы < и == (используйте tie).*/

//______________//\\Task_1_Person//\\_________________//
struct Person {

        std::string m_firstName;
        std::optional <std::string> m_patronymic;
        std::string m_lastName;
    friend std::ostream& operator<<(std::ostream& stock, const Person& person);
    friend bool operator<(const Person& person1, const Person& person2);
    friend bool operator==(const Person& person1, const Person& person2);
};

std::ostream& operator<<(std::ostream& stock, const Person& person) {
    stock << person.m_firstName << " " << person.m_patronymic.value_or("") << " " << person.m_lastName;
    return stock;
}
bool operator<(const Person& person1, const Person& person2) {
    return tie(person1.m_lastName, person1.m_firstName, person1.m_patronymic) < tie(person2.m_lastName, person2.m_firstName, person2.m_patronymic);
}
bool operator==(const Person& person1, const Person& person2) {
    return tie(person1.m_lastName, person1.m_firstName, person1.m_patronymic) == tie(person2.m_lastName, person2.m_firstName, person2.m_patronymic);
}
/*Создайте структуру PhoneNumber с 4 полями:
· код страны (целое число)
· код города (целое число)
· номер (строка)
· добавочный номер (целое число, опциональный тип)
Для этой структуры перегрузите оператор вывода. Необходимо, чтобы номер телефона
выводился в формате: +7(911)1234567 12, где 7 – это номер страны, 911 – номер города,
1234567 – номер, 12 – добавочный номер. Если добавочного номера нет, то его выводить не
надо. Также перегрузите операторы < и == (используйте tie)*/

//______________//\\Task_2_PhoneNumber//\\_________________//
struct PhoneNumber {
  
        int m_country;
        int m_city;
        std::string m_number;
        std::optional<int> m_add_number;

    friend std::ostream& operator<<(std::ostream& stock, const PhoneNumber& pho_number);
    friend bool operator<(const PhoneNumber& pho_number1, const PhoneNumber& pho_number2);
    friend bool operator==(const PhoneNumber& pho_number1, const PhoneNumber& pho_number2);
};

std::ostream& operator<<(std::ostream& stock, const PhoneNumber& pho_number) {
    stock << "+" << pho_number.m_country << "(" << pho_number.m_city << ")" << pho_number.m_number << " ";
    if (pho_number.m_add_number) {
                stock << pho_number.m_add_number.value();
            }
            else {
                stock << "";
            }
    
    return stock;
}
bool operator<(const PhoneNumber& pho_number1, const PhoneNumber& pho_number2) {
    return tie(pho_number1.m_country, pho_number1.m_city, pho_number1.m_number, pho_number1.m_add_number) < tie(pho_number2.m_country, pho_number2.m_city, pho_number2.m_number, pho_number2.m_add_number);
}
bool operator==(const PhoneNumber& pho_number1, const PhoneNumber& pho_number2) {
    return tie(pho_number1.m_country, pho_number1.m_city, pho_number1.m_number, pho_number1.m_add_number) == tie(pho_number2.m_country, pho_number2.m_city, pho_number2.m_number, pho_number2.m_add_number);
}
/*Создайте класс PhoneBook, который будет в контейнере хранить пары: Человек – Номер
телефона. Конструктор этого класса должен принимать параметр типа ifstream – поток данных,
полученных из файла. В теле конструктора происходит считывание данных из файла и заполнение контейнера. Класс PhoneBook должен содержать перегруженный оператор
вывода, для вывода всех данных из контейнера в консоль.
В классе PhoneBook реализуйте метод SortByName, который должен сортировать элементы
контейнера по фамилии людей в алфавитном порядке. Если фамилии будут одинаковыми, то
сортировка должна выполняться по именам, если имена будут одинаковы, то сортировка
производится по отчествам. Используйте алгоритмическую функцию sort.
Реализуйте метод SortByPhone, который должен сортировать элементы контейнера по
номерам телефонов. Используйте алгоритмическую функцию sort.
Реализуйте метод GetPhoneNumber, который принимает фамилию человека, а возвращает
кортеж из строки и PhoneNumber. Строка должна быть пустой, если найден ровно один
человек с заданном фамилией в списке. Если не найден ни один человек с заданной
фамилией, то в строке должна быть запись «not found», если было найдено больше одного
человека, то в строке должно быть «found more than 1».
Реализуйте метод ChangePhoneNumber, который принимает человека и новый номер
телефона и, если находит заданного человека в контейнере, то меняет его номер телефона на
новый, иначе ничего не делает.*/
//                    класс PhoneBook
class PhoneBook {
    private:
        std::vector<std::pair<Person, PhoneNumber>> data;
    public:
        PhoneBook(std::ifstream& data_from_file)     {
            std::string lineFromFile;
            std::string lastName, firstName, patronymic, number, str_add_number;
            int country, city, add_number;
            while (data_from_file) {
                data_from_file >> lastName;
                data_from_file >> firstName;
                data_from_file >> patronymic;
                data_from_file >> country;
                data_from_file >> city;
                data_from_file >> number;
                data_from_file >> str_add_number;
                if (patronymic == "-") {
                    patronymic = "";
                }
                if (str_add_number == "-") {
                    add_number = 0;
                }
                Person person{ lastName, firstName, patronymic };
                PhoneNumber pho_number{ country, city, number, add_number };
                data.push_back(std::make_pair(person, pho_number));
            }
        data_from_file.close();
    }
    friend std::ostream& operator<<(std::ostream& stock, const PhoneBook& pho_book);
};

std::ostream& operator<<(std::ostream& stock, const PhoneBook& pho_book) {
    for (const auto& [person, pho_number] : pho_book.data)
        stock << person << " " << pho_number << std::endl;
    return stock;
}

int main()
{
    std::ifstream file("PhoneBook.xt");
    PhoneBook book(file);
    Person Sveta {"Masha","Zlatoust"};
    Person Fedor{"Vasya","Tagizbaevich", "Kosolapov"};
    std::cout << Fedor << "\n" << Sveta << "\n";
    PhoneNumber SvetaPhon {1, 292, "3333"};
    PhoneNumber PhoneFedy {7, 495, "5556",34};
    std::cout << PhoneFedy << "\n" << SvetaPhon << "\n";
    return 0;
}

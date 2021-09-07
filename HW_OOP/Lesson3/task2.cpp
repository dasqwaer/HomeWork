#include <iostream> 
#include <string.h>
using namespace std;
class Car {
    private:
       
    public:
        Car (string m_company, string m_model) {
            cout << "Class Car" << "\n" << "company: " << m_company << "\n" << "model: " << m_model << endl;  
        }
};
class PassengerCar: virtual public Car {
    private:
    public:
        PassengerCar (string m_pcompany, string m_pmodel, string m_company, string m_model): Car(m_company, m_model) {
            cout << "Class PassengerCar" << "\n" << "company: " << m_pcompany << "\n" << "model: " << m_pmodel << endl;  
        }
};
class Bus: virtual public Car {
    private:
    public:
        Bus (string m_bcompany, string m_bmodel, string m_company, string m_model): Car(m_company, m_model) {
            cout << "Class Bus" << "\n" << "company: " << m_bcompany << "\n" << "model: " << m_bmodel << endl;  
        }
};
class Minivan: public PassengerCar, public Bus {
    private:
    public:
        Minivan (string m_pcompany, string m_pmodel, string m_bcompany, string m_bmodel, string m_company, string m_model):
        PassengerCar (m_pcompany, m_pmodel, m_company, m_model), Bus (m_bcompany, m_bmodel, m_company, m_model), Car(m_company, m_model) {
           cout << "Class Minivan" << "\n" << "company: " << m_bcompany << "\n" << "model: " << m_bmodel << endl;  
        }
};
int main () {
   
    Car car ("noCompany", "noModel");
    cout << "________________________" << '\n';
    
    Bus bus ("companyBus", "modelBus", "noCompany_bus","noModel_bus");
    cout << "________________________" << '\n';
    
    PassengerCar passengerCar ("companyPassengerCar", "modelPassengerCar", "noCompany_Pcar","noModel_Pcar");
    cout << "________________________" << '\n';
    
    Minivan minivan ("wolkswagen", "caravan", "pejo", "7", "Mini", "Cooper");
    return 0;
}

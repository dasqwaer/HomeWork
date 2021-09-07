#include <iostream>
#include <vector>
#include <set>
#include <array>
using namespace std;

set<int> convertToSet(vector<int> v)
{
    // Declaring the  set
    set<int> s;
    // Traverse the Vector
    for (int x : v) {
        // Insert each element
        // into the Set
        s.insert(x);
    }
  
    // Return the resultant Set
    return s;
}

int** returnRapidNumber (vector<int> &a) {
    set<int> relese = convertToSet(a);
    
    int **arr_resul = new int* [100]; // две строки в массиве
    for (int count = 0; count < 100; count++)
        arr_resul[count] = new int [2]; // и пять столбцов

    // int arr_resul[][2] = {};
    int i = 0;
    for (auto const &number : relese) {
        int n = 0;  
        for (auto const &number_in_vector : a){
            if (number == number_in_vector){
                n++;
            }
        }
        cout << number;
        cout <<"="<< n <<"\n";

        
        arr_resul[i][0] = number;
        arr_resul[i][1] = n;
        i++;
    }
    return arr_resul;


}
int main()
{
    vector<int> pink = {1,1,1,4,5,5,6,7,1,2,3,4,5,6};
    int** result = returnRapidNumber (pink);
    //cout << "len="<< sizeof(result[0]) / sizeof(result[0][0]) <<"\n";
    for (int p = 0; p < sizeof(result)/sizeof(result[0]); p++)
    {
        cout <<result[p][0]<<"=";
        cout <<result[p][1]<<"\n";
    }
    
return 0;
}
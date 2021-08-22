#include <cmath>
#include <cstdint>
#include <iostream>
#define capacity_stack 10
/*Подскажите как можно сделать это константной  
переменной класса. Пробовал вот так
private:
    const int capacity_stack = 10;
    int array [capacity_stack] = {0};
компилятор выдаёт ошибку:
<source>:16:19: error: invalid use of non-static data member 'stack::capacity_stack'
   16 |         int array[capacity_stack] = {0};
и в чём смысл этой ошибки
*/
class Stack {
    private:
        int array[capacity_stack] = {0};
        int length_stack = 0;
    public:
        void reset() {
            //std::cout << "work_reset";
            for (int i = length_stack; i >= 0; i--) {
                array[i] = {0};
                //std::cout << "\n" << "element" << i << "reset " << array[i];
            }
            //std::cout << "\n" << "length_reset";
            length_stack = 0;
            //std::cout << " "<< length_stack;
        }
        bool push(int number) {
            if (length_stack < capacity_stack) {
                //std::cout << "array[" << length_stack << "] = " << number << " /";
                array[length_stack] = number;
                length_stack++;
                //std::cout << "Free space in the stack -" << " " << capacity_stack-length_stack << "\n";
            return true;
            } 

            else {
                std::cout << "Stack is full!!"<< "\n";
                return false;
            }
        }
        int pop() {
            if (length_stack == 0) {
                std::cout << "\n" << "No pop!/Stack is empty!!";
                return 0;
            } 
            else {
                length_stack--;
                int number = 0;
                number = array[length_stack];
                //std::cout << "Delete " << array[length_stack];
                array[length_stack] = 0;
                //std::cout << " member array"<< " it's value " << number;
                return number;
            } 
        }
        void print() {
            std::cout << "\n( ";
            for (const auto &number : array) {
                if (number!=0){
                    std::cout << number << " ";
                }
            }
            std::cout << ")\n";
        }
};

int main() {
    Stack stack;
    stack.reset();
    stack.print();
    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();
    stack.pop();
    stack.print();
    stack.pop();
    stack.pop();
    stack.print();
    return 0;
}


#include <iostream>
#include <cmath>
#include <cstdint>
class Stack
{
private:
    int array[9] = {0};
    int length_stack = 0;

    
public:
    void reset () {
      for (int i = length_stack; i>=0; i--){
      array[i] = {0};
      }
      length_stack = 0;  
    } 
    bool push (int number) {
        
        if (length_stack < 10) {
        array[length_stack] = number;
        //std::cout << "Stack ++!!" << "\n" << length_stack << "\n";
        length_stack++;
        return true;
        }

        else {
        std::cout << "Stack is full!!" << "\nlength_stack is " << length_stack << "\n";
        return false;
        }       
    }
    int pop () {
        if (length_stack == 0) {
            std::cout << "Stack is empty!!";
            return 0;
        }
        else {
            //std::cout << "Stack is empty!!" << "\n" << length_stack << "\n";
            length_stack--;
            int number = array[length_stack];
            array[length_stack] = 0;
            return number;
        }
    }
    void print () {
        int i = 0;
        std::cout << "( ";
        while (array[i] != 0) {
        std::cout  << array[i] << " ";
        i++;
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


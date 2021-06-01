#include <stdio.h>
//#include <math.h>
//#include <stdlib.h>
#include <stdlib.h>

#define SZ 10

typedef struct {
    int pr;
    int dat;
} Node;
Node* arr[SZ];
int head; //индекс головы очереди
int tail;//индекс хвоста очереди
int items;//текущее количество элементов в очереди
/* Функция нид котороя иницилизирует массив нулями и задаёт начальные значения
индексу головы и конца очереди*/
void init () {
    for (int i = 0; i < SZ; ++i) {
        arr[i] = NULL;
    }
    head = 0;
    tail = 0;
    items = 0;
}
int pr_max =0;
/*Функция  принимает значение и приоритет с которым его нужно положить в очередь*/
void ins (int pr, int dat) {
    Node *node = (Node*) malloc(sizeof(Node)); //Создаём объект node структуры Node
    node->dat = dat; // обращаемся к полю dat объекта node
    node->pr = pr; // обращаемся к полю pr объекта node
    if (items == 0) {
        arr [tail++] = node;
        items++;
    } else if (items == SZ) {
        printf ("%s \n", "Queue is full");
        return;
    } else {
        
        arr[items] = node;
        if (arr[items]->pr > arr[items-1]->pr){
            pr_max = arr[items]->pr;
        }
        items++;
        tail++;
        
    }
}

/* Функция удаления из очереди */
Node* rem() {
   int c =0; 
    Node *tmp = NULL;
    if (items == 0) {//если очередь пуста, возвращаем пустоту (NULL)
        return NULL;
    } else  {
       for (int j = 0; j < pr_max; j++) {
            for (int i = 0; i < items ; i++) {
               if (j == arr[i]->pr) {
                    c = i;
                    tmp = arr[i]; // положим элемент во временный контейнер tmp
                    arr[i] = NULL; // очистим ячейку массива
                    items--;                
                    j=pr_max+1;
                    for (int c = i; c<= items%SZ; c++) {// цикл перемещает все элементы влево после удаления элемента
                        if (i<SZ-1) {
                        arr[i] = arr[i+1];
                        i++;
                        }
                    }
                }
                else
                { 
                continue;                
                }
                
            }
            
       }   
    
    }
    return tmp; //вернём временную переменную tmp    
}
/*Функция вывода очереди*/
void printQueue () {
    printf ("[ ");
    for (int i = 0; i < SZ; ++i) {
        if (arr[i] == NULL)
            printf("[*, *]");
        else
            printf("[%d, %i] ", arr[i]->pr, arr[i]->dat);
    }
    printf(" ]\n");
}
//---------------------------------------------------
//converting from decimal to binary using a stack
#define T char
#define SIZE 1000
#define true 1 == 1
#define false 1 != 1
int cursor = -1;
/* Функция записи в массив Stack */
T Stack [SIZE];
typedef int boolean;
boolean push (T data) {
    if (cursor < SIZE) {
        Stack[++cursor] = data;
        return true; //если значение записано успешно
    } else { //если нет места выведем сообщение и вернём ложь
        printf ("%s \n", "Stack overflow");
        return false;
    }
     
}
/* Функция удаления из массива Stack */
T pop () {
    if (cursor != -1) {
        return Stack [cursor--];
    } else {
        printf ("%s \n", "Stack is empty");
        return -1; //Обязательно значение которого не может быть в стэке
    }
}
int call_num () {
    int num;
    printf ("enter a number: ");
     scanf ("%i", &num);
    while (num != 0){
    if (num > 0){
        printf ("\nbinary: \n");
        return num;
    }
    else 
        num = 0;
        printf ("enter a positive number: ");
    }
    return 0;
}
char convertingDecToBe (int x) {
    if (x==0){
        return  0;
    }
    else {
        char buf [2];
        sprintf (buf, "%i", x%2);  
      //  printf (buf, 6); //Здесь вопрос после запятой, что нужно указывать? Почему работает с любым числом? 
        push (buf[0]);
        convertingDecToBe (x/2);
        return 0;
    }
}
int main (int argc, char* argv[]) {


 init ();
  
    ins(12, 11);
    ins(5, 22);
    ins(6, 33);
    ins(2, 44);
    //ins(3,48);
    ins(6, 11);
    ins(9, 22);
    ins(10, 33);
    ins(7, 44);
    ins(12,48);
    ins(1, 11);
    printQueue ();


   for (int i = 0; i < 8; ++i) {
       Node* n = rem ();
       printf ("pr=%i, dat=%i \n", n->pr, n->dat);
    }
    printQueue ();


//----------------------------------------    
    convertingDecToBe (call_num()); 
    
    while (cursor != -1) {
        printf ("%c ", pop());
    }
    
    return (0);
} 

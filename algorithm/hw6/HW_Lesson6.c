/* для реализации алгоритма TPK*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/*Функция инициализирует передавемый ей указатель на массив*/
int** initArray (int** array, const int row, const int col){
    array = (int**) calloc (sizeof(int*),row);//Выделим под него
    //память
    for (int i =0; i< row; ++i) {
        *(array+i) = (int*) calloc (sizeof (int), col);//В каждом
        //элементе выделим память под вторую размерность массива
    }
    return array;
}
/*Функция инициализирующая двумерный массив от пользователя*/
void fillArray(int** array, const int row, const int col) {
   printf ("INITIAL ARRAY\n Enter numbers\n");
    for (int i = 0; i< row; ++i) {
        for (int j = 0; j<col; ++j)   {  
           scanf ("%i", &array[i][j]);
        }
    }
}
/*Функция вывода массива*/
void printArray (int** array, const int row, const int col) {
      for (int i = 0; i< row; ++i) {
        for (int j = 0; j<col; ++j) {
            printf ("[%i]",*((*(array+i))+j));
        }
        printf ("\n");
    }
    //printf ("%i\n",array[1][0]);
}
/*Функция для перестановки значений местами*/
void swap (int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
/*Пузырьковая сортировка*/
void bubbleDiSort (int** arr, int row, int col) {
   
    for (int g = 0; g< row; ++g) {
        for (int m = 0; m < col; ++m) {
            for (int i =0; i< row; ++i) {
                for (int j=0; j< col; ++j) {
                    if (((i+1) ==row)&&((j+1)==col)){
                        continue;
                    }
                    else {
                        if (j==col-1) {
                            swap (&arr[i][j], &arr[i+1][0]);
                        }
                        else {
                            if (arr[i][j] > arr [i][j+1])    {
                                swap (&arr[i][j], &arr[i][j+1]);
                            }
                        }
                    }    
                }
            }
        }
   }
   printf ("Array sorted:\n");
}

//-----------------------------------------------------
// f (x) = sqrt (| x |) + 5 * x ** 3

void funcTPK (int* array, int len) {
    printf ("Work algorithm TPK:\n");
    for (int i=len; i>=0; i--) {
        int y = sqrt(fabs((array[i]))) + 5.0 * pow((array[i]), 3.0) ;
            if (y > 400.0) {
                printf ("%i TOO LARGE\n", i);
            }
            else {
                printf ("%i %i\n", i, y);
            }
    }
}

int Len () {
    int len;
    printf ("INITIAL ARRAY\n Enter lengch array\n");
    scanf ("%i",&len);
    return len;
}

/*Функция инициализирующая отдномерный массив от пользователя*/
void fillOneArray(int* array, int len) {
    for (int i = 0; i< len; ++i) {
        printf ("Continue filling the array. Enter number\n");
        scanf ("%i", &array[i]);
    }
}  

/*Функция инициализирует передавемый ей указатель на массив*/
int* initOneArray (int* array, int len) {
    array = (int*) calloc (sizeof(int*),len);//Выделим под него
    //память
    return array;
}
void printOneArray (int* array, int len) {
    printf ("You initial array:\n");
    for (int i=0; i<=len; i++) {
        printf ("%i ", array [i]);
    }
    printf ("\n");
}

int main (int argc, char* argv[])

{
    int len = Len ();
    int* A = initOneArray (A, len);
    fillOneArray (A , len);
    printOneArray (A, len);  

    funcTPK (A, len);

    int row = 3;
    int col = 3;
    int** arr = initArray(arr, row, col);
    //int arr[3][3] = {{1,9,2},{5,7,6},{7,3,8}}; //Как передать такой массив на вход fillArray?
    fillArray (arr, row, col);
    printArray (arr, row, col);
    printf ("\n");
    bubbleDiSort (arr, row, col);
    printArray (arr, row, col);

    return (0);
} 

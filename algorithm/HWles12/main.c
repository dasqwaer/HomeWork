#include <stdio.h>
#include <stdlib.h>
FILE *file;
#define true 1 == 1
#define false 1 != 1
typedef int boolean;
char A[12255];
int randomFile () {
    for (int i=0; i< 10050; i++) {
        *(A+i)=rand()%100;
       // printf ("%i, ", A[i]);
    }
        printf ("\n");
        
   file = fopen ("myfile.txt","w");
   for (int n=0 ; n<10000 ; n++)
   {
     fprintf (file, "%d ", rand()%100);
   }
   fclose (file);
 
   return 0;
}
typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} BinTreeIntNode;
int a = 0;
int left = 0;
int right = 0;
BinTreeIntNode* balancedTree(int n) {
    BinTreeIntNode *newNode;
    int x;
    int nL;
    int nR;
    
    if (n == 0) {
        return NULL;
    } else {
        fscanf(file, "%d", &x);
        nL = n / 2;
        nR = n - nL - 1;
        newNode = (BinTreeIntNode*) malloc(sizeof(BinTreeIntNode));
        newNode->key = A [a++];
        newNode->left = balancedTree(nL);
        newNode->right = balancedTree(nR);
        
    }
    return newNode;
}
int level (int element, int k) {
     k++;
    if (element < 1) {
        return k;
    }
    else {
       
        return level (element/2, k);
    }
}
void printBinTree(BinTreeIntNode *root) {
    if (root) {
        if (root->left || root->right) {
            if (root->left)
                printBinTree(root->left);
                left++;
            if (root->right)
                printBinTree(root->right);
                right++;
        }
    }

}

void balanceTest() {
    BinTreeIntNode *tree = NULL;
    const int counta = 8191;
    tree = balancedTree(counta);
    printBinTree(tree);
    file = fopen("myfile.txt", "r");
    if (file == NULL) {
        printf("%s \n", "Cannot open file");
        return;
    }
    const int count = 150;
    //tree = balancedTree(count);
    fclose(file);
    //printBinTree(tree);
}


int main () {
    randomFile ();
    balanceTest ();
 int x = 0;
    (left > right)?(x=(level (left,-2)-level(right,-2))):(x=(level(right,-2)-level(left,-2)));
    (x<2)?(printf("The tree is ballanced")):(printf("The tree is not ballanced"));
    printf ("\nThe level left tree is %i\n", level(left,-2));
    printf ("\nThe level right tree is %i\n", level(right,-2));
    
    return 0;
}

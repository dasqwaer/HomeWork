#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
 
int K=-1;
char *title[]={"6","7","8","9","10","J","Q","K","A"};
 
struct Card
{
    unsigned int value:4;
    unsigned int mast:2;
    unsigned int ves:4;
};
#define size 36
 
class Coloda
{    
    Card card[size];    
public:
    Coloda()
    {
        for (int i=0;i<size;i++)
        {
            card[i].value=i%9;
            card[i].mast=i%4;
            if (card[i].value>=0 && card[i].value<=4) card[i].ves=card[i].value+6; 
            else if (card[i].value==8)
                card[i].ves=11;
            else
            {
                card[i].ves=card[i].value-3;
            }            
        }
    }    
    void PaintCard(bool comp,int value=0, int mast=0)
    {
        if (comp)
        {
        cout<<" ----- \n";
        cout<<"| *** |\n";
        cout<<"| *** |\n";
        cout<<"| *** |\n";
        cout<<" ----- \n";
        }else
        {
        cout<<" ----- \n";
        cout<<"|"<<char(card[value].mast+3)<<"    |\n";
        cout<<"|  "<<title[card[value].value]<<"  |\n";
        cout<<"|     |\n";
        cout<<" ----- \n";
        }
    }
 
    bool GetCard(int &Player,int &Comp,char ans='y')
    {        
        
                K++;
                Player+=card[K].ves;
                PaintCard(false,K,card[K].mast);
    
                K++;
                Comp+=card[K].ves;
                PaintCard(true,K,card[K].mast);
            
        
        Proverka(Player,Comp,false);
    }
 
    void Shuffle()
    {
        for (int i=0;i<size;i++)
        {
            int k=rand()%35;
            int tmp=card[k].value,tmp1=card[k].mast,tmp2=card[k].ves;
            card[k].value=card[i].value;
            card[k].mast=card[i].mast;
            card[k].ves=card[i].ves;
 
            card[i].value=tmp;
            card[i].mast=tmp1;
            card[i].ves=tmp2;            
        }
    }
    void Proverka(int Player, int Comp, bool end)
    {        
        if (end)
        {
            if (Player<21 && Player>Comp)
            {
                cout<<"Player wins! With "<<Player<<"\n";
                cout<<"Comp louse! With "<<Comp<<"\n";
            }
            else if (Player>21) 
            {
                cout<<"Player louse!\n";
                cout<<"Comp have "<<Comp<<"\n";
            }
 
            if (Comp<21 && Comp>Player)
            {
                cout<<"Comp wins! With "<<Comp<<"\n";
                cout<<"Player louse! With "<<Player<<"\n";
            }
            else if (Comp>21) 
            {
                cout<<"Comp louse!\n";    
                cout<<"Player have "<<Player<<"\n";
            }
        } else
            cout<<"Player have: "<<Player<<"\n";
    }    
 
    void Play(int& Player, int& Comp)
    {        
        char ans;
        cout<<"Press 'q' to exit\n";
        do
        {    
            cout<<"Continue play and get one card?(y/n)\n";
            cin>>ans;
            if (ans=='y')
                GetCard(Player,Comp);                
            else if (ans=='n')
            {                                
                Proverka(Player,Comp,true);                    
                break;
            }
        }while (ans!='q');    
    }
    
 
    void Print(int i)
    {        
cout<<title[card[i].value]<<" "<<char(card[i].mast+3)<<" ";//<<card[i].ves<<"\n";            
    }
    void PrintAll()
    {        
        for (int i=0;i<size;i++)
cout<<title[card[i].value]<<" "<<char(card[i].mast+3)<<" "<<card[i].ves<<"\n";            
    }
};
 
int main()
{    
    Coloda k1;
    srand(time(0));
    k1.Shuffle();
 
    int Player=0,Comp=0;        
        
                for (int i=0;i<2;i++)
                  k1.GetCard(Player,Comp);
            
 
        k1.Play(Player,Comp);
 
 
}



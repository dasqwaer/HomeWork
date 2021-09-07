#include <iostream>
#include <string.h>
class Card {
    private:
        enum class Suit { 
                CLUBS,//Крести
                DIAMONDS,//Буби 
                HEARTS,//Черви 
                SPADES //Пики
        };
        enum class Rank {
                ACE = 1,//Туз
                TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,//Карты числа
                JACK, QUEEN, KING//Валет, дама, король
        };
        bool position;
    public:
        Card () {

        }
        void Flip () {
            position = !(position);
        }
        //Не пойму как нужно сделать функция GetValue должна же возвращать какое-то конкретное значение из 
        //перечислениия Rank,а для этого какая то другая функция должна создавать объект типа Rank и присваивать его в какое то поле?
        int GetValue () const {
            Rank rank = Rank::ACE;
            return static_cast<int>(rank);
        }
        ~Card () {

        }
};
int main () {
    Card card;
    std::cout << card.GetValue();
    return 0;
}

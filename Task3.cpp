#include <iostream>
#include <vector>
class Card {
    
    public:
          enum class Suit {
            CLUBS,
            DIAMONDS,
            HEARTS,
            SPADES,
        };
        enum class Rank {
            //ZERO = 0,
            ACE = 1,
            TWO = 2, THREE = 3, FOUR = 4, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
            JACK =10, QUEEN =10, KING =10,
        };
        private:
      
        Rank m_Rank;
        Suit m_Suit;
        bool m_position;
        public:
        Card () {

        }
        Card (Rank r = Rank::ACE, Suit  s = Suit::SPADES, bool if_pos_fase_up = true) : m_Rank(r), m_Suit(s), m_position(if_pos_fase_up) {

        }
        void Flip () {
            m_position = !(m_position);
        }
        int GetValue () const {
            // Rank rank = Rank::KING;
            int value = 0;
            if (m_position) {
                value = static_cast<int>(m_Rank);
            }
            return value;
        }
        Rank GetRank () const {
           // Rank rank = Rank::KING;
            // Rank value = Rank::ZERO;
            Rank value;
            if (m_position) {
                value = m_Rank;
            }
            return value;
        }
        ~Card () {

        }
};
class Hand {
    private:
        std::vector<Card*> m_Card;
        //int  m_Sum = 0;
    public:
        Hand () {

        }
        void Add (Card* new_Card) {
            m_Card.push_back(new_Card);
        }
        void Clear () {
            m_Card.~vector();
        }
        int GetTotalValue () const {
            if (m_Card.empty()){
                return 0;
            }
            else {
                int Sum = 0;
                bool Hand_is_Ace = false;
                std::vector<Card*>::const_iterator it;
                for (it = m_Card.begin();it != m_Card.end();it++) {
                        if((*it)->GetRank () == Card::Rank::ACE && Sum <=11)
                        {
                            Sum +=10;        
                        }        
                    Sum += (*it)->GetValue();
                }
              
                
                return Sum;
            }
        }
};

int main() {
    Hand hand;
    
    Card card(Card::Rank::TWO, Card::Suit::CLUBS, true);
    hand.Add(&card);
    
    Card card2(Card::Rank::THREE, Card::Suit::CLUBS, true);
    hand.Add(&card2);
    
    Card card3(Card::Rank::ACE, Card::Suit::CLUBS, true);
    hand.Add(&card3);

    std::cout <<hand.GetTotalValue()  << " ";
    
return 0;
}
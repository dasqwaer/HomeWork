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
            JACK, QUEEN, KING,
        };
        protected:

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
                if (value > 10) {
                    value = 10;
                }
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
    friend std::ostream& operator<< (std::ostream& potoc, const Suit& suit);
    friend std::ostream& operator<< (std::ostream& potoc, const Rank& rank);
    friend std::ostream& operator<< (std::ostream& potoc, const Card& card);
};
std::ostream& operator << (std::ostream& potoc, const Card::Suit& suit) {
    switch (suit) {
        case Card::Suit::CLUBS: 
            std::cout << "CLUBS" << '\n';
            break;
        case Card::Suit::DIAMONDS: 
            std::cout << "DIAMONDS" << '\n'; 
            break; 
        case Card::Suit::HEARTS:
            std::cout << "HEARTS" << '\n';
            break;
        case Card::Suit::SPADES:
            std::cout << "SPADES" << '\n';
            break;
        default:
            std::cout << "SUIT" << '\n';
            break;
    }
    return potoc;
}
std::ostream& operator << (std::ostream& potoc, const Card::Rank& rank) {
    switch (rank) {
        case Card::Rank::ACE: 
            std::cout << "ACE" << '\n';
            break;
        case Card::Rank::TWO: 
            std::cout << "TWO" << '\n';
            break;
        case Card::Rank::THREE: 
            std::cout << "THREE" << '\n';
            break;
        case Card::Rank::FOUR: 
            std::cout << "FOUR" << '\n';
            break;
        case Card::Rank::FIVE: 
            std::cout << "FIVE" << '\n';
            break;
        case Card::Rank::SIX: 
            std::cout << "SIX" << '\n';
            break;
        case Card::Rank::SEVEN: 
            std::cout << "SEVEN" << '\n';
            break;
        case Card::Rank::EIGHT: 
            std::cout << "EIGHT" << '\n';
            break;
        case Card::Rank::NINE: 
            std::cout << "NINE" << '\n';
            break;
        case Card::Rank::TEN: 
            std::cout << "TEN" << '\n'; 
            break; 
        case Card::Rank::JACK:
            std::cout << "JACK" << '\n';
            break;
        case Card::Rank::QUEEN:
            std::cout << "QUEEN" << '\n';
            break;
        case Card::Rank::KING:
            std::cout << "KING" <<  '\n';
        default:
            std::cout << "RANK" << '\n';
            break;
    }
    return potoc;
}
std::ostream& operator << (std::ostream& potoc, const Card& card) {
    if (card.m_position) {
        potoc << card.m_Rank << " " << card.m_Suit << "\n"; 
    }
    else {
        potoc << "XX" << "\n";        
    }
    return potoc;
}
class Hand {
    protected:
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
class GenericPlayer : public Hand {
    public:
        GenericPlayer (const std::string& name = ""):m_Name(name) {
            
        }
        virtual ~GenericPlayer() {

        }
// показывает, хочет ли игрок продолжать брать карты
// Для класса GenericPlayer функция не имеет своей реализации,
// т.к. для игрока и дилера это будут разные функции
        virtual bool IsHitting() const = 0;
// возвращает значение, если у игрока перебор -
// сумму очков большую 21
// данная функция не виртуальная, т.к. имеет одинаковую реализацию
// для игрока и дилера
        bool IsBusted() const {
            return (GetTotalValue () > 21);
        }
// объявляет, что игрок имеет перебор
// функция одинакова как для игрока, так и для дилера
        void Bust() const {
            std::cout << m_Name << " busts.\n";
        };
    protected:
        std::string m_Name;
    friend std::ostream& operator<<(std::ostream& potoc, const GenericPlayer&aGenericPlayer); 
};
std::ostream& operator<<(std::ostream& potoc, const GenericPlayer& aGenericPlayer) {
    potoc << aGenericPlayer.m_Name << ":\t";
    std::vector<Card*>::const_iterator pCard;
    if (!aGenericPlayer.m_Card.empty()) {
        for (pCard = aGenericPlayer.m_Card.begin();pCard != aGenericPlayer.m_Card.end();++pCard) {
            potoc << *(*pCard) << "\t";
        }
        if (aGenericPlayer.GetTotalValue() != 0) {
            std::cout << "(" << aGenericPlayer.GetTotalValue() << ")";
        }
    }
    else {
        potoc << "<empty>";
    }
    return potoc;
}
class Player : public GenericPlayer {
    public:
        Player(const std::string& name = "");
        virtual ~Player();
    // показывает, хочет ли игрок продолжать брать карты
        virtual bool IsHitting() const {
            std::cout << m_Name << ", do you want a hit? (Y/N): ";
            char response;
            std::cin >> response;
            return (response == 'y' || response == 'Y');
        }
    // объявляет, что игрок победил
        void Win() const {
            std::cout << m_Name << " wins.\n";
        }
    // объявляет, что игрок проиграл
        void Lose() const {
            std::cout << m_Name << " loses.\n";
        }
// объявляет ничью
        void Push() const {
            std::cout << m_Name << " pushes.\n";
        }
};
class House : public GenericPlayer {
    public:
        House(const std::string& name = "House");
        virtual ~House();
    // показывает, хочет ли дилер продолжать брать карты
        virtual bool IsHitting() const {
            return (GetTotalValue() <= 16);
        }
    // переворачивает первую карту
        void FlipFirstCard() {
            if (!(m_Card.empty())) {
                m_Card[0]->Flip();
            }
            else {
                std::cout << "No card to flip!\n";
            }
        }
};
int main() {
    Hand hand;

    Card card(Card::Rank::KING, Card::Suit::DIAMONDS, true);
    hand.Add(&card);

    Card card2(Card::Rank::THREE, Card::Suit::CLUBS, true);
    hand.Add(&card2);

    Card card3(Card::Rank::ACE, Card::Suit::SPADES, true);
    hand.Add(&card3);

    std::cout <<hand.GetTotalValue()  << "\n";
    std::cout << card; //!!!!Почему выводится дефолтное значение масти выбора switch?
    //а для других объектов card2 и card3 всё выводится нормально
return 0;
} 

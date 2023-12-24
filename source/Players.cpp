#include "Players.hpp"

Players::Players()
{
    setPlayerName("Player");
    setDealerName("Dealer");
}
Players::Players(string namePlayer, string nameDealer)
{
    setPlayerName(namePlayer);
    setDealerName(nameDealer);
}
string Players::getPlayerName() const
{
    return namePlayer;
}
string Players::getDealerName() const
{
    return nameDealer;
}
char Players::getChoice() const
{
    return choice;
}
void Players::setPlayerName(string namePlayer)
{
    this-> namePlayer = namePlayer;
}
void Players::setDealerName(string nameDealer)
{
    this-> nameDealer = nameDealer;
}
void Players::setChoice(char choice)
{
    this-> choice = choice;
}
vector<Card> Players::setdealerHand(vector<Card>& hH, vector<Card>& d)
{
    for(int i = 0; i < 2; i++)  // loop to get first two cards
    {
        // dealer hand
        hH.push_back(d[0]);
        d.erase(d.begin());

        if(d.empty())
        {
            cout << "No more cards. \n";
            cout << "Thank you for playing.\n";
        }
    }
    return hH;  // returns dealer's hand
}
vector<Card> Players::setplayerHand(vector<Card>& hP, vector<Card>& d1)
{
    for(int i = 0; i < 2; i++)  // loop to get first two cards
    {
        // player hand
        hP.push_back(d1[0]);
        d1.erase(d1.begin());

        if(d1.empty())
        {
            cout << "No more cards. \n";
            cout << "Thank you for playing.\n";
        }
    }
    
    return hP;  // returns player's hand
}
ostream& operator<<(ostream& out, Players& p1)
{
    out << "=================================\n";
    out << "||                             ||\n";
    out << "||  Welcome to BlackJack 2022  ||\n";
    out << "||                             ||\n";
    out << "=================================\n\n";
    out << "\t1. New Game\n";
    out << "\t2. Exit Game\n\t";
    return out;
}
istream& operator>>(istream& in, Players& p1)
{
    in >> p1.choice;
    return in;
}



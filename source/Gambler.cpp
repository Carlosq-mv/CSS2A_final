#include "Gambler.hpp"

Gambler::Gambler()
{
    setNum_of_cards(2);

}
Gambler::Gambler(int num_of_cards)
{
    setNum_of_cards(num_of_cards);
}
void Gambler::setNum_of_cards(int num_of_cards)
{
    this-> num_of_cards = num_of_cards;
}
int Gambler::getNum_of_cards() const
{
    return num_of_cards;
}
void Gambler::print() const
{
    cout << "\tAccount Info\n";
    cout << "\tName: " << getPlayerName() << endl;
    cout << "\tHere are your " << num_of_cards << " cards. " << endl;
    cout << "\nYou will be playing against " << nameDealer << " today.\nGood luck!\n";
}
vector<Card> Gambler::hit(vector<Card>& hand, vector<Card>& d)
{
    // hit function adds one card to Gambler(player) hand
    for(int i = 0; i < 1; i++)
    {
        hand.push_back(d[0]);
        d.erase(d.begin());
        
        if(d.empty())
        {
            cout << "No more cards in deck.\n";
            cout << "Thank you for playing.\n";
        }
    }
    return hand;   // returns the new hand
}
ostream& operator<<(ostream& out, Gambler& g1)
{
    out << "=======================================================================================\n";
    out << "\tGoal of BlackJack is to reach 21 points without exceeding that number.\n";
    out << "\tIf value of player's hand has exceeded 21, player will lose and the house wins.\n";
    out << "\tPlayer wins if they hit BlackJack or their hand is worth more than the dealer's hand\n";
    out << "\n\tEnjoy BlackJack 2022!\n";
    out << "=======================================================================================\n";
    return out;
}

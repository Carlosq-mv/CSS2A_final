#include "Dealer.hpp"

Dealer::Dealer()
{
    setValue(0);
}
Dealer::Dealer(int value)
{
    setValue(value);
}
void Dealer::setValue(int value)
{
    this-> value = value;
}
int Dealer::getValue() 
{
    return value;
}
vector<Card> Dealer::hit(vector<Card>& hand, vector<Card>& d)
{
    // hit function adds one card to Dealer hand
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
    return hand;    // returns the new hand
}


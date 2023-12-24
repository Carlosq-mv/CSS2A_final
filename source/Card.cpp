#include "Card.hpp"

Card::Card()
{
    setValue(0);
    setSuit("unkown");
    setFace("unkown");
}
Card::Card(int value, string face, string suit)
{
    setValue(value);
    setSuit(suit);
    setFace(face);
}
void Card::setValue(int value)
{
    this-> value = value;
}
void Card::setSuit(string suit)
{
    this-> suit = suit;
}
int Card::getValue() const
{
    return value;
}
void Card::setFace(string face)
{
    this-> face = face;
}
string Card::getFace() const
{
    return face;
}
string Card::getSuit() const
{
    return suit;
}
void Card::print() const
{
    cout << face << " of " << suit << endl;
}


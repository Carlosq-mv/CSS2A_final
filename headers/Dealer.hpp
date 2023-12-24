#pragma once
#include "Card.hpp"
#include "Players.hpp"
#include <iostream>
#include <vector>

class Dealer : public Players
{
    private:
        int value;
    public:
        Dealer();       // constructor
        Dealer(int);    // overloaded constructor
        void setValue(int);     // settors (mutators) for member variable
        int getValue();         // gettors (accesors) for member variable
        // hit function
        vector<Card> hit(vector<Card> &handH, vector<Card> &deck);
};

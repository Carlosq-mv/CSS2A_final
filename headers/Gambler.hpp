#pragma once
#include "Players.hpp"
#include <iostream>
using namespace std;

class Gambler : public Players
{
    // overloaded output operator
    friend ostream& operator<<(ostream& out, Gambler& g1);
    
    private:
        int num_of_cards;
    public:
        Gambler();  // constructor
        Gambler(int);   // overloaded constructor
        void setNum_of_cards(int);      // setters (mutators) for Gambler member variable
        int getNum_of_cards() const;    // gettors (accesors) for Gambler member variable;
        // print fucntion
        void print() const;
        // hit function
        vector<Card> hit(vector<Card>& hand, vector<Card>& d);
};


#pragma once

#include "Card.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Players
{
    // overloaded input and output operators
    friend ostream& operator<<(ostream& out, Players& p1);
    friend istream& operator>>(istream& in, Players& p1);
    
    protected:
        string namePlayer, nameDealer;
        char choice;
    public:
        Players();  // constructor
        Players(string, string);    // overloaded constructor
        string getPlayerName() const;   // getters (accesors) for Players member variables
        string getDealerName() const;
        char getChoice() const;
        void setPlayerName(string);     // setters (mutators) for Players member variables
        void setDealerName(string);
        void setChoice(char);
        // sets first two cards for Player and Dealer
        vector<Card> setdealerHand(vector<Card>& hH, vector<Card>& d);
        vector<Card> setplayerHand(vector<Card>& hP, vector<Card>& d1);
};

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Card
{
    private:
        int value;
        string suit;
        string face;
    public:
        Card();     // constructor
        Card(int, string, string);  // overloaded constructor
        void setValue(int);      // setters (mutators) for Card member variables
        void setSuit(string);
        void setFace(string);
        int getValue() const;   // gettors (acccesors) for Card member variables
        string getSuit() const;
        string getFace() const;
        // print fucntion
        void print() const;
};


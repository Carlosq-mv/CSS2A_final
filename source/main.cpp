/*
 * Title: finalproject.cpp
 * Description: This progam will emulate the card game BlackJack
 * Author: Carlos Quiroz, Carmen Aguila, Kathryne
 * Date: 5/16/22
 */
#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <ctime>
#include <iomanip>
#include "Players.hpp"
#include "Gambler.hpp"
#include "Dealer.hpp"
#include "Card.hpp"

using namespace std;

// function prototypes
void playerprint(Players& g, Gambler& p, vector<Card>& playerHand, vector<Card>& d, int& playerP);
void dealerprint(vector<Card>& dealerHand, int& dealerP);
void totalpoints(vector<Card>& s, int& pt);
ostream& operator<<(ostream& out, vector<Card>& hand);

int main()
{
    // declarations
    ifstream fin;
    vector<Card> deck, handH, handP;
    string suit, face, name;
    char ch, option;
    int value, pointP = 0, pointH = 0, winsP = 0, winsH = 0;
    // objects
    Card card;
    Dealer house;
    Gambler player;
    Players game;

    cout << game;   // prints main menu
    cin >> game;

    if(game.getChoice() == '1')
    {
        cout << player << endl;     // prints small message on rules

        cout << "Enter you name: ";     // users enters name
        cin >> name;
        player.setPlayerName(name);

        cout << endl;
        player.print();     // prints player info
        cout << endl;
    
        // user enters file path
        fin.open("");
        
        if(fin.fail())  // check if file will open
        {
            cout << "Error: File could not open.";
            exit(1);
        }
        
        // loop that read file to store into a vector
        for(int i = 0; i < 52; i++)
        {
            fin >> face >> suit >> value;

            deck.push_back(Card(value, face, suit));
        }
        
        shuffle(deck.begin(), deck.end(), default_random_engine(time(0)));     // function that shuffles deck of cards each time

        do
        {
            game.setdealerHand(handH, deck);    // first two cards for dealer are set
            game.setplayerHand(handP, deck);    // first two cards for player are set
            
            totalpoints(handH, pointH);     // points of dealer hand are calculated
            totalpoints(handP, pointP);     // points of player hand are calculated
            
            // dealers first two cards
            cout << "\n=======================================\n";
            cout << "Dealer's hand: \n";
            
            for(int i = 0; i < handH.size()-1; i++)     // loop hides dealers first card
            {
                if(i == 0)
                    cout << "\t xxxxxxxxxxxxxx" << endl;
                
                cout << "\t " << handH[1].getFace() << " of " << handH[1].getSuit() << endl;
            }
            cout << "=======================================\n\n\n";
 
            
            // players first two cards
            cout << "=======================================\n";
            cout << player.getPlayerName() <<"'s hand: " << pointP << endl;
            
            // range based for loop to show players hand
            for(auto& p : handP)
            {
                cout << "\t "; p.print();
            }
            cout << "=======================================\n\n\n";
    
            bool choice = true;
            while(choice == true)
            {
                cout << "Would you like to (h)it or (s)tand?: ";    // player choose to hit or stand
                cin >> option;

                if(option == 'h')
                {
                    // function that prints out results after hitting
                    playerprint(game, player, handP, deck, pointP);
                    
                    if(pointP == 21)        // player gets 21 points
                    {
                        cout << player.getPlayerName() <<" hit blackjack!\n\n";
                        choice = false;     // choice set to false to exit while loop
                    }
                    else if(pointP > 21)    // player goes over 21 points
                    {
                        cout << player.getPlayerName() <<" busts.\n\n";
                        choice = false;     // choice set to false to exit while loop
                    }
                }
                else if(option == 's')
                {
                    cout << endl << player.getPlayerName() <<" choose to stand.\n\n";
                    choice = false;    // choice set to false to exit while loop
               }
            
            }
            
            cout << "Dealer's turn\n";
            if(pointH >= 17)
            {
                dealerprint(handH, pointH); // print function for dealer to print dealer hand
            }
            else
            {
                while(pointH < 17)  // continue to hit until they get atleast 17
                {
                    house.hit(handH, deck);     // dealer hit function adds one card at a time
                    totalpoints(handH, pointH); // points of dealer hand are calculated
                }

               dealerprint(handH, pointH);  // print function for dealer to print dealer hand
            }
            
            if(pointH > 21)
                cout << "\nDealer busts.\n\n";
            else if (pointH == 21)
                cout << "\nDealer hit BlackJack!\n\n";

            // calculates who wins the round
            if(pointH > pointP && pointH < 21 && pointP < 21)   // when both hands are under 21 and dealer has more points than player, dealer wins
                winsH++;
            else if(pointP > pointH && pointH < 21 && pointP < 21)  // when both hands are under 21 and player has more points than dealer, player wins
                winsP++;
            else if(pointH > 21 && pointP < 21) // hand of player is less than 21 and hand of dealer is more than 21, player wins
                winsP++;
            else if(pointP > 21 && pointH < 21) // hand of dealer is less than 21 and hand of player is more than 21, dealer wins
                winsH++;
            if(pointP == 21)    // hand is 21, automatic win
                winsP++;
            if(pointH == 21)    // hand is 21, automatic win
                winsH++;
            if(pointP > 21 && pointH > 21)  // loss if both hands go over 21
                cout << "Both lose. No one wins!\n\n";
            else if (pointH == pointP)      // tie if both hands go over 21
                cout << "Tie. No one wins!\n\n";

            // results summed up on chart after every round ends
            cout << "\n===Round Results===\n";
            cout << "||\t Dealer: " <<  winsH << setw(5) << "||" << endl;
            cout << "||\t Player: " << winsP << setw(5) <<"||" << endl;
            cout << "===================\n\n";
    
            // asks user if they want to play again
            cout << "Do you want to play again? (y)es || (n)o: ";
            cin >> ch;
            
            // clears the hand of player and dealer
            handH.clear();
            handP.clear();
        }
        while(ch == 'y');   // as long as player chooses 'y', the progam will run until they choose 'n'
        
        // final results summed up on chart after player choose to not play again
        cout << "\n====Final Results====\n";
        cout << "||\tDealer wins: " << winsH << " ||\n";
        cout << "||\tPlayer wins: " << winsP << " ||\n";
        cout << "=====================\n";
        cout << "\nThank you for playing BlackJack 2022!\n";
    }
    else
    {
        cout << "Thank you. Goodbye.\n";
        exit(1);
    }
}
/*
 * Purpose: This function is used to set the points of the hand of dealer and player.
 * It reads through the vector of Card and adds up the value of the cards in the vector.
 * Passes a vector of Card and an int by reference
 */
void totalpoints(vector<Card>& s, int& pt)
{
    pt = 0;
    for(int i = 0; i < s.size(); i++)    // loop to set points
    {
        pt += s[i].getValue();
    }
}
/*
 * Purpose: Overloads output operator to print out the card they receive.
 * Passes a vector of Card and ostream by reference
 */
ostream& operator<<(ostream& out, vector<Card>& hand)
{
    // loop for player when they choose "hit"
    // it will only print the new card they recieve
    int k = 1;
    for(int i = k; i < hand.size() - k; i++)
    {
        out << "Card: " << hand[hand.size()-1].getFace() << " of " << hand[hand.size()-1].getSuit();
        k++;
    }
    return out;
}
/*
 * Purpose: Prints the player card and points when they choose to hit
 * Passes an object of Players, Gambler, 2 vectors of Card, and an int by reference
 */
void playerprint(Players& g, Gambler& p, vector<Card>& playerHand, vector<Card>& d, int& playerP)
{
    cout << endl << p.getPlayerName() << " chooses to hit";
    cout << "\n\n**************************************\n";
    
    p.hit(playerHand, d);    // player hit function adds one card at a time
    
    totalpoints(playerHand, playerP); // points of hand calculated

    cout << playerHand << endl;      // print out only the card player just received
   
    cout << p.getPlayerName() << "'s hand: " << playerP << endl;
    cout << "**************************************\n\n";
}
/*
 * Purpose: Prints the dealers hand after player is done
 * Passes a vector of Card and int by reference
 */
void dealerprint(vector<Card>& dealerHand, int& dealerP)
{
    cout << "\n\n><><><><><><><><><><><><><><><><><><><\n";
    cout << "Dealer's hand: " << dealerP << endl;

    for(auto& h : dealerHand)    // range based for loop to print dealer's hand
    {
        cout << "\t= "; h.print();
    }
    cout << "><><><><><><><><><><><><><><><><><><><\n\n";
}

/**
 *
 * CCI Ch7.1
 *
 * Noah
 *
 * Disign the datastructures for a generic deck of cards. Explain how you would subclass the data structures to implement blackjack.
 */


#include <string>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Card {
    public:
        Card(int v, int s) {
            value = v; 
            suit = s;
            

        }    
        ~Card(){}

        int getVal() {return value;}
        int getSuit() {return suit;}

    private:
        int value = -1;
        int suit;
};



class Deck {
    public:
        Deck() {
            pos = -1;
            for(int i = 0; i < 52; i++) {
                cards.push_back(Card((i%13)+1, (i%4)+1));    
            }  
        }
        ~Deck(){}
        void shuffle(){
            // Maybe implement later...
        }

        Card draw() {
            if (pos > cards.size()) {
                return Card(-1, -1);
            }
            Card c = cards[pos];
            pos++;
            return c;
        }

    private:
        vector<Card> cards;
        int pos = -1;

};



class BlackJack : Deck {
    public:
        BlackJack(int p) {
            shuffle();
            for(int i = 0; i > p; i++){
                vector<Card> temp = {draw(), draw()};
                players.push_back(temp);
            }    
        }

        void round() {
            // Play one round 
            // Check if a player has won
            // Deal out more cards? I dont know how to play blackjack....
            // Check if the deck is empty
        }

    private:
        vector<vector<Card>> players;



};

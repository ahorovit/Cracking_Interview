
/* 
   Design data structures for generic deck of cards. Explain how you would sublass 
   the structures to implement blackjack
*/

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;


class Card
{
private:
  char name;
  char suit;
  int value;

public:
  Card(char n, char s, int v)
  {
    name = n; // 2 through 9,X,J,Q,K,A
    suit = s; // suits: spades (s), clubs (c), diamonds (d), hearts (h)
    value = v; // depends on game
  }
};



class Deck
{
  Card * cards[52];
  char suits[4] = {'s','c','d','h'};
  char names[13] = {'2','3','4','5','6','7','8','9','X','J','Q','K','A'};

  //  int values[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
  
public:
  Deck()
  {   
    int dInd = 0;

    // Iterate suits
    for (int ss = 0; ss < 4; ss++)
      {

	// Iterate names
	for (int nn = 0; nn < 13; nn++)
	  {
	    Card * thisCard = new Card(
	  }
      }    
  }
};

   
class BJdeck : Deck
{



};

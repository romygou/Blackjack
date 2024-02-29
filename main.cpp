//
//  main.cpp
//  Blackjack 
//

#include <iostream>
#include <cassert>
#include "Enums.h"
#include "Card.h"
#include "Hand.h"

using namespace std;
using namespace cs32;

int main() {
    Card c;

    Card c1;
    Card c2;
    Hand h( c1, c2);
    Card ace( Suit::CLUBS, Face::ACE );
    Card two( Suit::CLUBS, Face::DEUCE );
    Card three( Suit::CLUBS, Face::THREE );
    Card four( Suit::CLUBS, Face::FOUR );
    Card five( Suit::CLUBS, Face::FIVE );
    Card six( Suit::SPADES, Face::SIX );
    Card seven( Suit::CLUBS, Face::SEVEN );
    Card eight( Suit::CLUBS, Face::EIGHT );
    Card nine( Suit::SPADES, Face::NINE );
    Card ten( Suit::CLUBS, Face::TEN );
    Card jack( Suit::CLUBS, Face::JACK );
    Card queen( Suit::CLUBS, Face::QUEEN );
    Card king( Suit::CLUBS, Face::KING );
    // two aces...
    assert( h.evaluateHand(two) == Choice::SPLIT );
    
    h = Hand( two, two );
    assert( h.evaluateHand(two) == Choice::SPLITHIT );
    assert( h.evaluateHand(three) == Choice::SPLITHIT );
    assert( h.evaluateHand(four) == Choice::SPLIT );
    assert( h.evaluateHand(five) == Choice::SPLIT );
    assert( h.evaluateHand(six) == Choice::SPLIT );
    assert( h.evaluateHand(seven) == Choice::SPLIT );
    assert( h.evaluateHand(eight) == Choice::HIT );
    assert( h.evaluateHand(nine) == Choice::HIT );
    assert( h.evaluateHand(ten) == Choice::HIT );
    assert( h.evaluateHand(jack) == Choice::HIT );
    assert( h.evaluateHand(queen) == Choice::HIT );
    assert( h.evaluateHand(king) == Choice::HIT );
    assert( h.evaluateHand(ace) == Choice::HIT );
    
    h = Hand( queen, queen );
    assert( h.evaluateHand(two) == Choice::STAND );
    assert( h.evaluateHand(three) == Choice::STAND );
    assert( h.evaluateHand(four) == Choice::STAND );
    assert( h.evaluateHand(five) == Choice::STAND );
    assert( h.evaluateHand(six) == Choice::STAND );
    assert( h.evaluateHand(seven) == Choice::STAND );
    assert( h.evaluateHand(eight) == Choice::STAND );
    assert( h.evaluateHand(nine) == Choice::STAND );
    assert( h.evaluateHand(ten) == Choice::STAND );
    assert( h.evaluateHand(jack) == Choice::STAND );
    assert( h.evaluateHand(queen) == Choice::STAND );
    assert( h.evaluateHand(king) == Choice::STAND );
    assert( h.evaluateHand(ace) == Choice::STAND );
    
    
    h = Hand( jack, six );
    assert( h.evaluateHand(two) == Choice::STAND );
    assert( h.evaluateHand(three) == Choice::STAND );
    assert( h.evaluateHand(four) == Choice::STAND );
    assert( h.evaluateHand(five) == Choice::STAND );
    assert( h.evaluateHand(six) == Choice::STAND );
    assert( h.evaluateHand(seven) == Choice::HIT );
    assert( h.evaluateHand(eight) == Choice::HIT );
    assert( h.evaluateHand(nine) == Choice::SURRENDERHIT );
    assert( h.evaluateHand(ten) == Choice::SURRENDERHIT );
    assert( h.evaluateHand(jack) == Choice::SURRENDERHIT );
    assert( h.evaluateHand(queen) == Choice::SURRENDERHIT );
    assert( h.evaluateHand(king) == Choice::SURRENDERHIT );
    assert( h.evaluateHand(ace) == Choice::SURRENDERHIT );
    
    h = Hand( king, five );
    assert( h.evaluateHand(two) == Choice::STAND );
    assert( h.evaluateHand(three) == Choice::STAND );
    assert( h.evaluateHand(four) == Choice::STAND );
    assert( h.evaluateHand(five) == Choice::STAND );
    assert( h.evaluateHand(six) == Choice::STAND );
    assert( h.evaluateHand(seven) == Choice::HIT );
    assert( h.evaluateHand(eight) == Choice::HIT );
    assert( h.evaluateHand(nine) == Choice::HIT );
    assert( h.evaluateHand(ten) == Choice::SURRENDERHIT );
    assert( h.evaluateHand(jack) == Choice::SURRENDERHIT );
    assert( h.evaluateHand(queen) == Choice::SURRENDERHIT );
    assert( h.evaluateHand(king) == Choice::SURRENDERHIT );
    assert( h.evaluateHand(ace) == Choice::HIT );

               c = Card( Suit::CLUBS, Face::DEUCE );
               assert( c.getSuit() == Suit::CLUBS );
               assert( c.getFace() == Face::DEUCE );
               assert( c.getValue( ) == 2 );

               Card d( Suit::SPADES, Face::QUEEN );
               assert( d.getSuit() == Suit::SPADES );
               assert( d.getFace() == Face::QUEEN );
               assert( d.getValue( ) == 10 );

               ace = Card( Suit::CLUBS, Face::ACE );
               two = Card( Suit::HEARTS, Face::DEUCE );
               three = Card( Suit::DIAMONDS, Face::THREE );
               four = Card( Suit::SPADES, Face::FOUR );
               five = Card( Suit::CLUBS, Face::FIVE );
               six = Card( Suit::HEARTS, Face::SIX );
               seven = Card( Suit::DIAMONDS, Face::SEVEN );
               eight = Card( Suit::SPADES, Face::EIGHT );
               nine = Card( Suit::CLUBS, Face::NINE );
               ten = Card( Suit::HEARTS, Face::TEN );
               jack = Card( Suit::DIAMONDS, Face::JACK );
               queen = Card( Suit::CLUBS, Face::QUEEN );
               king = Card( Suit::SPADES, Face::KING );

               Hand h2( c, d );
               assert( h2.evaluateHand(two) == Choice::HIT );
               assert( h2.evaluateHand(three) == Choice::HIT );
               assert( h2.evaluateHand(four) == Choice::STAND );
               assert( h2.evaluateHand(five) == Choice::STAND );
               assert( h2.isPair( ) == false );
               assert( h2.isSoft( ) == false );

               h2 = Hand( ace, seven );
               assert( h2.evaluateHand(five) == Choice::DOUBLESTAND );
               assert( h2.evaluateHand(six) == Choice::DOUBLESTAND );
               assert( h2.evaluateHand(seven) == Choice::STAND );
               assert( h2.evaluateHand(eight) == Choice::STAND );
               assert( h2.evaluateHand(nine) == Choice::HIT );
               assert( h2.isPair( ) == false );
               assert( h2.isSoft( ) == true );

               h2 = Hand( five, five );
               assert( h2.evaluateHand(two) == Choice::DOUBLEHIT );
               assert( h2.evaluateHand(three) == Choice::DOUBLEHIT );
               assert( h2.evaluateHand(four) == Choice::DOUBLEHIT );
               assert( h2.isPair( ) == true );
               assert( h2.isSoft( ) == false );
    
    h2 = Hand( king, queen );
    assert( h2.evaluateHand(five) == Choice::STAND );
    assert( h2.evaluateHand(six) == Choice::STAND );
    assert( h2.evaluateHand(seven) == Choice::STAND );
    assert( h2.evaluateHand(eight) == Choice::STAND );
    assert( h2.evaluateHand(nine) == Choice::STAND );
    assert( h2.isPair( ) == false );
    assert( h2.isSoft( ) == false );

    cout << "all tests passed!" << endl;
    
    return( 0 );
}

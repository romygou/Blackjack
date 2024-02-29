//
//  Card.cpp
//  Blackjack 
//

#include "Card.h"

namespace cs32
{

Card::Card()
{
    mSuit = Suit::HEARTS;
    mFace = Face::ACE;
}

Card::Card( Suit s, Face f )
{
    mSuit = s;
    mFace = f;
}

Suit Card::getSuit() const
{
    return( mSuit );
}

void Card::setSuit( Suit s )
{
    mSuit = s;
}

Face Card::getFace() const
{
    return( mFace );
}

void Card::setFace( Face f )
{
    mFace = f;
}

int  Card::getValue() const
{
    int result = 0;
    
    if (mFace == Face::ACE)
    {
        result = 1;
    }
    
    if (mFace == Face::DEUCE)
    {
        result = 2;
    }
    
    if (mFace == Face::THREE)
    {
        result = 3;
    }
    
    if (mFace == Face::FOUR)
    {
        result = 4;
    }
    
    if (mFace == Face::FIVE)
    {
        result = 5;
    }
    
    if (mFace == Face::SIX)
    {
        result = 6;
    }
    
    if (mFace == Face::SEVEN)
    {
        result = 7;
    }
    
    if (mFace == Face::EIGHT)
    {
        result = 8;
    }
    
    if (mFace == Face::NINE)
    {
        result = 9;
    }
    
    if ((mFace == Face::TEN) | (mFace == Face::JACK) | (mFace == Face::QUEEN) | (mFace == Face::KING))
    {
        result = 10;
    }
    
    return( result );
}

std::string Card::to_string() const
{
    std::string result = "";
    switch( mFace )
    {
        case Face::ACE:
            result = "Ace of ";
            break;
        case Face::DEUCE:
            result = "Deuce of ";
            break;
        case Face::THREE:
            result = "Three of ";
            break;
        case Face::FOUR:
            result = "Four of ";
            break;
        case Face::FIVE:
            result = "Five of ";
            break;
        case Face::SIX:
            result = "Six of ";
            break;
        case Face::SEVEN:
            result = "Seven of ";
            break;
        case Face::EIGHT:
            result = "Eight of ";
            break;
        case Face::NINE:
            result = "Nine of ";
            break;
        case Face::TEN:
            result = "Ten of ";
            break;
        case Face::JACK:
            result = "Jack of ";
            break;
        case Face::QUEEN:
            result = "Queen of ";
            break;
        case Face::KING:
            result = "King of ";
            break;
    }
    
    
    // push s to the next suit...
    switch( mSuit )
    {
        case Suit::HEARTS:
            result += "Hearts";
            break;
        case Suit::CLUBS:
            result += "Clubs";
            break;
        case Suit::DIAMONDS:
            result += "Diamonds";
            break;
        case Suit::SPADES:
            result += "Spades";
            break;
    }
    return( result );
}


}


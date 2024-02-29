//
//  Hand.cpp
//  Blackjack 
//

#include "Hand.h"

namespace cs32
{


Hand::Hand( Card card1, Card card2 ) : mCard1( card1 ), mCard2( card2 )
{
    
}

Card Hand::getCard1() const
{
    return( mCard1 );
}

Card Hand::getCard2() const
{
    return( mCard2 );
}

Choice Hand::evaluateHand( Card dealerCard ) const
{
    // by default STAND
    Choice c = Choice::STAND;
    
    if (mCard1.getValue() + mCard2.getValue() == 8)
    {
        c = Choice::HIT;
    }
    
    if (mCard1.getValue() + mCard2.getValue() == 9)
    {
        if ((dealerCard.getValue() >= 3) & (dealerCard.getValue() <= 6))
        {
            c = Choice::DOUBLEHIT;
        } else {
            c = Choice::HIT;
        }
    }
    
    if (mCard1.getValue() + mCard2.getValue() == 10)
    {
        if ((dealerCard.getValue() >= 2) & (dealerCard.getValue() <= 9))
        {
            c = Choice::DOUBLEHIT;
        } else {
            c = Choice::HIT;
        }
    }
    
    if (mCard1.getValue() + mCard2.getValue() == 11)
    {
        c = Choice::DOUBLEHIT;
    }
    
    if (mCard1.getValue() + mCard2.getValue() == 12)
    {
        if ((dealerCard.getValue() >= 4) & (dealerCard.getValue() <= 6))
        {
            c = Choice::STAND;
        } else {
            c = Choice::HIT;
        }
    }
    
    if ((mCard1.getValue() + mCard2.getValue() == 13) | (mCard1.getValue() + mCard2.getValue() == 14))
    {
        if ((dealerCard.getValue() >= 2) & (dealerCard.getValue() <= 6))
        {
            c = Choice::STAND;
        } else {
            c = Choice::HIT;
        }
    }
    
    if (mCard1.getValue() + mCard2.getValue() == 15)
    {
        if ((dealerCard.getValue() >= 2) & (dealerCard.getValue() <= 6))
        {
            c = Choice::STAND;
        }
        if (((dealerCard.getValue() >= 7) & (dealerCard.getValue() <= 9)) | (dealerCard.getValue() == 1))
        {
            c = Choice::HIT;
        }
        if (dealerCard.getValue() == 10)
        {
            c = Choice::SURRENDERHIT;
        }
    }
    
    if (mCard1.getValue() + mCard2.getValue() == 16)
    {
        if ((dealerCard.getValue() >= 2) & (dealerCard.getValue() <= 6))
        {
            c = Choice::STAND;
        }
        if ((dealerCard.getValue() >= 7) & (dealerCard.getValue() <= 8))
        {
            c = Choice::HIT;
        }
        if ((dealerCard.getValue() == 9) | (dealerCard.getValue() == 10) | (dealerCard.getValue() == 1))
        {
            c = Choice::SURRENDERHIT;
        }
    }
    
    if (mCard1.getValue() + mCard2.getValue() == 17)
    {
        c = Choice::STAND;
    }
    
    if ((mCard1.getFace() == Face::ACE) & ((mCard2.getFace() == Face::DEUCE) | (mCard2.getFace() == Face::THREE)))
    {
        if ((dealerCard.getValue() >= 5) & (dealerCard.getValue() <= 6))
        {
            c = Choice::DOUBLEHIT;
        } else {
            c = Choice::HIT;
        }
    }
    
    if ((mCard1.getFace() == Face::ACE) & ((mCard2.getFace() == Face::FOUR) | (mCard2.getFace() == Face::FIVE)))
    {
        if ((dealerCard.getValue() >= 4) & (dealerCard.getValue() <= 6))
        {
            c = Choice::DOUBLEHIT;
        } else {
            c = Choice::HIT;
        }
    }
    
    if ((mCard1.getFace() == Face::ACE) & (mCard2.getFace() == Face::SIX))
    {
        if ((dealerCard.getValue() >= 3) & (dealerCard.getValue() <= 6))
        {
            c = Choice::DOUBLEHIT;
        } else {
            c = Choice::HIT;
        }
    }
    
    if ((mCard1.getFace() == Face::ACE) & (mCard2.getFace() == Face::SEVEN))
    {
        if ((dealerCard.getValue() >= 3) & (dealerCard.getValue() <= 6))
        {
            c = Choice::DOUBLESTAND;
        }
        if ((dealerCard.getValue() == 2) | (dealerCard.getValue() == 7) | (dealerCard.getValue() == 8))
        {
            c = Choice::STAND;
        }
        if ((dealerCard.getValue() == 9) | (dealerCard.getValue() == 10) | (dealerCard.getValue() == 1))
        {
            c = Choice::HIT;
        }
    }
    
    if ((mCard1.getFace() == Face::ACE) & (mCard2.getFace() == Face::EIGHT))
    {
        c = Choice::STAND;
    }
        
    if (isPair() == true) // evaluate if it's a pair first
    {
        if ((mCard1.getFace() == Face::DEUCE) | (mCard1.getFace() == Face::THREE))
        {
            if ((dealerCard.getValue() == 2) | (dealerCard.getValue() == 3))
            {
                c = Choice::SPLITHIT;
            }
            if ((dealerCard.getValue() >= 4) & (dealerCard.getValue() <= 7))
            {
                c = Choice::SPLIT;
            }
            if (((dealerCard.getValue() >= 8) & (dealerCard.getValue() <= 10)) | (dealerCard.getValue() == 1))
            {
                c = Choice::HIT;
            }
        }
        if (mCard1.getFace() == Face::FOUR)
        {
            if ((dealerCard.getValue() == 5) | (dealerCard.getValue() == 6))
            {
                c = Choice::SPLITHIT;
            } else {
                c = Choice::HIT;
            }
        }
        if (mCard1.getFace() == Face::FIVE)
        {
            if ((dealerCard.getValue() >= 2) & (dealerCard.getValue() <= 9))
            {
                c = Choice::DOUBLEHIT;
            } else {
                c = Choice::HIT;
            }
        }
        if (mCard1.getFace() == Face::SIX)
        {
            if (dealerCard.getValue() == 2)
            {
                c = Choice::SPLITHIT;
            }
            if ((dealerCard.getValue() >= 3) & (dealerCard.getValue() <= 6))
            {
                c = Choice::SPLIT;
            }
            if (((dealerCard.getValue() >= 7) & (dealerCard.getValue() <= 10)) | (dealerCard.getValue() == 1))
            {
                c = Choice::HIT;
            }
        }
        if (mCard1.getFace() == Face::SEVEN)
        {
            if ((dealerCard.getValue() >= 2) & (dealerCard.getValue() <= 7))
            {
                c = Choice::SPLIT;
            } else {
                c = Choice::HIT;
            }
        }
        if (mCard1.getFace() == Face::EIGHT)
        {
            c = Choice::SPLIT;
        }
        if (mCard1.getFace() == Face::NINE)
        {
            if ((dealerCard.getValue() == 1) | (dealerCard.getValue() == 7) | (dealerCard.getValue() == 10))
            {
                c = Choice::STAND;
            } else {
                c = Choice::SPLIT;
            }
        }
        if (mCard1.getValue() == 10) // use getValue to account for tens, jacks, queens, and kings
        {
            c = Choice::STAND;
        }
        if (mCard1.getFace() == Face::ACE)
        {
            c = Choice::SPLIT;
        }
    }
        
    return( c );
}

bool Hand::isPair() const
{
    if (mCard1.getFace() == mCard2.getFace())
    {
        return(true);
    } else {
        return(false);
    }
}

bool Hand::isSoft() const
{
    if ((mCard1.getFace() == Face::ACE) | (mCard2.getFace() == Face::ACE))
    {
        return(true);
    } else {
        return(false);
    }
}


}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <random>
#include <set>

struct card
{
    int value = 1;
    int color = 1;
    std::string suit = {};
    
    void print ()
    {    
        if (color == 1)
            suit = "spades";
        else if (color == 2)
            suit = "hearts";
        else if (color == 3)
            suit = "clubs";
        else
            suit = "diamonds";


    
    if (value == 14)
        std::cout << "Ace of " << suit << "\n";
    else if (value == 11)
        std::cout << "Jack of " << suit << "\n";
    else if (value == 12)
        std::cout << "Queen of " << suit << "\n";
    else if (value == 13)
        std::cout << "King of " << suit << "\n";
    else
        std::cout << value << " of " << suit << "\n";

    }
};

std::vector<card> deckCreation ()
{
    std::vector<card> d = {};
    card c;
    for (int i=1; i <= 4; ++i)
    {
        for (int j=2; j<=14; ++j)
            {
                c.value=j;
                c.color=i;
                d.emplace_back(c);
            }
    }
    return d;
}

void shuffle(std::vector<card>& dek )
{


    std::mt19937 generator(std::time(nullptr));

    std::shuffle(dek.begin(), dek.end(), generator);



}

bool compareCards(card a, card b)
{
    return (a.value < b.value);
}

auto deal5(std::vector<card>& dek)
{
    std::vector<card> hand;

    for (int i=0; i<5; ++i)
        hand.emplace_back(dek[i]);

    dek.erase(dek.begin(), dek.begin()+5);

    std::sort(hand.begin(), hand.end(), compareCards);

    return hand;
}

 std::string whatsInHand(std::vector<card>& hen)
{
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    bool trueColor = true;
    std::vector<card> Royal = {{14,1}, {13,1}, {12,1}, {11,1}, {10,1}};

    for(int i=1; i<5; ++i)
    {
        if(hen[i].color-hen[i-1].color != 0)
            trueColor=false;
            break;

    }
    
    for(int i=1; i<5; ++i)
    {
        
        if (hen[i].value == Royal[i].value && trueColor == true)
            return "Royal Flush";
        else
        {   

            if(hen[i].value-hen[i-1].value == 0)
                {
                    a++;
                    if (a == 2 && hen[i].value - hen[i-2].value == 0)
                        c++;
                
                
                }
            else if(hen[i].value-hen[i-1].value == -1)
                {
                    d++;
                }
            else
                {
                     b++;
                }      
        }
    }

    if(a == 1 && b == 3 && c == 0)
    return "A pair";

    else if(a == 2 && b == 2 && c == 1)
    return "Three of same";
    
    else if(a == 3 && b == 1 && c == 0)
    return "Four of same"; 

    else if(a == 2 && b == 2 && c == 0)
    return "Two pairs"; 

    else if(a == 3 && b == 1 && c == 1)
    return "Full house"; 

    else if(a == 0 && b == 0 && c == 0 && d == 4 && trueColor == true )
    return "Straight Flush"; 
    
    else if(a == 0 && b == 0 && c == 0 && d == 4 && trueColor == false )
    return "Straight";

    else if(a == 0 && b == 4 && c == 0 && d == 0 && trueColor == true )
    return "Flush"; 

    else
    return "Nothing";
    
    
} 

void compareHands (std::string hand1, std::string hand2)
{
    std::set<std::string> allValues = {"Nothing", "A pair", "Two pairs", "Three of same", "Straight", "Flush", "Full house", "Four of same","Straight Flush", "Royal Flush" };
    std::set<std::string>::iterator position1 = allValues.find( hand1);
    std::set<std::string>::iterator position2 = allValues.find( hand2);
    if(*position1 < *position2)
        std::cout<< hand1 <<" is stronger than "<< hand2; 
    else
    {
        std::cout<< hand2 <<" is stronger than "<< hand1; 
    }
    
}

int main()
{
    static std::vector<card> deck = deckCreation();
    
    shuffle(deck);

    std::vector<card> handOne = deal5(deck);
    std::vector<card> handTwo = deal5(deck);
    //{{7,1},{6,2},{5,2},{4,4},{3,3}};
    
    for(card c : handOne)
    {
        c.print();
    }
    std::cout<< whatsInHand(handOne) <<" \n";
    std::cout<<"\n";

    for(card c : handTwo)
    {
        c.print();
    }

    
    std::cout<< whatsInHand(handTwo) <<" \n";

    compareHands(whatsInHand(handOne), whatsInHand(handTwo));
}

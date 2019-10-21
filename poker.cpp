#include <iostream>
#include <vector>
#include <string>

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


int main()
{

}
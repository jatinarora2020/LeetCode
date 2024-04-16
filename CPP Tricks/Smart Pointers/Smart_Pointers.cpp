#include <iostream>
#include <memory> // Header for Smart Pointers
using namespace std;

class Rectangle 
{
    int dLength;
    int dBreadth;

    public:
    Rectangle(int xLength = 0,int xBreadth = 0) : dLength(xLength),dBreadth(xBreadth)
    {

    }
};

int main()
{
    unique_ptr<Rectangle> lUnique_Ptr;
    cout<<"Unique Ptr";
    return 0;
}
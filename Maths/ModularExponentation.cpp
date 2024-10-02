#include<iostream>
using namespace std;

int Exponent(int base,int exp,int N ){
        
    long t = 1L;
    while (exp > 0) 
    {
 
        // for cases where exponent
        // is not an even value
        if (exp % 2 != 0)
            t = (t * base) % N;
 
        base = (base * base) % N;
        exp =exp/ 2;
    }
    return t % N
}

int main()
{
 return 0;
}
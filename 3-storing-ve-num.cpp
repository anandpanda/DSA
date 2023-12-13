/*
First bit : 0 --> +ve
            1 --> -ve
Lets take -5 :
1) Ignore the -ve sign --> 5
2) Convert to Binary -->  00000000 00000000 00000000 00000101
3) Take 2's compliment :-
    1's compliment --> 11111111 11111111 11111111 11111010
    2's compliment --> 11111111 11111111 11111111 11111011  (1's + 1)  1st '1' represent sign(-ve)
4) Printing num :-
    consider binary after 2's comp. (1st bit '1' represents -ve sign)
    take 2's compliment again
    after 2's compliment the binary gives the number without sign
    sign is obtained from above 
*/

#include <iostream>
using namespace std;

int main()
{
    unsigned int a = 112;  // range is 0 to 2^32 - 1
    unsigned int b = -112; // most significant bit is 1 (after 2's comp.), hence a very large value
    cout << a << endl
         << b << endl;

    return 1;
}
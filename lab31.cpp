
#include <iostream>
#include <vector>
#include<fstream>
#include <iterator>

using namespace std;

int main()
{
    ifstream trojki("trojki.txt");
    ofstream wynik("wynik.txt");
    vector<int> in;
    vector<int> popr;
    vector<int>::iterator ptr;
    int value;
    while (trojki >> value) {
        in.push_back(value);
        
    }
    int a, b, c;
    for (ptr = in.begin(); ptr < in.end(); ptr++){
        
       a = *ptr;
       b = ++*ptr;
       c = ++*ptr;
       if (a * a + b * b == c * c) {
           cout << a << " " << b << " " << c << endl;
           wynik << a << " " << b << " " << c << endl;
       }
     }
    
    return 0;
}

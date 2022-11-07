#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int lenOfLongZigZagArr(vector<int> a)
{
    vector<int>::iterator it;
    int max = 1,
    len = 1;

    for (it = a.begin(); it < a.end();it++) {

        if (i % 2 == 0
            && (a[i] < a[i + 1]))
            len++;

        else if (i % 2 == 1
            && (a[i] > a[i + 1]))
            len++;

        else {
         
            if (max < len)
                max = len;

            len = 1;
        }
    }

    if (max < len)
        max = len;

    return max;
}


int main()
{
    vector<int> zigzag = { 1, 2, 1, 4, 5 };

    cout << lenOfLongZigZagArr(zigzag);

    return 0;
}
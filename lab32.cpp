#include <iostream>
#include <iterator>
#include <list>
using namespace std;

void printNestedList(list<list<int>> nested_list)
{
 

    list<list<int> >::iterator nested_list_itr;

    for (nested_list_itr = nested_list.begin();
        nested_list_itr != nested_list.end();
        ++nested_list_itr) {


        list<int>::iterator single_list_itr;

        list<int>& single_list_pointer = *nested_list_itr;

        for (single_list_itr = single_list_pointer.begin();
            single_list_itr != single_list_pointer.end();
            single_list_itr++) {
            cout << " " << *single_list_itr << " ";
        }
        cout << "\n";
    }
   
}


int main()
{
   
    list<list<int>> nested_list;
    list<int> single_list;
    int n, m, num;

    n = 5;

    for (int i = 0; i < n; i++) {

        m = i + 2;
        for (int j = 0; j < m; j++) {
            num = i + j;
            single_list.push_back(num);
        }

        nested_list.push_back(single_list);

        single_list.erase(single_list.begin(),
            single_list.end());
    }

    printNestedList(nested_list);

    return 0;
}
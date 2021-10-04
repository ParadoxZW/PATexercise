#include <iostream>
#include <stdio.h>
#include "quickSort.cpp"
using namespace std;

int main(){
    int x[10] = {4, 5, 1, 1, 2, 4, 6, 7, 9, 8};
    quickSort(x, 0, 9);
    for(auto i:x){
        cout << i << " ";        
    }
    cout << endl;
    return 0;
}

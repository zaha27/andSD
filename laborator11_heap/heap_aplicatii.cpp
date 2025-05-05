#include <iostream>
#include "heap.h"

using namespace std;

void sortare_aplicatia1(int de_sortat[], int heap[], int n) {
    for(int i = 0; i < n; ++i) {
        insertHeap(heap, n, de_sortat[i]);
    }
    
    int ret_val;
    do { 
        ret_val = removeHeap(heap, n);
        if(ret_val != -1)
            cout << ret_val << ' ';
    } while(ret_val != -1);
}

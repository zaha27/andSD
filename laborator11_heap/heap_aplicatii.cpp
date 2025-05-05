#include <iostream>
#include "heap.h"

void sortare_aplicatia1(int de_sortat[], int heap[], int n) {
    for(int i = 0; i < n; ++i) {
        insert(heap, n, de_sortat[i]);
    }
    do { 
        ret_val = remove(heap);
        cout << ret_val << ' ';
    } while(ret_val != -1);
}
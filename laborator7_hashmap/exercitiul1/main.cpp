#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "header.h"

int main(int argc, char *argv[]) {

    if (argc < 2) {
        cerr << "Utilizare: " << argv[0] << " <fisier_intrare>\n";
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if(0 == f) {
        perror("Eroare la deschiderea fisierului!");
        return 1;
    }
    char buffer[255];

    Nod* HT[M];
    init(HT);

    while(fgets(buffer, sizeof(buffer), f)) {
        buffer[strlen(buffer)] = '\0';
        insert(HT, buffer);
    }

    fclose(f);

    cout << "\nCuvintele din fisier:\n";
    afisare(HT);

    return 0;
}
#include <iostream>

using namespace std;
using namespace cimg_library;
using namespace std::chrono;

struct Pozitie {
    int x, y;
};

Pozitie directii[4] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };

    CImg<unsigned char> ColoreazaDomeniu(CImg<unsigned char>& in, Pozitie init, unsigned char color, CImgDisplay& dispOut) {
    CImg<unsigned char> imgOut = in; // imgOut este o copie a lui in

    //dimensiunile imaginii
    int width = in.width();
    int height = in.height();

    unsigned char culoareDomeniu = in(init.x, init.y); // obtinem valoarea pixelului de la pozitia initiala
    cout << "Color: " << (unsigned int)culoareDomeniu << "( " << init.x << ", " << init.y << ")" << endl;

    //... adaugati logica aplicatiei aici
    //afisati imaginea dupa fiecare pas pentru a vedea cum se modifica culoarea domeniului in timp real
    
    cout << "DONE!" << endl;
    return imgOut;
}

int main() {
    CImg<unsigned char> imgIn("/home/ubuntu/SD/ColorareDomeniu/img.jpg"); // Incarca imaginea, de specificat calea completa

    // Creati o fereastra pentru a vizualiza imaginile
    CImgDisplay dispIn(imgIn, "Input");
    CImgDisplay dispOut;

    Pozitie posInit;
    posInit.x = imgIn.width() / 2;
    posInit.y = imgIn.height() / 2;

    // imgIn este o imagine grayscale (fiecare pixel este reprezentat de o valoare pe 8 biti, in [0,255])
    CImg<unsigned char> imgOut = ColoreazaDomeniu(imgIn, posInit, (unsigned char)255, dispOut);

    // Afisarea imaginilor
    dispOut = CImgDisplay(imgOut, "Output");

    // Asteptam ca utilizatorul sa inchida fereastra
    while (!dispIn.is_closed() && !dispOut.is_closed()) {
        dispIn.wait();
        dispOut.wait();
    }

    return 0;
}

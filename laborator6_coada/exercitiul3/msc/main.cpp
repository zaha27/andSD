#include <iostream>
#include "CImg.h"

using namespace std;
using namespace cimg_library;
using namespace std::chrono;

// ------------------ STRUCTURI ȘI TIPURI ------------------

struct Poz {
    int x, y;
};

Poz directii[4] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };

struct Element {
    Poz data;
    Element* succ;
};

struct Queue {
    Element* head;
    Element* tail;
};

// ------------------ COADA ------------------

void initQueue(Queue& Q) {
    Q.head = Q.tail = nullptr;
}

int isEmpty(Queue Q) {
    return Q.head == nullptr && Q.tail == nullptr;
}

void put(Queue& Q, Poz a) {
    Element* temp = new Element;
    temp->data = a;
    temp->succ = nullptr;

    if (isEmpty(Q)) {
        Q.head = Q.tail = temp;
    } else {
        Q.tail->succ = temp;
        Q.tail = temp;
    }
}

Poz get(Queue& Q) {
    if (isEmpty(Q)) {
        cout << "coada este goala";
        exit(1);
    }

    Poz val = Q.head->data;
    Element* temp = Q.head;
    Q.head = Q.head->succ;
    delete temp;

    if (Q.head == nullptr) {
        Q.tail = nullptr;
    }

    return val;
}

// ------------------ FUNCTIE DE COLORARE ------------------

CImg<unsigned char> ColoreazaDomeniu(CImg<unsigned char>& in, Poz init, unsigned char color, CImgDisplay& dispOut) {
    CImg<unsigned char> imgOut = in;

    int width = in.width();
    int height = in.height();

    unsigned char culoareDomeniu = in(init.x, init.y);
    cout << "Color: " << (unsigned int)culoareDomeniu << " (" << init.x << ", " << init.y << ")" << endl;

    Queue Q;
    initQueue(Q);
    put(Q, init);
    imgOut(init.x, init.y) = color;

    while (!isEmpty(Q)) {
        Poz p = get(Q);
        for (int d = 0; d < 4; ++d) {
            Poz pi = { p.x + directii[d].x, p.y + directii[d].y };
            if ((pi.x >= 0 && pi.x < width) && (pi.y >= 0 && pi.y < height) &&
                imgOut(pi.x, pi.y) == culoareDomeniu) {
                imgOut(pi.x, pi.y) = color;
                put(Q, pi);
            }
        }
        dispOut.display(imgOut);
        cimg::sleep(10);
    }

    cout << "DONE!" << endl;
    return imgOut;
}

// ------------------ MAIN ------------------

int main() {
    CImg<unsigned char> imgIn(200, 200, 1, 1, 255); // imagine albă

    unsigned char alb[] = {0};
    unsigned char negru[] = {255};
    imgIn.draw_rectangle(50, 50, 150, 150, alb);     // pătrat negru
    imgIn.draw_rectangle(80, 80, 120, 120, negru);   // pătrat alb în mijloc

    CImgDisplay dispIn(imgIn, "Input");
    CImgDisplay dispOut;

    Poz posInit;
    posInit.x = imgIn.width() / 2;
    posInit.y = imgIn.height() / 2;

    CImg<unsigned char> imgOut = ColoreazaDomeniu(imgIn, posInit, (unsigned char)255, dispOut);
    dispOut = CImgDisplay(imgOut, "Output");

    while (!dispIn.is_closed() && !dispOut.is_closed()) {
        dispIn.wait();
        dispOut.wait();
    }

    return 0;
}

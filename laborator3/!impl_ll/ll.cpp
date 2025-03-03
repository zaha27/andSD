// Program C++ pentru implementarea unei liste inlantuite
#include <iostream>
using namespace std;

// Structura pentru un nod din lista inlantuita
struct Node {
    int data;  
    Node* succ; 
};

// Definirea clasei pentru lista inlantuita
class LinkedList {
    // Pointer catre primul nod din lista
    Node* head;

public:
    // Constructor care initializeaza head cu NULL
    LinkedList() : head(NULL) {}

    // Functie pentru inserarea unui nou nod la inceputul listei
    void insertAtBeginning(int value) {
        Node* p = new Node(); 
        p->data = value;      
        p->succ = head;      
        head = p;            
    }

    // Functie pentru inserarea unui nou nod la sfarsitul listei
    void insertAtEnd(int value) {
        Node* p = new Node(); 
        p->data = value;      
        p->succ = NULL;       

        // Daca lista este goala, actualizam head cu noul nod
        if (!head) {
            head = p;
            return;
        }

        // Traversam lista pana la ultimul nod
        Node* temp = head;
        while (temp->succ) {
            temp = temp->succ;
        }

        // Actualizam pointerul ultimului nod catre noul nod
        temp->succ = p;
    }

    // Functie pentru inserarea unui nod la o anumita pozitie in lista
    void insertAtPosition(int value, int position) {
        if (position < 1) {
            cout << "Pozitia trebuie sa fie >= 1." << endl;
            return;
        }

        if (position == 1) {
            insertAtBeginning(value);
            return;
        }

        Node* p = new Node(); 
        p->data = value;     

        // Traversam lista pana la nodul dinaintea pozitiei dorite
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp; ++i) {
            temp = temp->succ;
        }

        // Daca pozitia este in afara intervalului valid, afisam un mesaj de eroare
        if (!temp) {
            cout << "Pozitie invalida." << endl;
            delete p;
            return;
        }

        // Inseram noul nod la pozitia dorita
        p->succ = temp->succ;
        temp->succ = p;
    }

    // Functie pentru stergerea primului nod din lista
    void deleteFromBeginning() {
        if (!head) {
            cout << "Lista este goala." << endl;
            return;
        }

        Node* temp = head; 
        head = head->succ; 
        delete temp;      
    }

    // Functie pentru stergerea ultimului nod din lista
    void deleteFromEnd() {
        if (!head) {
            cout << "Lista este goala." << endl;
            return;
        }

        if (!head->succ) {
            delete head;   
            head = NULL;   
            return;
        }

        // Traversam lista pana la penultimul nod
        Node* temp = head;
        while (temp->succ->succ) {
            temp = temp->succ;
        }
        
        // Stergem ultimul nod
        delete temp->succ; 
        // Setam pointerul penultimului nod la NULL
        temp->succ = NULL; 
    }

    // Functie pentru stergerea unui nod de la o anumita pozitie in lista
    void deleteFromPosition(int position) {
        if (position < 1) {
            cout << "Pozitia trebuie sa fie >= 1." << endl;
            return;
        }

        if (position == 1) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp; ++i) {
            temp = temp->succ;
        }

        if (!temp || !temp->succ) {
            cout << "Pozitie invalida." << endl;
            return;
        }

        // Salvam nodul care trebuie sters
        Node* nodeToDelete = temp->succ; 
        // Actualizam pointerul nodului anterior
        temp->succ = temp->succ->succ;   
        // Stergem nodul
        delete nodeToDelete;            
    }

    // Functie pentru afisarea nodurilor din lista inlantuita
    void display() {
        if (!head) {
            cout << "Lista este goala." << endl;
            return;
        }

        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> "; 
            temp = temp->succ;
        }
        cout << "NULL" << endl; 
    }
};

int main() {
    // Initializam o lista inlantuita noua
    LinkedList list1;

    // Inseram elemente la sfarsit
    list1.insertAtEnd(10);
    list1.insertAtEnd(20);

    // Inseram un element la inceput
    list1.insertAtBeginning(5);

    // Inseram un element la o anumita pozitie
    list1.insertAtPosition(15, 3);

    cout << "Lista inlantuita dupa insertii: ";
    list1.display();

    // Stergem un element de la inceput
    list1.deleteFromBeginning();
    cout << "Lista inlantuita dupa stergerea primului element: ";
    list1.display();

    // Stergem un element de la sfarsit
    list1.deleteFromEnd();
    cout << "Lista inlantuita dupa stergerea ultimului element: ";
    list1.display();

    // Stergem un element de la o anumita pozitie
    list1.deleteFromPosition(2);
    cout << "Lista inlantuita dupa stergerea elementului de la pozitia 2: ";
    list1.display();

    return 0;
}

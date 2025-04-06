void init(Coada& c) {
    c.front = c.rear = nullptr;
}

void enqueue(Coada& c, int val) {
    Nod* temp = new Nod;
    temp->data = val;
    temp->next = nullptr;

    if (isEmpty(c)) {
        c.front = c.rear = temp;
    } else {
        c.rear->next = temp;
        c.rear = temp;
    }
}

void dequeue(Coada& c) {
    if (isEmpty(c)) return;

    Nod* temp = c.front;
    c.front = c.front->next;
    delete temp;

    if (c.front == nullptr)
        c.rear = nullptr;
}

int peek(Coada c) {
    if (isEmpty(c)) return -1;
    return c.front->data;
}

bool isEmpty(Coada c) {
    return c.front == nullptr;
}

void destroyQueue(Coada& c) {
    Nod* p = c.front;
    while (p != nullptr) {
        Nod* temp = p;
        p = p->next;
        delete temp;
    }
    c.front = c.rear = nullptr;
}

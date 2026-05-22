#include <iostream>
#include <string>

using namespace std;

struct Node {
    string move;
    Node* prev;
    Node* next;
    Node(const string& m) : move(m), prev(nullptr), next(nullptr) {}
};

void append(Node*& head, Node*& tail, const string& move) {
    Node* newNode = new Node(move);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}


void hanoi(int n, char from, char to, char aux, Node*& head, Node*& tail) {
    if (n == 1) {
        string move = "Move disk 1 from " + string(1, from) + " to " + string(1, to);
        append(head, tail, move);
        return;
    }
    hanoi(n - 1, from, aux, to, head, tail);
    string move = "Move disk " + to_string(n) + " from " + string(1, from) + " to " + string(1, to);
    append(head, tail, move);
    hanoi(n - 1, aux, to, from, head, tail);
}

void printList(Node* head) {
    Node* current = head;
    int step = 1;
    while (current) {
        cout << step++ << ". " << current->move << endl;
        current = current->next;
    }
}


void freeList(Node* head) {
    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main() {
    const int DISKS = 3;
    Node* head = nullptr;
    Node* tail = nullptr;

    cout << "Tower of Hanoi solution for " << DISKS << " disks:\n";
    hanoi(DISKS, 'A', 'C', 'B', head, tail);
    printList(head);
    freeList(head);

    return 0;
}

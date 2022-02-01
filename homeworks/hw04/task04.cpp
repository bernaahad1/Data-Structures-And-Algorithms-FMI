#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) :data(data), next(nullptr), prev(nullptr) {

    }
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;
    Node* mid;
    int size;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        mid = nullptr;
        size = 0;
    }
    void updateMiddle(bool added) {
        if (size == 0) {
            mid = nullptr;
        }
        else if (size == 1) {
            mid = head;
        }
        else {
            if (added && size % 2 == 0) {
                mid = mid->next;
            }
            else if ((!added) && size % 2 != 0) {
                mid = mid->prev;
            }
        }
    }
    void addNode(int data) {
        Node* node = new Node(data);
        if (head == nullptr) {
            head = node;
        }
        else {
            tail->next = node;
            node->prev = tail;
        }
        tail = node;
        size++;
        updateMiddle(true);
    }

    void deleteLastNode() {
        Node* current = tail;
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        size--;
        updateMiddle(false);
        delete current;
    }

    void printList() {
        Node* temp = this->head;

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    void freeList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            size = 0;
            delete temp;
        }
    }

};

DoublyLinkedList* actionMilen(DoublyLinkedList* list) {
    if (list->size == 1) {
        return list;
    }
    Node* newMiddle = nullptr;
    if (list->size % 2 == 0) {
        newMiddle = list->head;
    }
    else {
        newMiddle = list->tail;
    }
    list->tail->next = list->head;
    list->head->prev = list->tail;
    list->tail = list->mid->prev;
    list->tail->next = nullptr;
    list->mid->prev = nullptr;
    list->head = list->mid;
    list->mid = newMiddle;
    return list;
}

int main() {
    const string add = "add";
    const string gun = "gun";
    const string milen = "milen";
    DoublyLinkedList* list = new DoublyLinkedList();
    int size;
    cin >> size;

    for (int i = 0; i < size; i++) {
        string input;
        cin >> input;
        if (input == add) {
            int num;
            cin >> num;
            list->addNode(num);
        }
        else if (input == gun) {
            list->deleteLastNode();
        }
        else {
            list = actionMilen(list);

        }
    }
    cout << list->size << endl;
    list->printList();
    list->freeList();
    return 0;
}


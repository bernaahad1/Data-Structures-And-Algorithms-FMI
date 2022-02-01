#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data = 0;
    Node* next = nullptr;

    Node(int data = 0, Node* next = nullptr):
        data(data), next(next) {
    }
};

class SinglyLinkedList {
public:
    Node* head = nullptr;
    Node* tail = nullptr;

    void freeList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }

        head = nullptr;
        tail = nullptr;
    }

    void push_front(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        if (tail == nullptr) {
            tail = head;
        }
    }

    void push_back(int number) {
        Node* node = new Node(number);
        if (head == nullptr) {
            head = node;
            tail = head;
        }
        else {
            tail->next = node;
            tail = tail->next;
        }
    }

    void pop_front() {
        if (head == nullptr) {
            throw out_of_range("Invalid");
        }
        Node* old = head;
        if (tail == head) {
            tail = nullptr;
        }
        head = head->next;
        delete old;

    }

    void pop_back() {
        if (head == nullptr) {
            throw out_of_range("Invalid");

        }

        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }

        Node* left = head;
        while (left->next != nullptr && left->next != tail) {
            left = left->next;
        }

        delete left->next;
        left->next = nullptr;
        tail = left;

    }

};


long long int sumOfMinEl(long long int arr[], int size, int k)
{
    SinglyLinkedList* smallestEl = new SinglyLinkedList;
    long long int sum = 0;
    int i = 0;
    while (i < k)
    {
        while ((smallestEl->head != nullptr) && arr[smallestEl->tail->data] >= arr[i]) {
            smallestEl->pop_back();
        }
        smallestEl->push_back(i);
        i++;
    }
    while (i < size)
    {
        sum += arr[smallestEl->head->data];

        while ((smallestEl->head != nullptr) && smallestEl->head->data <= i - k) {
            smallestEl->pop_front();
        }
        while ((smallestEl->head != nullptr) && arr[smallestEl->tail->data] >= arr[i]) {
            smallestEl->pop_back(); 
        }
      
        smallestEl->push_back(i);
        i++;
    }

    sum += arr[smallestEl->head->data];
    return sum;
}

int main()
{
    int size;
    int k;
    cin >> size;
    cin >> k;
    long long int* arr = new long long int[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cout << sumOfMinEl(arr, size, k);
    delete[] arr;

    return 0;
}
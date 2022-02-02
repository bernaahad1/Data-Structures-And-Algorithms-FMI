#include <bits/stdc++.h>
using namespace std;


struct Node {
    Node *next;
    int data;
};


class LinkedList{
    public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    ~LinkedList(){
        Node* temp;
        while(head != nullptr){
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    void add(int value){
        Node* temp = new Node;
        temp->data = value;
        temp->next = nullptr;
        
        if (head == nullptr and tail == nullptr){
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    void print(){
        Node* curr = head;
        while(curr != nullptr){
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
    vector<int> findNum(){
    vector<int> num;
    if(head==nullptr){
        return num;
    }
    
    Node* curr=head;
    while(curr!=nullptr){
        num.push_back(curr->data);
        curr=curr->next;
    }
    return num;
    }
private:
    Node *head, *tail;
};

void solve(LinkedList& num1, LinkedList& num2){
    vector<int> reversedNum1=num1.findNum();
    vector<int> reversedNum2=num2.findNum();
    int size1=reversedNum1.size();
    int size2=reversedNum2.size();
    vector<int> result;
    int size;
    if(size1>size2){
       size=size1;
    }
    else{
        size=size2;
    }
    int ost=0;
    for(int i=0;i<size;i++){
        if(i<size1 && i<size2){
            int num=reversedNum1[i]+reversedNum2[i]+ost;
            if(num>9){
                ost=num/10;
                num=num%10;
                result.push_back(num);
            }
            else{
                result.push_back(num);
                ost=0;
            }
          
        }
        else if(i>=size1){
            int num=reversedNum2[i]+ost;
            if(num>9){
                ost=num/10;
                num=num%10;
                result.push_back(num);
            }
            else{
                result.push_back(num);
                ost=0;
            }

        }
        else if(i>=size2){
             int num=reversedNum1[i]+ost;
            if(num>9){
                ost=num/10;
                num=num%10;
                result.push_back(num);
            }
            else{
                result.push_back(num);
                ost=0;
            }

        }
    }
    
    while(ost>0){
        result.push_back(ost%10);
        ost=ost/10;
        size++;
    }
    
    for(int i=size-1;i>=0;i--){
        cout<<result[i];
    }
    
}

int main(){
    LinkedList num1, num2;

    int size1, size2;
    cin >> size1;
    for(int i = 0 ; i < size1 ; i++){
        int digit;
        cin >> digit;
        num1.add(digit);
    }
    
    cin >> size2;
    for(int i = 0 ; i < size2 ; i++){
        int digit;
        cin >> digit;
        num2.add(digit);
    }
  
    solve(num1, num2);
}
/*
 * Complete the 'deleteNode' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER position
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
    SinglyLinkedListNode* current = llist;
    SinglyLinkedListNode* prev = nullptr;
    
    if(position == 0){
        if(llist->next != nullptr){
            llist = llist->next;
            delete current;
            return llist;
        }
        else{
            delete current;
            llist = nullptr;
            return llist;
        }
        
    }
    int i=0;
    while(i < position - 1){
        if(current->next!=nullptr){
          current = current->next;
          i++;
        }
        else{
            throw out_of_range("Invalid index");
        }
    }
    prev = current;
    current = current->next;
    prev->next = current->next;
    delete current;
    
    
    return llist;
    
}
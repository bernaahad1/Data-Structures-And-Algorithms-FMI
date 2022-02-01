// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int getSize(SinglyLinkedListNode* head){
    SinglyLinkedListNode* current = head;
    int size = 0;
 
    while (current != nullptr) {
        size++;
        current = current->next;
    }
 
    return size;
}

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* list1 = head1;
    SinglyLinkedListNode* list2 = head2;

    int size1 = getSize(head1);
    int size2 = getSize(head2);
    
    if(size1 > size2){
        int start = size1 - size2;
        while(start > 0){
            list1 = list1->next;
            start--;
        }
    }
    else if (size2 > size1){
        int start = size2 - size1;
        while(start > 0){
            list2 = list2->next;
            start--;
        }
    }

    while (list1->next != nullptr) {
        while (list2->next != nullptr) {
            if (list1->next == list2->next) {
                list1 = list1->next;
                list2 = list2->next;

                return list1->data;
            }
            list2 = list2->next;
        }
        list1 = list1->next;
        list2 = head2;

    }
    
    return list2->data;
}
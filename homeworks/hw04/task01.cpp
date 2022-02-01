/*
 * Complete the 'insertNodeAtPosition' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER data
 *  3. INTEGER position
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

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* newList = new SinglyLinkedListNode(data);
    if (position == 0) {
        newList->next = llist;
        return newList;
    }
    else if (llist->next == nullptr) {
        throw out_of_range("Invalid index");
    }
    SinglyLinkedListNode* current = llist;
    SinglyLinkedListNode* previous = nullptr;
    for (int i = 1; i <= position; i++) {
        if (current != nullptr) {
            previous = current;
            current = current->next;
        }
        else {
            throw out_of_range("Invalid index");
        }
    }
    previous->next = newList;
    newList->next = current;
    return llist;
}
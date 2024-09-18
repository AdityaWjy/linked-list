// import library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisi struktur Node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to show linked list
void showList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to create a new node
Node* createNode(int data, Node* next) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = next;
    return newNode;
}

// Function to insert the first node
void insertFirstNode(Node** head, int value) {
    Node* newNode = createNode(value, *head);
    *head = newNode;
}

// Function to insert a node at the end of the list
void insertLastNode(Node** head, int value) {
    Node* newNode = createNode(value, NULL);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* tail = *head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = newNode;
    }
}

// free alocate memory with free function
 void freeNode(Node *p)
 {
     free(p);
     p = NULL;
 }

 // function delete first
void deleteFirstNode(Node** head) {

    if(*head == NULL) {
        return; // nothing to delete if list is empty
    }

    Node* delete = *head;
    *head = delete -> next;
    freeNode(delete);
}

// Function to remove the last node of the linked list
struct Node* deleteLastNode(struct Node* head)
{
    if (head == NULL)
        return NULL;

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    // Find the second last node
    struct Node* second_last = head;
    while (second_last->next->next != NULL)
        second_last = second_last->next;

    // Delete last node
    free(second_last->next);

    // Change next of second last
    second_last->next = NULL;

    return head;
}

int main() {
    // Create linked list
    Node* n3 = createNode(30, NULL);
    Node* n2 = createNode(20, n3);
    Node* headOfList = createNode(10, n2);  // Set headOfList to the start of the list

    printf("Linked List:\n");
    showList(headOfList);

    // Insert at the beginning
    insertFirstNode(&headOfList, 200);
    printf("Linked List after Insert First:\n");
    showList(headOfList);
    
    // Insert at the end
    insertLastNode(&headOfList, 100);
    printf("Linked List after Insert Last:\n");
    showList(headOfList);

    // Delete first node from linked list
    deleteFirstNode(&headOfList);
    printf("Linked List after deletion first node:\n");
    showList(headOfList);

    // Delete last node from linked list
    deleteLastNode(headOfList);
    printf("Linked List after deletion last node:\n");
    showList(headOfList);
    
    // Clean up remaining nodes
    Node* current = headOfList;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        freeNode(current);
        current = nextNode;
    }
    return 0;
}


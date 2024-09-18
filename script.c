#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
1. Print linked list
    a. Program / source code
    b. screenshot output
    c. analisis code

2. Sisip awal Linked List
    a. Program / Source code
    b. screenshot output
    c. Analisis code
3. Hapus awal linked list
    a. program / source code
    b. screenshot output
    c. Analisis code
*/


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

// C++ Function to remove the last node of the linked list
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

// Main function
int main() {
    // Create linked list
    Node* headOfList = createNode(10, NULL);
    headOfList = createNode(20, headOfList);
    headOfList = createNode(30, headOfList);  // headOfList now points to 30 -> 20 -> 10 -> NULL

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
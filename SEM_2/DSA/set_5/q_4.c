#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

void insertNode(Node** head, int value);
void displayList(Node* head);
void bubbleSort(Node* head);
void insertionSort(Node** head);
void selectionSort(Node* head);


int main() {
    Node* head = NULL;
    int choice, value;

    while(1) {
        printf("\n1. Insert an element\n");
        printf("2. Bubble Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Selection Sort\n");
        printf("5. Display the list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertNode(&head, value);
                printf("Element inserted successfully.\n");
                break;
            case 2:
                bubbleSort(head);
                printf("List sorted using Bubble Sort (interchanging links).\n");
                break;
            case 3:
                insertionSort(&head);
                printf("List sorted using Insertion Sort (interchanging links).\n");
                break;
            case 4:
                selectionSort(head);
                printf("List sorted using Selection Sort.\n");
                break;
            case 5:
                printf("List: ");
                displayList(head);
                break;
            case 6:
                return 0;
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    };

    return 0;
}

void insertNode(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayList(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void bubbleSort(Node* head) {
    int swapped;
    Node* temp;
    Node* lastNode = NULL;

    if (head == NULL) {
        return;
    }

    do {
        swapped = 0;
        temp = head;

        while (temp->next != lastNode) {
            if (temp->data > temp->next->data) {
                int tempData = temp->data;
                temp->data = temp->next->data;
                temp->next->data = tempData;

                // Interchange links
                Node* nextNode = temp->next;
                temp->next = temp->next->next;
                nextNode->next = temp;

                swapped = 1;
            }
            temp = temp->next;
        }
        lastNode = temp;
    } while (swapped);
}

void insertionSort(Node** head) {
    Node* sorted = NULL;
    Node* current = *head;

    while (current != NULL) {
        Node* nextNode = current->next;
        Node** sortedRef = &sorted;

        while (*sortedRef != NULL && (*sortedRef)->data < current->data) {
            sortedRef = &(*sortedRef)->next;
        }

        current->next = *sortedRef;
        *sortedRef = current;
        current = nextNode;
    }

    *head = sorted;
}

void selectionSort(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        Node* minNode = temp;
        Node* node = temp->next;

        while (node != NULL) {
            if (node->data < minNode->data) {
                minNode = node;
            }
            node = node->next;
        }

        int tempData = temp->data;
        temp->data = minNode->data;
        minNode->data = tempData;

        temp = temp->next;
    }
}
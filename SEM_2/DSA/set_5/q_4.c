#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertNode(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayList(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void bubbleSort(struct Node* head) {
    int swapped;
    struct Node* temp;
    struct Node* lastNode = NULL;

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
                struct Node* nextNode = temp->next;
                temp->next = temp->next->next;
                nextNode->next = temp;

                swapped = 1;
            }
            temp = temp->next;
        }
        lastNode = temp;
    } while (swapped);
}

void insertionSort(struct Node** head) {
    struct Node* sorted = NULL;
    struct Node* current = *head;

    while (current != NULL) {
        struct Node* nextNode = current->next;
        struct Node** sortedRef = &sorted;

        while (*sortedRef != NULL && (*sortedRef)->data < current->data) {
            sortedRef = &(*sortedRef)->next;
        }

        current->next = *sortedRef;
        *sortedRef = current;
        current = nextNode;
    }

    *head = sorted;
}

void selectionSort(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        struct Node* minNode = temp;
        struct Node* node = temp->next;

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

void deleteList(struct Node** head) {
    struct Node* current = *head;
    struct Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    *head = NULL;
}

int main() {
    struct Node* head = NULL;
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Insert an element\n");
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
                deleteList(&head);
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 6);

    return 0;
}
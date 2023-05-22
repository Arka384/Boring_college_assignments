#include <stdio.h>
#include <limits.h>
#define MAX 10

typedef struct item {
    int data;
    int priority;
}item;
item p_queue[MAX] = {0};
int g_size = -1;

void insert(int data, int priority);
int delete(void);

int main()
{
    int choice, data, p, x;
    while(1) {
		printf("\n1 -> insert, ");
		printf("2 -> delete, ");
		printf("3 -> Exit, ");
		printf("\nEnter choice: ");
		scanf("%d", &choice);

		switch(choice) {
		case 1:
            if(g_size == MAX - 1) {
                printf("\nOverflow");
                break;
            }
			printf("\nEnter data to insert: ");
			scanf("%d", &data);
            printf("\nEnter priotity of data: ");
			scanf("%d", &p);
			insert(data, p);
			break;
		case 2:
            x = delete();
            if(x != -1)
			    printf("\nPopped data is %d", x);
            else
                printf("\nUnderflow");
			break;
		case 3:
			return 0;
		default:
			printf("\nWrong choice");
		}
	}

	return 0;

}

void insert(int data, int priority) {
    item i;
    g_size++;
    i.data = data;
    i.priority = priority;
    p_queue[g_size] = i;
}

int delete() {
    if(g_size == -1)
        return -1;
    int maxPriority = INT_MAX;
    item e;
    int index = -1;

    for(int i = 0; i <= g_size; i++) {
        if(p_queue[i].priority < maxPriority) {
            maxPriority = p_queue[i].priority;
            e = p_queue[i];
            index = i;
        }
        else if(p_queue[i].priority == maxPriority) {
            e = (p_queue[i].data > e.data) ? p_queue[i] : e;
            index = i;
        }
    }
    for(int i=index; i < g_size; i++)
        p_queue[i] = p_queue[i + 1];
    g_size--;
    return e.data;
}
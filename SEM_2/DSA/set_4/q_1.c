#include <stdio.h>
#include <malloc.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
}node;

node* getnode(void);
void createTree(node** root);
node** search(node** root, int value);
void inorder(node* root);
void preorder(node* root);
void postorder(node* root);

int main()
{
    node* binaryTree = NULL;
    int choice = 0;
    do {
		printf("\n0 -> exit\n1 -> create\n2 -> preorder\n3 -> inorder traversal\n4 -> postorder\nEnter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
				return 0;
				break;
			case 1:
				printf("Creating Binary tree\n");
                createTree(&binaryTree);
				break;
			case 2:
				if(binaryTree == NULL) { printf("Nothing in tree\n"); continue; }
                preorder(binaryTree);
				break;
			case 3:
				if(binaryTree == NULL) { printf("Nothing in tree\n"); continue; }
                inorder(binaryTree);
				break;
			case 4:
				if(binaryTree == NULL) { printf("Nothing in tree\n"); continue; }
                postorder(binaryTree);
				break;
			default:
				printf("Enter valid option between 0 to 4\n");
				break;
		}
	} while(choice!=0);
}

void createTree(node** root) {
    int d = 0, choice = 0;
    node* t = getnode();
    printf("\nEnter root node data: ");
    scanf("%d", &d);
    t->data = d;
    *root = t;
    do {
        node** x;
        printf("1->add left child\n2->add right child\n3->end\nEnter choice: ");
        scanf("%d", &choice);
        if(choice == 1 || choice == 2) {
            printf("Enter desired node data: ");
            scanf("%d", &d);
            x = search(root, d);
            if(x == NULL) {
                printf("Value not found\n");
                continue;
            }
            if(choice == 1 && (*x)->left != NULL) {
                printf("Node already exists there\n");
                continue;
            }
            if(choice == 2 && (*x)->right != NULL) {
                printf("Node already exists there\n");
                continue;
            }
            node* temp = getnode();
            printf("\nEnter new node data: ");
            scanf("%d", &d);
            temp->data = d;
            if(choice == 1)
                (*x)->left = temp;
            else (*x)->right = temp;
        }
        if(choice == 3)
            return;
    } while(1);
}

node** search(node** root, int value) {
    if(*root == NULL)
        return NULL;
    if((*root)->data == value)
        return root;
    node** t1 = search(&(*root)->left, value);
    if(t1 != NULL && (*t1)->data == value)
        return t1;
    node** t2 = search(&(*root)->right, value);
    return t2;
}

void inorder(node* root) {
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(node* root) {
    if(root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

node* getnode() {
    node* t = (node*)malloc(sizeof(node));
    if(t == NULL) {
        printf("Overflow error");
        return NULL;
    }
    t->left = NULL;
    t->right = NULL;
    return t;
}

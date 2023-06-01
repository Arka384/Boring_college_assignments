#include <stdio.h>
#include <malloc.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
}node;

node* getnode(void);
node* createTree(void);
void inorder(node* root);
node* search(node* root, node** parent, int value);
node* insertnode(node* root, int value);
node* deletenode(node* root, int value);

int main()
{
    node* bst = NULL;
    node* temp = NULL, *parent = NULL;

    int choice = 0, key = 0;
    while(1) {
		printf("\n0 -> create BST\n1 -> insert\n2 -> delete\n3 -> search\n4 -> inorder traversal\n5 -> exit\nEnter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
				bst = createTree();
				break;
			case 1:
                if(bst == NULL) { printf("Create tree first\n"); continue; }
				printf("\nEnter new node data: ");
                scanf("%d", &key);
                bst = insertnode(bst, key);
				break;
			case 2:
                if(bst == NULL) { printf("Create tree first\n"); continue; }
				printf("\nEnter data to delete: ");
                scanf("%d", &key);
                bst = deletenode(bst, key);
				break;
			case 3:
                if(bst == NULL) { printf("Create tree first\n"); continue; }
				printf("\nEnter data to search: ");
                scanf("%d", &key);
                temp = search(bst, &parent, key);
                if(temp == NULL) printf("Value NOT found\n");
                else printf("Value found\n");
				break;
			case 4:
				if(bst == NULL) { printf("Nothing in tree\n"); continue; }
                inorder(bst);
				break;
            case 5:
                return 0;
			default:
				printf("Enter valid option between 0 to 4\n");
				break;
		}
	}
    return 0;
}

node* search(node* root, node** parent, int value) {
    while(root != NULL) {
        if(root->data == value)
            break;
        *parent = root;
        if(value < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

node* insertnode(node* root, int value) {
    if(root == NULL) {
        node* temp = getnode();
        temp->data = value;
        root = temp;
    }
    else if(value < root->data)
        root->left = insertnode(root->left, value);
    else if(value > root->data)
        root->right = insertnode(root->right, value);
    else
        printf("node already exists\n");
    return root;
}

node* deletenode(node* root, int value) {
    node* t = root;
    node* parent = NULL, *inSucc = NULL, *parSucc = NULL, *tempChild = NULL;
    t = search(root, &parent, value);
    if(t == NULL) {
        printf("Given node not found\n");
        return root;
    }

    //if the node is found then there are 3 cases
    //first case : the node have 2 children, then find inorder successor
    if(t->left != NULL && t->right != NULL) {
        parSucc = t;
        inSucc = t->right;
        while(inSucc->left != NULL) {
            parSucc = inSucc;
            inSucc = inSucc->left;
        }
        t->data = inSucc->data;
        t = inSucc;
        parent = parSucc;
        //now run case 2 or case 3 accordingly
    }
    if(t->left != NULL)   //case 2 only left child present
        tempChild = t->left;
    else    //case 3 only right child present
        tempChild = t->right;

    if(parent == NULL)
        root = tempChild;
    else if(parent->left == t)
        parent->left = tempChild;
    else
        parent->right = tempChild;
    
    printf("Data deleted\n");
    free(t);
    return root;
}

node* createTree() {
    printf("\nCreating tree\n");
    node* t = getnode();
    printf("Enter root node data\n");
    scanf("%d", &t->data);
    return t;
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

void inorder(node* root) {
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

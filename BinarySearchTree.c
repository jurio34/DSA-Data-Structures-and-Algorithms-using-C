#include <stdio.h>
#include <stdlib.h>

typedef struct Bstnode {
    int data;
    struct Bstnode *left;
    struct Bstnode *right;
}Bstnode;
Bstnode* findMin(Bstnode *root) {
    if (root == NULL) {
        return NULL;
    } else {
        while (root->left != NULL) {
            root = root->left;
        }
        return root;
    }
}
void insertNode(Bstnode **root, int data) {
    if (*root == NULL) {
        *root = (Bstnode *)malloc(sizeof(Bstnode));
        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
        return;
    }else {
        if (data < (*root)->data) {
            insertNode(&((*root)->left), data);
        } else if (data > (*root)->data) {
            insertNode(&((*root)->right), data);
        } else {
            printf("duplicate.");
        }
    }
}
Bstnode* deleteNode(Bstnode *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
       root->right = deleteNode(root->right, data);
    }else{
        //caso nó folha:
        if (root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        // caso 1 filho direita:
        }else if (root->left == NULL) {
            Bstnode *temp = root->right;
            free(root);
            return temp;
        //caso 1 filho esquerda:
        } else if (root->right == NULL) {
            Bstnode *temp = root->left;
            free(root);
            return temp;
        //caso 2 filhos:
        } else {
            // nó substituto é o menor elemento da subárvore da direita
            Bstnode *temp = findMin(root->right);
            //atribui o valor do nó a ser deletado ao nó substituto
            root->data = temp->data;
            //deleta o nó
            root->right = deleteNode(root->right, temp->data);
            }
        }
    return root;
    }
void preOrder(Bstnode *root) {
    if (root != NULL) {
        printf("%3d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(Bstnode *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%3d ", root->data);
        inOrder(root->right);
    }
}
void postOrder(Bstnode *root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%3d ", root->data);
    }
}
int main() {
    Bstnode *root = NULL;
    int choice;
    int value;
    int valueTobeDeleted;
    printf("Choose an option to manipulate the BST: (1- Insert a node, 2- Delete a node, 3- Exit)");
    scanf("%d", &choice);
    while (choice != 3) {
        switch (choice) {
            case 1:
                printf("Insert a node: ");
                scanf("%d", &value);
                insertNode(&root, value);
                break;
            case 2:
                printf("Delete a node: ");
                scanf("%d", &valueTobeDeleted);
                root = deleteNode(root, valueTobeDeleted);
                break;
            default:
                printf("Wrong choice. Try again.");
                break;
        }
        printf("\nChoose an option (1- Insert, 2- Delete, 3- Exit): ");
        scanf("%d", &choice);
    }
    printf("The pre order traversal of the BST is: ");
    preOrder(root);
    printf("\n");
    printf("The in-order traversal of the BST is: ");
    inOrder(root);
    printf("\n");
    printf("The post order traversal of the BST is: ");
    postOrder(root);
    printf("\n");
    return 0;
}
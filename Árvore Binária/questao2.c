#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

void printTree(struct Node* root) {
    if (root == NULL)
        return;
    printf("%d", root->data);
    if (root->left != NULL || root->right != NULL) {
        printf("(");
        if (root->left != NULL)
            printTree(root->left);
        printf(" ");
        if (root->right != NULL)
            printTree(root->right);
        printf(")");
    }
}

void printRightSubtree(struct Node* root) {
    if (root == NULL)
        return;
    printTree(root->right);
}

void printLeftSubtree(struct Node* root) {
    if (root == NULL)
        return;
    printTree(root->left);
}

void printParentAndChildren(struct Node* root, int target) {
    if (root == NULL)
        return;
    if ((root->left && root->left->data == target) || (root->right && root->right->data == target)) {
        printf("Parent: %d\n", root->data);
        if (root->left)
            printf("Left Child: %d\n", root->left->data);
        if (root->right)
            printf("Right Child: %d\n", root->right->data);
        return;
    }
    printParentAndChildren(root->left, target);
    printParentAndChildren(root->right, target);
}

void printMenu() {
    printf("\nMenu\n");
    printf("1 - Inserir numero\n");
    printf("2 - Mostrar todos\n");
    printf("3 - Mostrar a subarvore da direita\n");
    printf("4 - Mostrar a subarvore da esquerda\n");
    printf("5 - Mostrar o no pai e os nos filhos de um no\n");
    printf("6 - Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    struct Node* root = NULL;
    int choice, data, target;

    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o numero para inserir: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Representacao da arvore: ");
                printTree(root);
                printf("\n");
                break;
            case 3:
                printf("Subarvore da direita: ");
                printRightSubtree(root);
                printf("\n");
                break;
            case 4:
                printf("Subarvore da esquerda: ");
                printLeftSubtree(root);
                printf("\n");
                break;
            case 5:
                printf("Digite o no alvo: ");
                scanf("%d", &target);
                printf("Nó pai e nós filhos de %d:\n", target);
                printParentAndChildren(root, target);
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (choice != 6);

    return 0;
}

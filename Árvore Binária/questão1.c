#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da árvore
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Função para criar um novo nó com um dado específico
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Aloca memória
    newNode->data = data; // Define o dado do novo nó
    newNode->left = newNode->right = NULL;   // Inicializa os ponteiros esquerdo e direito como NULL
    return newNode; // Retorna o novo nó criado
}

// Função para inserir um novo nó na árvore
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) // Se a raiz for NULL, cria um novo nó e o torna a raiz
        return createNode(data);
    if (data < root->data) // Se o dado for menor que o dado da raiz, insere à esquerda
        root->left = insert(root->left, data);
    else if (data > root->data) // Se o dado for maior que o dado da raiz, insere à direita
        root->right = insert(root->right, data);
    return root; // Retorna a raiz atualizada da árvore
}

// Função para imprimir os nós folha da árvore
void printLeafNodes(struct Node* root) {
    if (root == NULL) // Se a raiz for NULL, retorna
        return;
    if (root->left == NULL && root->right == NULL) // Se a raiz for uma folha, imprime o dado
        printf("%d ", root->data);
    printLeafNodes(root->left); // Chama recursivamente para o filho esquerdo
    printLeafNodes(root->right); // Chama recursivamente para o filho direito
}

// Função auxiliar para encontrar os ancestrais de um nó e imprimi-los
int isAncestor(struct Node* root, int target) {
    if (root == NULL) // Se a raiz for NULL, retorna 0
        return 0;
    if (root->data == target || isAncestor(root->left, target) || isAncestor(root->right, target)) {
        // Se o nó atual for o nó alvo ou se o nó alvo for encontrado nos filhos esquerdo ou direito,
        // imprime o dado do nó atual e retorna 1
        printf("%d ", root->data);
        return 1;
    }
    return 0; // Retorna 0 se o nó alvo não for encontrado
}

// Função auxiliar para encontrar os descendentes de um nó e imprimi-los
void printDescendants(struct Node* root, int target) {
    if (root == NULL) // Se a raiz for NULL, retorna
        return;
    if (root->data == target) { // Se o nó atual for o nó alvo, imprime o dado
        printf("%d ", root->data);
        return;
    }
    printDescendants(root->left, target); // Chama recursivamente para o filho esquerdo
    printDescendants(root->right, target); // Chama recursivamente para o filho direito
}

// Função para imprimir o nó pai e os nós filhos de um nó específico
void printParentAndChildren(struct Node* root, int target) {
    if (root == NULL) // Se a raiz for NULL, retorna
        return;
    if ((root->left && root->left->data == target) || (root->right && root->right->data == target)) {
        // Se o nó atual tiver um filho esquerdo ou direito com o dado igual ao dado do nó alvo,
        // imprime o nó atual como pai e seus filhos, se existirem
        printf("Parent: %d\n", root->data);
        if (root->left)
            printf("Left Child: %d\n", root->left->data);
        if (root->right)
            printf("Right Child: %d\n", root->right->data);
        return;
    }
    printParentAndChildren(root->left, target); // Chama recursivamente para o filho esquerdo
    printParentAndChildren(root->right, target); // Chama recursivamente para o filho direito
}

// Função para exibir o menu de opções
void printMenu() {
    printf("\nMenu\n");
    printf("1- Inserir numero\n");
    printf("2- Mostrar os nos das folhas\n");
    printf("3- Mostrar os nos ancestrais de um no\n");
    printf("4- Mostrar os nos descendentes de um no\n");
    printf("5- Mostrar o no pai e os nos filhos de um np\n");
    printf("6- Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    struct Node* root = NULL; // Inicializa a raiz da árvore como NULL
    int choice, data, target; // Variáveis para armazenar a escolha do usuário, o dado a ser inserido e o alvo para operações específicas

    // Loop principal para exibir o menu e executar as operações escolhidas pelo usuário
    do {
        printMenu(); // Exibe o menu de opções
        scanf("%d", &choice); // Lê a escolha do usuário

        switch (choice) {
            case 1:
                printf("Digite o numero para inserir: ");
                scanf("%d", &data);
                root = insert(root, data); // Insere um novo nó na árvore com o dado fornecido pelo usuário
                break;
            case 2:
                printf("Nos das folhas: ");
                printLeafNodes(root); // Imprime os nós folha da árvore
                printf("\n");
                break;
            case 3:
                printf("Digite o no alvo: ");
                scanf("%d", &target);
                printf("Nos ancestrais de %d: ", target);
                isAncestor(root, target); // Imprime os nós ancestrais do nó alvo fornecido pelo usuário
                printf("\n");
                break;
            case 4:
                printf("Digite o no alvo: ");
                scanf("%d", &target);
                printf("Nos descendentes de %d: ", target);
                printDescendants(root, target); // Imprime os nós descendentes do nó alvo fornecido pelo usuário
                printf("\n");
                break;
            case 5:
                printf("Digite o noo alvo: ");
                scanf("%d", &target);
                printf("No pai e nos filhos de %d:\n", target);
                printParentAndChildren(root, target); // Imprime o nó pai e os nós filhos do nó alvo fornecido pelo usuário
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (choice != 6); // O loop continua até que o usuário escolha a opção de sair

    return 0;
}

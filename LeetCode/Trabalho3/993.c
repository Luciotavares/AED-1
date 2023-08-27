// Função que encontra o pai de um nó com valor de destino
struct TreeNode* findParent(struct TreeNode* root, int target, struct TreeNode* parent) {
    if (root == NULL) {
        return NULL;
    }
    
    if (root->val == target) {
        return parent;
    }
    
    // Verifica se o nó de destino está na subárvore esquerda
    struct TreeNode* leftParent = findParent(root->left, target, root);
    if (leftParent != NULL) {
        return leftParent;
    }
    
    // Se não estiver na subárvore esquerda, verifica na subárvore direita
    return findParent(root->right, target, root);
}

// Função que encontra a profundidade de um nó com valor de destino
int findDepth(struct TreeNode* root, int target, int depth) {
    if (root == NULL) {
        return -1;
    }
    
    if (root->val == target) {
        return depth;
    }
    
    // Verifica se o nó de destino está na subárvore esquerda
    int leftDepth = findDepth(root->left, target, depth + 1);
    if (leftDepth != -1) {
        return leftDepth;
    }
    
    // Se não estiver na subárvore esquerda, verifica na subárvore direita
    return findDepth(root->right, target, depth + 1);
}

// Função principal para verificar se dois nós são primos
bool isCousins(struct TreeNode* root, int x, int y) {
    // Encontra os pais dos nós com valores x e y
    struct TreeNode* xParent = findParent(root, x, NULL);
    struct TreeNode* yParent = findParent(root, y, NULL);
    
    // Encontra as profundidades dos nós com valores x e y
    int xDepth = findDepth(root, x, 0);
    int yDepth = findDepth(root, y, 0);
    
    // Verifica se os nós são primos (mesma profundidade e pais diferentes)
    return xDepth == yDepth && xParent != yParent;
}

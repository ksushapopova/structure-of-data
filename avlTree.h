#pragma once


// ����������� ��������� ����
struct Node {
    int key; // ���� ����
    Node* left; // ����� �������
    Node* right; // ������ �������
    int height; // ������ ��������� � ������ � ���� ����
};

// ������� ��� ���������� ��������� �� ���� �����
int max(int a, int b) {
    return (a > b) ? a : b;
}

// ������� ��� ���������� ������ ��������� � ������ � ������ ����
int heightt(Node* node) {
    if (node == nullptr) {
        return 0; // ������ ������ ����� ������ 0
    }
    return node->height; // ���������� ������ ����
}

// ������� ��� �������� ������ ���� � �������� ������
Node* newNode(int key) {
    Node* node = new Node(); // �������� ������ ��� ����
    node->key = key; // ������������� ����
    node->left = nullptr; // ������������� ������ �������
    node->right = nullptr; // ������������� ������� �������
    node->height = 1; // ������������� ������
    return node; // ���������� ��������� �� ����
}

// ������� ��� ���������� ������� �������� ��������� � ������ � ������ ����
Node* rightRotate(Node* y) {
    Node* x = y->left; // ���������� ������ ������� y
    Node* T2 = x->right; // ���������� ������� ������� x

    // ��������� ��������
    x->right = y; // ������ �������� x ���������� y
    y->left = T2; // ����� �������� y ���������� T2

    // ��������� ������
    y->height = max(heightt(y->left), heightt(y->right)) + 1;
    x->height = max(heightt(x->left), heightt(x->right)) + 1;

    // ���������� ����� ������
    return x;
}

// ������� ��� ���������� ������ �������� ��������� � ������ � ������ ����
Node* leftRotate(Node* x) {
    Node* y = x->right; // ���������� ������� ������� x
    Node* T2 = y->left; // ���������� ������ ������� y

    // ��������� ��������
    y->left = x; // ����� �������� y ���������� x
    x->right = T2; // ������ �������� x ���������� T2

    // ��������� ������
    x->height = max(heightt(x->left), heightt(x->right)) + 1;
    y->height = max(heightt(y->left), heightt(y->right)) + 1;

    // ���������� ����� ������
    return y;
}

// ������� ��� ���������� ������� ����
int getBalance(Node* node) {
    if (node == nullptr) {
        return 0; // ������ ���� ����� ������ 0
    }
    return heightt(node->left) - heightt(node->right); // ������ ����� �������� ����� ������ � ������� �����������
}

// ������� ��� ������� ����� � AVL-������ � ������ � ������ ����
Node* insert(Node* node, int key) {
    // ��������� ������� ������� � �������� ������ ������
    if (node == nullptr) {
        return newNode(key); // ���� ���� ������, ������� ����� ���� � ������
    }

    if (key < node->key) {
        node->left = insert(node->left, key); // ���� ���� ������ ����� ����, ��������� � ����� ���������
    }
    else if (key > node->key) {
        node->right = insert(node->right, key); // ���� ���� ������ ����� ����, ��������� � ������ ���������
    }
    else {
        return node; // ���� ���� ����� ����� ����, ������ �� ������
    }

    // ��������� ������ ����
    node->height = max(heightt(node->left), heightt(node->right)) + 1;

    // �������� ������ ����
    int balance = getBalance(node);

    // ���� ���� ���������������, ��������� ���� �� ������� ��������

    // ������ 1: ����� �����
    if (balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }

    // ������ 2: ������ ������
    if (balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }

    // ������ 3: ����� ������
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // ������ 4: ������ �����
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // ���������� ������������ ����
    return node;
}


// ������� ��� ������ AVL-������ � �������
void printTree(Node* node, int level) {
    if (node == nullptr) {
        return; // ���� ���� ������, ������ �� �������
    }
    printTree(node->right, level + 1); // ������� ������ ��������� � ����������� �������
    for (int i = 0; i < level; i++) {
        std::cout << "    "; // ������� ������ � ����������� �� ������
    }
    std::cout << node->key << std::endl; // ������� ���� ����
    printTree(node->left, level + 1); // ������� ����� ��������� � ����������� �������
}




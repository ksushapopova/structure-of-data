#pragma once


// Определение структуры узла
struct Node {
    int key; // Ключ узла
    Node* left; // Левый потомок
    Node* right; // Правый потомок
    int height; // Высота поддерева с корнем в этом узле
};

// Функция для вычисления максимума из двух чисел
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Функция для вычисления высоты поддерева с корнем в данном узле
int heightt(Node* node) {
    if (node == nullptr) {
        return 0; // Пустое дерево имеет высоту 0
    }
    return node->height; // Возвращаем высоту узла
}

// Функция для создания нового узла с заданным ключом
Node* newNode(int key) {
    Node* node = new Node(); // Выделяем память для узла
    node->key = key; // Устанавливаем ключ
    node->left = nullptr; // Устанавливаем левого потомка
    node->right = nullptr; // Устанавливаем правого потомка
    node->height = 1; // Устанавливаем высоту
    return node; // Возвращаем указатель на узел
}

// Функция для выполнения правого вращения поддерева с корнем в данном узле
Node* rightRotate(Node* y) {
    Node* x = y->left; // Запоминаем левого потомка y
    Node* T2 = x->right; // Запоминаем правого потомка x

    // Выполняем вращение
    x->right = y; // Правым потомком x становится y
    y->left = T2; // Левым потомком y становится T2

    // Обновляем высоты
    y->height = max(heightt(y->left), heightt(y->right)) + 1;
    x->height = max(heightt(x->left), heightt(x->right)) + 1;

    // Возвращаем новый корень
    return x;
}

// Функция для выполнения левого вращения поддерева с корнем в данном узле
Node* leftRotate(Node* x) {
    Node* y = x->right; // Запоминаем правого потомка x
    Node* T2 = y->left; // Запоминаем левого потомка y

    // Выполняем вращение
    y->left = x; // Левым потомком y становится x
    x->right = T2; // Правым потомком x становится T2

    // Обновляем высоты
    x->height = max(heightt(x->left), heightt(x->right)) + 1;
    y->height = max(heightt(y->left), heightt(y->right)) + 1;

    // Возвращаем новый корень
    return y;
}

// Функция для вычисления баланса узла
int getBalance(Node* node) {
    if (node == nullptr) {
        return 0; // Пустой узел имеет баланс 0
    }
    return heightt(node->left) - heightt(node->right); // Баланс равен разности высот левого и правого поддеревьев
}

// Функция для вставки ключа в AVL-дерево с корнем в данном узле
Node* insert(Node* node, int key) {
    // Выполняем обычную вставку в бинарное дерево поиска
    if (node == nullptr) {
        return newNode(key); // Если узел пустой, создаем новый узел с ключом
    }

    if (key < node->key) {
        node->left = insert(node->left, key); // Если ключ меньше ключа узла, вставляем в левое поддерево
    }
    else if (key > node->key) {
        node->right = insert(node->right, key); // Если ключ больше ключа узла, вставляем в правое поддерево
    }
    else {
        return node; // Если ключ равен ключу узла, ничего не делаем
    }

    // Обновляем высоту узла
    node->height = max(heightt(node->left), heightt(node->right)) + 1;

    // Получаем баланс узла
    int balance = getBalance(node);

    // Если узел несбалансирован, выполняем одно из четырех вращений

    // Случай 1: Левый левый
    if (balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }

    // Случай 2: Правый правый
    if (balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }

    // Случай 3: Левый правый
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Случай 4: Правый левый
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Возвращаем неизмененный узел
    return node;
}


// Функция для вывода AVL-дерева в консоль
void printTree(Node* node, int level) {
    if (node == nullptr) {
        return; // Если узел пустой, ничего не выводим
    }
    printTree(node->right, level + 1); // Выводим правое поддерево с увеличенным уровнем
    for (int i = 0; i < level; i++) {
        std::cout << "    "; // Выводим отступ в зависимости от уровня
    }
    std::cout << node->key << std::endl; // Выводим ключ узла
    printTree(node->left, level + 1); // Выводим левое поддерево с увеличенным уровнем
}




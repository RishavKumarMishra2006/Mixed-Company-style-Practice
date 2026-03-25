#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 2

typedef struct Node {
    int key, value;
    struct Node *prev, *next;
} Node;

Node *head = NULL, *tail = NULL;

Node* createNode(int key, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->prev = node->next = NULL;
    return node;
}

void moveToFront(Node* node) {
    if (node == head) return;

    if (node == tail) tail = tail->prev;

    if (node->prev) node->prev->next = node->next;
    if (node->next) node->next->prev = node->prev;

    node->next = head;
    node->prev = NULL;
    head->prev = node;
    head = node;
}

void insertFront(Node* node) {
    if (!head) {
        head = tail = node;
        return;
    }
    node->next = head;
    head->prev = node;
    head = node;
}

void removeLast() {
    if (!tail) return;
    Node* temp = tail;
    if (head == tail) head = tail = NULL;
    else {
        tail = tail->prev;
        tail->next = NULL;
    }
    free(temp);
}

void put(int key, int value) {
    Node* temp = head;
    while (temp) {
        if (temp->key == key) {
            temp->value = value;
            moveToFront(temp);
            return;
        }
        temp = temp->next;
    }

    Node* node = createNode(key, value);
    insertFront(node);

    int count = 0;
    temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }

    if (count > CAPACITY) removeLast();
}

int get(int key) {
    Node* temp = head;
    while (temp) {
        if (temp->key == key) {
            moveToFront(temp);
            return temp->value;
        }
        temp = temp->next;
    }
    return -1;
}

#ifndef __LinkedList_H__
#define __LinkedList_H__

#include<stdlib.h>

struct Data{
    int id;
    char name[50];
    char email[50];
    char address[50];
};

typedef struct Data Data;

struct Node{
    Data data;
    struct Node* next;
};

typedef struct Node Node;

extern Node* head;

void showAllNode(Node* node);
Node* searchNode(Node* node, int id);
void appendNode(Node** node_ref, Data data);
void updateNode(Node** node_ref, int id, Data data);
void deleteNode(Node** node_ref, int id);
int getLastNodeId(Node* node);

#endif
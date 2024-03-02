#include "LinkedList.h"

#include<stdio.h>

Node* head = NULL;

void showAllNode(Node* node)
{
    while(node != NULL){
        printf("%d %s %s %s\n", node->data.id, node->data.name, node->data.email, node->data.address);
        node = node->next;
    }
    printf("\n");
}

Node* searchNode(Node* node, int id)
{
    while(node != NULL){
        if(node->data.id == id){
            return node;
        }
        node = node->next;
    }
    return NULL;
}

void appendNode(Node** node_ref, Data data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    Node* currentNode = *node_ref;

    if(currentNode == NULL){
        *node_ref = newNode;
        return;
    }

    while(currentNode->next != NULL){
        currentNode = currentNode->next;
    }

    currentNode->next = newNode;

}

void updateNode(Node** node_ref, int id, Data data)
{
    Node* currentNode = *node_ref;
    while(currentNode != NULL){
        if(id == currentNode->data.id){
            (currentNode)->data = data;
            break;
        }
        currentNode = currentNode->next;
    }
}

void deleteNode(Node** node_ref, int id)
{
    Node* prev = NULL;
    Node* temp = *node_ref;

    if(temp != NULL && temp->data.id == id){
        *node_ref = temp->next;
        free(temp);
    }else{
        while(temp != NULL && temp->data.id != id){
            prev = temp;
            temp = temp->next;
        }

        if(temp == NULL){
            return;
        }

        prev->next = temp->next;
        free(temp);
    }

}

int getLastNodeId(Node* node)
{
    if(node == NULL){
        return 0;
    }else{
        while(node->next != NULL){
            node = node->next;
        }
        return node->data.id;
    }
}

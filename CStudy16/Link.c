//
// Created by 1 on 2024/5/8.
//

#include "Link.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Menu.h"

//LIST_T listInit(){
//    LIST_T *head=(LIST_T*)malloc(sizeof (LIST_T));
//    if(head==NULL){
//        printf("head creat error");
//        exit(0);
//    }
//    head->data = NULL;
//    head->next = NULL;
//}
//
//
//void listAppend(LIST_T*head,void *data){
//    LIST_T *current = head,*newNode=NULL;
//    while (current->next!=NULL){
//        current = current->next;
//    }
//    newNode = (LIST_T*) malloc(sizeof (LIST_T));
//    if(newNode==NULL){
//        printf("newnode creat error");
//        exit(0);
//    }
//    memset(newNode,0,sizeof (LIST_T));
//    head->data = data;
//    head->next = NULL;
//    current->next = newNode;
//}
//
//int listCouont(LIST_T*head){
//    int count = 0;
//    LIST_T *current = head;
//    if(current->next==NULL){
//        current = current->next;
//        count++;
//        if(count == index){
//            return current->data;
//        }
//    }
//
//}

int ID = 1; // Assuming you have a global variable for ID generation

LIST_T* list_init() {
    LIST_T *head = (LIST_T*)malloc(sizeof(LIST_T));
    if (head == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    memset(head, 0, sizeof(LIST_T));
    head->next = NULL;
    return head;
}

void list_add(LIST_T *head, void *data) {
    LIST_T *newNode = (LIST_T*)malloc(sizeof(LIST_T));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;

    LIST_T *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

int list_get_count(LIST_T *head) {
    int count = 0;
    LIST_T *current = head->next; // Skip the dummy head node
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void* list_get_data_by_pos(LIST_T *head, int pos) {
    LIST_T *current = head->next; // Skip the dummy head node
    int count = 0;
    while (current != NULL) {
        if (count == pos) {
            return current->data;
        }
        count++;
        current = current->next;
    }
    return NULL;
}

void list_delete_node(LIST_T *head, int pos) {
    LIST_T *prev = head;
    LIST_T *current = head->next;
    int count = 0;
    while (current != NULL) {
        if (count == pos) {
            prev->next = current->next;
            free(current);
            return;
        }
        count++;
        prev = current;
        current = current->next;
    }
}

void list_free(LIST_T *head) {
    LIST_T *current = head->next; // Skip the dummy head node
    while (current != NULL) {
        LIST_T *temp = current;
        current = current->next;
        free(temp->data);
        free(temp);
    }
    //free会追溯到开辟的首地址
    free(head);
}


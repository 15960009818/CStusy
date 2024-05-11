//
// Created by 1 on 2024/5/8.
//

#ifndef CSTUDY16_LINK_H
#define CSTUDY16_LINK_H
typedef struct list_t{
    void *data;
    struct list_t *next;
}LIST_T;

LIST_T* list_init();
void list_add(LIST_T *head, void *data);
int list_get_count(LIST_T *head);
void* list_get_data_by_pos(LIST_T *head, int pos);
void list_delete_node(LIST_T *head, int pos);
void list_free(LIST_T *head);
#endif //CSTUDY16_LINK_H

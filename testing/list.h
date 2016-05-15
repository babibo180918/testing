//
//  list.h
//  testing
//
//  Created by Nhan Nguyen on 5/13/16.
//  Copyright © 2016 Nhan Nguyen. All rights reserved.
//

#ifndef list_h
#define list_h

//#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef void (*FunctionType)(int);

void test(int input){
    printf("input integer: %d\n", input);
}

void pfTest(int value, FunctionType fp){
    fp(value);
}

/********** Implement of Doubly Linked List *************
 *  Interface:
 1. Create new linked list
 2. Create new Item
 3. Check list is empty
 4. Add an item to tail of list
 5. Add an item to head of list
 6. Add an item at another enqueued item
 7. Dequeue and item from list
 8. Get an item from list (not dequeue)
 9. Destroy item
 10. Clear List
 11. Destroy List
 */

typedef struct list_item_{
    list_item_  *next;
    list_item_  *prev;
    void        *data;
} L2_List_Item, *L2_List_Item_p;

typedef struct l2_list_s {
    L2_List_Item_p  anchor;
    char            *name;
} L2_List, *L2_List_p;

typedef void (*DELETE_ITEM_CALLBACK) (void *);
typedef void (*LIST_ITEM_TRAVERSE_CALLBACK) (void *);

L2_List_p L2_LIST_INIT(char *name){
    L2_List_p p_list = (L2_List_p)malloc(sizeof(L2_List));
    p_list->anchor = NULL;
    p_list->name = strcpy((char*)malloc(strlen(name)+1), name);
    return p_list;
}

L2_List_Item_p L2_ITEM_NEW(void *data){
    L2_List_Item_p p_item = (L2_List_Item_p)malloc(sizeof(L2_List_Item));
    p_item->next = NULL;
    p_item->prev = NULL;
    p_item->data = data;
    return p_item;
}

bool L2_IS_ITEM_QUEUED(L2_List_Item_p p_item){
    return (p_item && p_item->prev && p_item->next);
}

bool L2_LIST_IS_EMPTY(L2_List_p list){
    return (list->anchor);
}

void L2_ADD_TO_HEAD(L2_List_p list, void *data){
    L2_List_Item_p p_item = L2_ITEM_NEW(data);
    if(list->anchor != NULL){
        p_item->next = list->anchor;
        p_item->prev = list->anchor->prev;
        list->anchor->prev->next = p_item;
        list->anchor->prev = p_item;
    } else {
        p_item->next = p_item;
        p_item->prev = p_item;
    }
    list->anchor = p_item;
}

void L2_ADD_TO_LAST(L2_List_p list, void *data){
    L2_List_Item_p p_item = L2_ITEM_NEW(data);
    if(list->anchor == NULL) {
        p_item->next = p_item;
        p_item->prev = p_item;
        list->anchor = p_item;
    } else {
        p_item->next = list->anchor;
        p_item->prev = list->anchor->prev;
        p_item->prev->next = p_item;
        list->anchor->prev = p_item;
    }
}

bool L2_ADD_TO_BEFORE_OF(L2_List_p list, L2_List_Item_p p_item, void *data){
    if(!L2_IS_ITEM_QUEUED(p_item))
        return false;
    else {
        L2_List_Item_p new_item = L2_ITEM_NEW(data);
        new_item->next = p_item;
        new_item->prev = p_item->prev;
        new_item->prev->next = new_item;
        p_item->prev = new_item;
        if(list->anchor == p_item)
            list->anchor = new_item;
        return true;
    }
}

L2_List_Item_p L2_DEQUEUE_AT_HEAD(L2_List_p list){
    L2_List_Item_p p_item = list->anchor;
    if(p_item){
        list->anchor = p_item->next;
        list->anchor->prev = p_item->prev;
        p_item->prev->next = list->anchor;
        //
        p_item->prev = NULL;
        p_item->next = NULL;
        if(list->anchor == p_item)
            list->anchor = NULL;
    }
    return p_item;
}

L2_List_Item L2_GET_ITEM_HEAD(L2_List_p list){
    return *list->anchor;
}

void L2_DESTROY_ITEM(L2_List_Item_p p_item, DELETE_ITEM_CALLBACK callback){
    callback(p_item->data);
    free(p_item);
    p_item = NULL;
}

void L2_CLEAR_LIST (L2_List_p list, DELETE_ITEM_CALLBACK callback){
    while(list->anchor != NULL){
        L2_List_Item_p item = L2_DEQUEUE_AT_HEAD(list);
        L2_DESTROY_ITEM(item, callback);
    }
}

void L2_LIST_DESTROY (L2_List_p list, DELETE_ITEM_CALLBACK callback){
    L2_CLEAR_LIST(list, callback);
    free(list);
}

void L2_LIST_TRAVERSE(L2_List_p list, LIST_ITEM_TRAVERSE_CALLBACK callback){
    L2_List_Item_p p_item = list->anchor;
    while(p_item){
        callback(p_item->data);
        p_item = p_item->next;
        if(p_item == list->anchor) break;
    }
}

#endif /* list_h */

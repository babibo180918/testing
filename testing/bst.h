//
//  bst.h
//  testing
//
//  Created by Nhan Nguyen on 5/17/16.
//  Copyright © 2016 Nhan Nguyen. All rights reserved.
//

#ifndef bst_h
#define bst_h

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef int size_p;

typedef struct node_s {
    void *data;
    node_s *left;
    node_s *right;
    int idx;
} Node, *Node_p;

typedef struct tree_s {
    char *name;
    int count;
    Node_p root;
} BST, *BST_p;

//typedef int (*CompareFunc)(void *p1, void p2);

typedef void (*TreeTraverse)(void *data, size_p size);
typedef void (*NodeDestroy)(void *data);

/******* Implemetation Binary tree as linked data structure ***********
 *  Interface:
 1. Init an empty binary tree
 2. Build a binary tree from a list;
 3. Add root node to a tree
 4. Add a leaf node.
 4. Add a left child, right child to a node
 5. Get tree's root node
 6. Get data of a node
 7. Check tree empty
 8. Check node is leaf
 9. Remove leaf node
 10. Tranverse tree
 11. Destroy tree
 */

BST_p BST_init(char *name){
    BST_p tree = (BST_p)malloc(sizeof(BST));
    strcpy((char*)malloc(strlen(name)+1), name);
    tree->root = NULL;
    tree->count = 0;
    return tree;
}

bool BST_tree_is_empty(BST_p tree){
    return (tree->root == NULL);
}

bool BST_is_node_leaf(Node_p p_node){
    return !(p_node->left || p_node->right);
}

void BST_add_root(BST_p tree, void *data, size_p size){
    Node_p p_node = (Node_p)malloc(sizeof(Node));
    p_node->left = NULL;
    p_node->right = NULL;
    p_node->data = memcpy(malloc(size), data, size);
    p_node->idx = tree->count++;
    tree->root = p_node;
}

void BST_add_left_child(BST_p tree, Node_p node, void *data, size_p size){
    Node_p p_node = (Node_p)malloc(sizeof(Node));
    p_node->left = NULL;
    p_node->right = NULL;
    p_node->data = memcpy(malloc(size), data, size);
    p_node->idx = tree->count++;
    //
    node->left = p_node;
}

void BST_add_right_child(BST_p tree, Node_p node, void *data, size_p size){
    Node_p p_node = (Node_p)malloc(sizeof(Node));
    p_node->left = NULL;
    p_node->right = NULL;
    p_node->data = memcpy(malloc(size), data, size);
    p_node->idx = tree->count++;
    //
    node->right = p_node;
}

void BST_add_leaf(BST_p tree, Node_p p_node, void *data, size_p size, bool &isAdded){ // toward to balanced tree
    if(p_node != NULL){
        if(!isAdded && p_node->idx*2+1 == tree->count){
            BST_add_left_child(tree, p_node, data, size);
            isAdded = true;
            return;
        }
        if(!isAdded && p_node->idx*2+2 == tree->count){
            BST_add_right_child(tree, p_node, data, size);
            isAdded = true;
            return;
        }
        if(!isAdded)
            BST_add_leaf(tree, p_node->left, data, size, isAdded);
        if(!isAdded)
            BST_add_leaf(tree, p_node->right, data, size, isAdded);
    }
    
}

BST_p BST_build_from_array(char *name, void *data, size_p num, size_p size){
    BST_p tree = BST_init(name);
    bool isAdded = false;
    for(int i=0; i<num; i++){
        if(i == 0) BST_add_root(tree,  (Byte_t)data+i*size, size);
        else BST_add_leaf(tree, tree->root, (Byte_t)data+i*size, size, isAdded);
        isAdded = false;
    }
    return tree;
}

Node_p BST_get_root(BST_p tree){
    return tree->root;
}

void *BST_get_node_data(Node_p p_node){
    return p_node->data;
}

void BST_traverse(Node_p root, TreeTraverse traverse, size_p size){
    if(root != NULL){
        traverse(root->data, size);
        BST_traverse(root->left, traverse, size);
        BST_traverse(root->right, traverse, size);
    }
}

void BST_Node_destroy(Node_p root, NodeDestroy func){
    if(root){
        func(root->data);
        BST_Node_destroy(root->left, func);
        BST_Node_destroy(root->right, func);
    }
}

void BST_destroy(BST_p tree, NodeDestroy func, size_p size){
    BST_Node_destroy(tree->root, func);
    free(tree->name);
    free(tree);
}


#endif /* bst_h */

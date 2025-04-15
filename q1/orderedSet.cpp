#include <iostream>
#include "orderedSet.h"

class Set{
private:
    struct node {
        int value;
        node *left;
        node *right;
    };

    node *root;

    bool add(node *&n, int i){
        if(n == nullptr){
            n = new node;
            n->value = i;
            n->left = nullptr;
            n->right = nullptr;
            return true;
        } 

        if(n->value == i){
            return false;
        }
        
        if(i < n->value){
            return add(n->left, i);
        } else if(i > n->value){
            return add(n->right, i);
        }

        return false;
    }

    bool remove(node *&n, int i){
        if(n == nullptr){
            return false;
        }

        if(i < n->value){
            return remove(n->left, i);
        } else if(i > n->value){
            return remove(n->right, i);
        } else if(i == n->value){
            if(n->left == nullptr && n->right == nullptr){
                delete n;
                n = nullptr;
                return true;
            } else if(n->left == nullptr){

            }
        }

        return false;
    }

public:
        /* An insert function. The function returns 1 if the
    character was added, and 0 if it was already in the set. */
    int add(int i){
        return add(root, i);
    }

    /* A removal function. The function returns 1 if the
    character was removed and 0 if it was not in the set. */
    int remove(int i){
        return remove(root, i);
    }

    /* A test function. The function returns 1 if the set contains
    the character and 0 otherwise. */
    int contains(int i){
        return 0;
    }

    /* Computes the current size of the set. */
    unsigned int size(){
        return 0;
    }

    /* A function that outputs all characters in the set on the
    console, delimited by commas. */
    void print(){
        
    }

    /* A function that releases allocated memory. Make sure,
    that after this function call, allocated memory was
    correctly deleted. */
    void destroy(){

    }

};

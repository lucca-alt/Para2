#include <iostream>

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
        node *temp;
        if(n == nullptr){
            return false;
        }

        if(i < n->value){ //search for fitting node
            return remove(n->left, i);
        } else if(i > n->value){
            return remove(n->right, i);
        } else if(i == n->value){ //node found
            if(n->left == nullptr && n->right == nullptr){ //no children
                delete n;
                n = nullptr;
                return true;
            } else if(n->left == nullptr){ //node has only right child
                temp = n;
                n = n->right;
                delete temp;
                return true;
            } else if(n->right == nullptr){ //node has only left child
                temp = n;
                n = n->left;
                delete temp;
                return true;
            } else if(n->right && n->left){ //if node has two children
                node *successor = n->right;
                
                while (successor != nullptr && successor->left != nullptr){ //find successor (smallest value on right side)
                    successor = successor->left;
                }
                n->value = successor->value; //replace current node value with successor
                return remove(n->right, successor->value); //find and properly remove the successor (n now has its value)
            }
        }

        return false;
    }

    bool contains(node *&n, int i){
        if(n == nullptr) return false;

        if(i < n->value){
            return contains(n->left, i);
        } else if(i > n->value){
            return contains(n->right, i);
        } else if(i == n->value){
            return true;
        }

        return false;
    }

    unsigned int size(node *&n){
        if(n == nullptr) return 0; //if empty, size 0

        return 1 + size(n->left) + size(n->right); //recursively checks if n->left and right a nullptr, if not
                                                   // then size goes up 
    }

    void print(node *&n){
        if(n == nullptr){
            return;
        }

        print(n->left);
        std::cout << static_cast<char>(n->value) << ",";
        print(n->right);
    }

    void destroy(node *&n){
        if(n == nullptr) return;

        destroy(n->left);
        destroy(n->right);
        delete n;
    }

public:
    Set() {
        root = nullptr;
    }

    ~Set() {
        destroy(root);
    }
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
        return contains(root, i);
    }

    /* Computes the current size of the set. */
    unsigned int size(){
        return size(root);
    }

    /* A function that outputs all characters in the set on the
    console, delimited by commas. */
    void print(){
        print(root);
    }

    /* A function that releases allocated memory. Make sure,
    that after this function call, allocated memory was
    correctly deleted. */
    void destroy(){
        destroy(root);
    }

};

int main(){
    Set set;
    set.add('A');
    set.add('a');
    set.add('B');
    set.add('C');
    std::cout << set.size() << std::endl;

    set.print();
    return 0;
}

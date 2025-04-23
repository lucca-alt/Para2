#ifndef ORDEREDSET_H
#define ORDEREDSET_H
class Set { //caused problems with this header file so I did not use it, was not required anyways
   public:
      struct node {
        int value;
        node *left;
        node *right;
    };

    node *root;

   public:
      Set();
      int add(int i);
      int remove(int i);
      int contains(int i);
      unsigned int size();
      void print();
      void destroy();
};

#endif /* ORDEREDSET_H */
#ifndef ORDEREDSET_H
#define ORDEREDSET_H

/* An insert function. The function returns 1 if the
   character was added, and 0 if it was already in the set. */
int add(int i);

/* A removal function. The function returns 1 if the
   character was removed and 0 if it was not in the set. */
int remove(int i);

/* A test function. The function returns 1 if the set contains
   the character and 0 otherwise. */
int contains(int i);

/* Computes the current size of the set. */
unsigned int size();

/* A function that outputs all characters in the set on the
   console, delimited by commas. */
void print();

/* A function that releases allocated memory. Make sure,
   that after this function call, allocated memory was
   correctly deleted. */
void destroy();

#endif /* ORDEREDSET_H */
#ifndef EX3LIB13_H
#define EX3LIB13_H

typedef struct _tnode
{
	int data;
	struct _tnode* left;
	struct _tnode* right;
} TNODE;

extern int sethr(int ans);
extern int trisethr(double x, double y, double z, int ans);
extern void print_array(int a[], int n);
extern void free_tree(TNODE* root);
extern void print_tree(TNODE* node);

#endif

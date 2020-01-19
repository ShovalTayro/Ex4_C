#ifndef _FREQ_H_
#define _FREQ_H_

	typedef struct Node Node;

	Node* CreateNewNode(char c);

	Node* addNode(Node *n ,char letter);

	void counter(Node* n);

	int noChildern(Node* n);

	void freeAll(Node *root);

	void printTree(Node* root, char *str, int j);

	void printTreeReverse(Node* root, char *str, int j);	

#endif

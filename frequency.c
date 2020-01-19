#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "trie.h"

#define NUM_LETTERS ((int)26) 

typedef struct Node{
	char letter;
	long unsigned int count;
	struct Node* children[NUM_LETTERS];
	char existChar[26];
	}Node;


Node* CreateNewNode(char c){
	int i;
	Node *n = (Node*)malloc(sizeof(Node));
	n->count=0;
	n->letter=c; 
	for (i=0; i<26; i++){
		n->existChar[i] = 0;
	}
	return n;
}

Node* addNode(Node *node, char letter){
	if(node->existChar[letter-'a'] == 0){
			Node *temp = CreateNewNode(letter);
			node->existChar[letter-'a'] = 1;
			node->children[letter-'a'] = temp;
			return temp;
	}
	return (node->children[letter-'a']);
}

void counter(Node* n){
	n->count++;
}

int noChildern(Node* n){
	int i;
	for (i=0; i<NUM_LETTERS; i++){
		if (n->existChar[i]==1)return 0;
	}
	return 1;
}

void freeAll(Node* root){
	int i;
	if (root==NULL) return;
	
	if (noChildern(root)){ 
		free(root);
		return;
	}
	else{
	for (i=0; i<NUM_LETTERS; i++){
		if (root->existChar[i]==1){
			freeAll(root->children[i]);

		}
		}
	free(root);
	}
}

void printTree(Node* root, char *str, int j){
	if (noChildern(root)){
		str[j] = '\0';
		printf("%s\t%ld\n", str, root->count);
		return;
	}
	if (root->count > 0){
		str[j] = '\0';
		printf("%s\t%ld\n", str, root->count);
	}
	int i;
	for (i=0; i<NUM_LETTERS; i++){
		if (root->existChar[i]==1){
			str[j] = root->children[i]->letter;
			printTree(root->children[i], str, j+1);
		}
	}
}

void printTreeReverse(Node* root, char *str, int j){
	if (noChildern(root)){
		str[j] = '\0';
		printf("%s\t%ld\n", str, root->count);
		return;
	}
	if (root->count > 0){
		str[j] = '\0';
		printf("%s\t%ld\n", str, root->count);
	}
	int i;
	for (i=NUM_LETTERS-1; i>=0; i--){
		if (root->existChar[i]==1){
			str[j] = root->children[i]->letter;
			printTreeReverse(root->children[i], str, j+1);
		}
	}
}

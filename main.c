#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>
#include "trie.h"

int main(int argc, char const *argv[]){
	//first node - root
	Node *root= CreateNewNode('\0');
	Node *temp = root;
	//letter read
	char letter;
	char ifReverse= 'a';
	//save the word length
	int length=0;
	int maxLength =0;

	while ((letter=getc(stdin)) != EOF){
		if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z')){
			temp = addNode(temp, tolower(letter));
			length++;
		}
		else if (letter == '\t' || letter == ' ' || letter == '\n'){
			counter(temp);
			temp = root;
			if(length > maxLength) maxLength = length;
			length = 0;
		}
	}

	char word[maxLength+2]; // +2 beacuse '\0'

	if(argc>1) ifReverse=*argv[1];	

	if(ifReverse == 'r') printTreeReverse(root, word, 0);
	else{ 
	printTree(root, word, 0); 
	}
	freeAll(root);

	return 0;
}

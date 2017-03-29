/*
COMP321 A2 Q2. Permutation Encryption 
Name: Simon Hsu
ID: 260610820
Date: 2017.02.07
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int *getKey(void){
	char x;
	int *k;
	int i = 0, c = 0, keyLength = 0, contentLength = 0;

	k = malloc(sizeof(int));
	if (k == NULL){
		return NULL;
	} 
		
	do {
		scanf("%d%c", &k[i], &x);
		if (k[0] == 0){	  		
			return k;
		}

		i++;

		k = realloc(k,sizeof(int) * (i + 1));
		if (k == NULL){
			return NULL;
		}
		c++;
	} while (x != '\n');
	return k;
}

void swap(char *a, int i, int j){
	if (i != j){
		a[i] = a[i]^a[j];
		a[j] = a[j]^a[i];
		a[i] = a[i]^a[j];
	}
}

// encrpyt the content
void encrpytion(char *d, char *ptr, int *key, int contentLength, int keyLength){
	int i = 0, j = 0 ,c = 0;

	while (j != (contentLength / keyLength)){
		for (i = 1; i < keyLength + 1; i++){
			swap(ptr, i, key[i] - 1);
			d[c] = ptr[i];
			swap(ptr, i, key[i] - 1);
			c++;
		}
		ptr += keyLength;
		j++;
	}
}

int main(int argc, char const *argv[]){
	// initialize the variables, the input is a list up to 150 messages
	int i, j, c;
	int *key[150];
	char *content[150];
	int keyLength;
	int contentLength;

	for (i = 0;; i++) {
		// get key for permutation
		key[i] = getKey();
		keyLength = key[i][0];
		// the key length, n, is set to be between 1 and 20, handle failure
		if (keyLength < 1 || keyLength > 20){
			free(key[i]);
			break;
		}
		
		// get message and pad the white space before encrpytion
		content[i] = malloc(sizeof(char) * 1024);
		(void)fgets(content[i], 1024,stdin);
		// strcspn returns the number of characters in the initial segment of string str1 which are not in the string str2.
		content[i][strcspn(content[i], "\n")] = '\0';

		contentLength = strlen(content[i]);
		
		// pad white space
		while (contentLength % keyLength != 0){
			strcat(content[i]," ");
			contentLength = strlen(content[i]);
		}
	}

	c = i;
	
	for (i = 0; i < c; i++){
		contentLength = strlen(content[i]);
		keyLength = key[i][0];
		char *newMessage = malloc(sizeof(int) * contentLength + 1);
		
		// encrpyt the message
		encrpytion(newMessage, content[i], key[i], contentLength, keyLength);
		
		// print out the messaage after, include single quotes around the encrpyted message
		int p;
		printf("%c",'\'' );
		for (p = 0; p < contentLength; p++){
			printf("%c", newMessage[p]);
		}
		printf("%c\n",'\'' );
		
		// deallocates the memory previously allocated by a call to calloc, malloc, or realloc.
		free(content[i]);
		free(key[i]);
		free(newMessage);
	}
	return 0;
}
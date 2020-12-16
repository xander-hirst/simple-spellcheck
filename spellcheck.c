#include "dictmod.h"
#define MAX_SENTENCE_SIZE 30
#define MAX_LINE_SIZE 1024

int main(){
  
    printf("Enter a sentence to be spell checked followed by an enter key:\n");
    char input[MAX_LINE_SIZE];
    fgets(input, MAX_LINE_SIZE, stdin); /*get line of input from user*/
    if (input[strlen(input)- 1] == '\n'){
      input[strlen(input)- 1] = '\0';
    }
    
    char inputtok[MAX_SENTENCE_SIZE][MAX_WORD_SIZE];
    int numwords = 0, i = 0;
    char *cp;
    /*tokenize user input word by word into 2D string array*/
    cp = strtok(input, " ,.?!\t\n");
    strcpy(inputtok[i++], cp);
    numwords++;
    while ((cp = strtok(NULL, " ,.?!\t\n"))!= NULL){
      strcpy(inputtok[i], cp);
      numwords = ++i;
    }
    printf("working...\n");

    create_dict(); /*initialize and populate the dictionary 2D array*/
    for (i = 0; i < numwords; i++){
      if ((lookup(inputtok[i])) == 1){/*check first if word is in dictionary, if is, print it*/
	      printf("%s ", inputtok[i]);
      }//if
      else {/*when not, find word with lowest levenshtein distance and print it*/
	 printindex(fixspelling(inputtok[i]));
      }
    }
    printf("\n");
}


#include "dictmod.h"

static char dict[DICT_SIZE][MAX_WORD_SIZE];

void create_dict ()
{
  FILE *f;
  f = fopen("/usr/share/dict/cracklib-small", "r");
  if (f == NULL){
    printf("Error opening the dictionary (File not found?)\n");
    exit(-1);
  }

  int i = 0;
  while ((fgets(dict[i], MAX_WORD_SIZE, f) != NULL)){
    if(dict[i][strlen(dict[i])- 1] == '\n'){/*remove enter key from end of each line*/
      dict[i][strlen(dict[i])- 1] = '\0';   
    }
    i++;
  }
}


int lookup (const char *a)
{
  int i;
  for (i = 0; i < DICT_SIZE; i++){
    if ((strcmp(a, dict[i]) == 0)){/*if strings are equal*/
      return 1;/*return true*/
    }
  }
  return -1;
}

int fixspelling (const char *a){
  int found = -1, count = 1, i;
  int lev_dist[DICT_SIZE];
  while (found < 0){/*first store levenshtein dist of every dictionary word into array*/
    for (i = 0; i < DICT_SIZE; i++){
      if (count == 1){/*if word w/ lev dist of 1 is in dict, return its index*/
	lev_dist[i] = distance(a, dict[i]);
	if (lev_dist[i] == count){
	  return i;
	}//if
      }//if
      if(lev_dist[i] == count){
	return i;
      }//if
    }//for
    count++; /*if word isnt found on first pass, increase tolerance for lev dist*/
  }//while
  return -1;
}//fixspelling

void printindex (int index){
  printf("*%s* ", dict[index]);
}//printindex


unsigned int distance (const char*a, const char*b)
{
  unsigned int a_len = strlen(a);
  unsigned int b_len = strlen(b);

  if (a_len == 0){
    return b_len;
  }

  if (b_len == 0){
    return a_len;
  }

  char a_head[MAX_WORD_SIZE], b_head[MAX_WORD_SIZE];
  strcpy(a_head, a);
  strcpy(b_head, b);

  a_head[a_len - 1] = '\0';
  b_head[b_len - 1] = '\0';

  int head_dist;
  if (a[a_len - 1] == b[b_len - 1]) {
      head_dist = distance(a_head, b_head);
  } else {
      head_dist = 1 + distance(a_head, b_head);
  }

  int ahead2b_dist = 1 + distance(a_head, b);
  int bhead2a_dist = 1 + distance(b_head, a);

  return MIN(head_dist, MIN(ahead2b_dist, bhead2a_dist));
}


      
      
    
	
	      
    
  
  

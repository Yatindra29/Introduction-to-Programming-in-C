#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include "cards.h"
#include "deck.h"
#include "eval.h"
#include "future.h"
#include "input.h"

deck_t ** read_input(FILE * f, size_t * n_hands, future_cards_t * fc){
  deck_t **arr_of_deck=NULL;
  size_t sz=0;
  char *line=NULL;
  size_t nm=0;
  while(getline(&line,&sz,f)>=0){
    deck_t *deck=hand_from_string(line,fc);
    if(deck==NULL)
      continue;
    arr_of_deck=realloc(arr_of_deck, (nm+1)*sizeof(*arr_of_deck));
    arr_of_deck[nm]=deck;
    nm++;
    //fprintf(stderr,"A hand consisted of less than 5 cards");
    //return NULL;
    //continue;
    //}
  }
  free(line);
  n_hands=&nm;
  return arr_of_deck;
}
deck_t * hand_from_string(const char * str, future_cards_t * fc){
  int len=strlen(str);
  deck_t *to_return=malloc(sizeof(*to_return));
  to_return->cards=NULL;
  to_return->n_cards=0;
  for(int i=0;i<len-1;i++){
    if ((str[i] == '\n') || (str[i] == ' ')){
      continue;
    }
    else{
      if(isdigit(str[i]) && isalpha(str[i+1])){
      card_t card=card_from_letters(str[i],str[i+1]);
      add_card_to(to_return,card);
      i++;
    }
    else if(str[i]=='?' && isdigit(str[i+1])){
      // card_t *em=add_empty_card(to_return);
      // size_t index=str[i+1]-'0';
      // add_future_card(fc,index,em);
      // i++;
      i++;
      char num[strlen(str)];
      int n = 0;
      while (!((str[i] == '\n') || (str[i] == ' '))){
	num[n] = str[i];
	i++;
	n++;
      }
      num[n] = '\0';
      add_future_card(fc, atoi(num), add_empty_card(to_return));
    }}}
  if(to_return->n_cards<5){
    fprintf(stderr,"Less than 5 cards\n");
    return NULL;
  }
  return to_return;
}

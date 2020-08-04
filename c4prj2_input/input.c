#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "cards.h"
#include "deck.h"
#include "eval.h"
#include "future.h"
#include "input.h"

deck_t ** read_input(FILE * f, size_t * n_hands, future_cards_t * fc){
  deck_t **arr_of_deck=malloc(sizeof(**arr_of_deck));
  deck_t *deck=malloc(sizeof(*deck));
  deck->cards=NULL;
  deck->n_cards=0;
  size_t sz=0;
  char *line=NULL;
  int n=0;
  while(getline(&line,&sz,f)>=0){
    deck=hand_from_string(line,fc);
    if(deck!=NULL){
      arr_of_deck=realloc(arr_of_deck, (n+1)*sizeof(**arr_of_deck));
    arr_of_deck[n]=deck;
    n++;
    }
    else{
      fprintf(stderr,"A hand consisted of less than 5 cards");
      return NULL;
    }
  }
  free(line);
  *n_hands=n;
  return arr_of_deck;
}
deck_t * hand_from_string(const char * str, future_cards_t * fc){
  int len=strlen(str);
  int count=0;
  deck_t *to_return=malloc(sizeof(*to_return));
  to_return->cards=NULL;
  to_return->n_cards=0;
  for(int i=0;i<len-1;i++){
    if(isdigit(str[i]) && isalpha(str[i+1])){
	card_t card=card_from_letters(str[i],str[i+1]);
	add_card_to(to_return,card);
	count++;
      }
    else if(str[i]=='?' && isdigit(str[i+1])){
      card_t *em=add_empty_card(to_return);
      add_future_card(fc,str[i+1],em);
      count++;
    }
    if(str[i]==';'){
      if(count<5){
	fprintf(stderr,"Less than 5 cards");
	return NULL;
      }
      count=0;
    }}
  return to_return;
}

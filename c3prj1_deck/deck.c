#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

void print_hand(deck_t * hand){
  size_t i=0;
  size_t len=(*hand).n_cards;
  card_t *ke=NULL;
  card_t k;
  for(i=0;i<len;i++)
    {
      ke=(*hand).cards[i];
      k=*ke;
      print_card(k);
      printf(" ");
    }
}

int deck_contains(deck_t * d, card_t c) {
  size_t i=0;
  size_t len=(*d).n_cards;
  card_t *poin=NULL;
  card_t card_req;
  for(i=0;i<len;i++)
    {
      poin=(*d).cards[i];
      card_req=*poin;
      if(card_req.value == c.value && card_req.suit==c.suit)
	{
	  return 1;
	  break;
	}
    }
  return 0;
}

void shuffle(deck_t * d){
  size_t num=(*d).n_cards;
  size_t i=0;
  card_t temp;
  card_t *p=NULL;
  card_t *r=NULL;
  size_t n;
  for(i=0;i<num/2;i++)
    {
      n=(rand() % num);
      p=(*d).cards[i];
      r=(*d).cards[n];
      temp=*p;
      *p=*r;
      *r=temp;
}
}
void assert_full_deck(deck_t * d) {
  size_t i=0;
  size_t n=(*d).n_cards;
  for(i=0;i<n;i++)
    {
      assert(deck_contains(d,card_from_num(i)));
}
}
void add_card_to(deck_t * deck, card_t c){
  card_t *point=&c;
  (*deck).cards=realloc((*deck).cards, (((*deck).n_cards)+1) *sizeof((*deck).cards));
 ((*deck).cards[(*deck).n_cards])=point;
  (*deck).n_cards++;
}
card_t * add_empty_card(deck_t * deck){
  card_t *empty_card=malloc(sizeof(*empty_card));
  (*empty_card).value=0;
  (*empty_card).suit=0;
  return empty_card;
}
deck_t * make_deck_exclude(deck_t * excluded_cards){
  deck_t *new_deck=malloc(sizeof(*new_deck));
  (*new_deck).cards=NULL;
  (*new_deck).n_cards=0;
  card_t check;
  for(int i=0;i<52;i++){
    check=card_from_num(i);
    if(deck_contains(excluded_cards,check)){
	continue;
      }
      else{
	add_card_to(new_deck,check);
      }}
  return new_deck;
  free(new_deck);
}
deck_t * build_remaining_deck(deck_t ** hands, size_t n_hands){
  deck_t *final_deck=malloc(sizeof(*final_deck));
  (*final_deck).cards=NULL;
  (*final_deck).n_cards=0;
  deck_t *to_exclude=malloc(sizeof(*to_exclude));
  (*to_exclude).cards=NULL;
  (*to_exclude).n_cards=0;
  for(int i=0;i<n_hands;i++){
    for(int j=0;j<hands[i]->n_cards;j++){
      add_card_to(to_exclude,*(hands[i]->cards[j]));
	  }}
  final_deck=make_deck_exclude(to_exclude);
  return final_deck;
  free(final_deck);
  free(to_exclude);
}
void free_deck(deck_t * deck){
  for(int i=0;i<(*deck).n_cards;i++){
    free(deck ->cards[i]);
  }
  free(deck ->cards);
  free(deck);
}

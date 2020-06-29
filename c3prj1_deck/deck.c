#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

void print_hand(deck_t * hand){
  size_t i=0;
  size_t len=(*hand).n_cards;
  card_t *ke;
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
  card_t *poin;
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
  card_t *p;
  card_t *r;
  size_t n;
  for(i=0;i<num/4;i++)
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


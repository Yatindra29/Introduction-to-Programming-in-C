#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
#include <string.h>
void print_hand(deck_t * hand){
  size_t i=0;
  size_t len=(*hand).n_cards;
  for(i=0;i<len;i++)
    {
      card_t *ke=(*hand).cards[i];
      card_t k=*ke;
      print_card(k);
      printf(" ");
    }
}

int deck_contains(deck_t * d, card_t c) {
  size_t i=0;
  size_t len=(*d).n_cards;
  for(i=0;i<len;i++)
    {
      card_t *poin=(*d).cards[i];
      card_t card_req=*poin;
      if(card_req.value == c.value && card_req.suit==c.suit)
	return 1;
    }
  return 0;
}

void shuffle(deck_t * d){
  size_t num=(*d).n_cards;
  size_t i=0;
  card_t temp;
  for(i=0;i<num;i++)
    {
      size_t n=(rand() % num);
      card_t *p=(*d).cards[i];
      //card_t tbs=*p;
      card_t *r=(*d).cards[n];
      //card_t ran=*r;
      temp=*p;
      *p=*r;
      *r=temp;
}
}
void assert_full_deck(deck_t * d) {
  size_t i=0;
  size_t n=(*d).n_cards;
  int count=0;
  for(i=0;i<n;i++)
    {
      count=0;
      card_t *p=(*d).cards[i];
      card_t searched=*p;
      int ch=deck_contains(d,searched);
      count+=ch;
      assert(count<2);
}
}


#include "eval.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int card_ptr_comp(const void * vp1, const void * vp2) {
  const card_t * const * cpp1=(const card_t * const *) vp1;
  const card_t * const * cpp2=(const card_t * const *) vp2;
  const card_t * cp1=*cpp1;
  const card_t * cp2=*cpp2;
  unsigned c1=(*cp1).value;
  unsigned c2=(*cp2).value;
  unsigned result=c2-c1;
  if(result!=0)
    return result;
  else
    {
      suit_t s1=(*cp1).suit;
      suit_t s2=(*cp2).suit;
      unsigned res=s2-s1;
	return res;
    }
  return 0;
}

suit_t flush_suit(deck_t * hand) {
  size_t num=(*hand).n_cards;
  size_t i=0;
  int sp=0;
  int cl=0;
  int he=0;
  int di=0;
  card_t *s=NULL;
  card_t card;
  for(i=0;i<num;i++)
    {
      s=(*hand).cards[i];
      card=*s;
      if(card.suit==SPADES)
	sp++;
      else if(card.suit==CLUBS)
	cl++;
      else if(card.suit==HEARTS)
	he++;
      else
	di++;
    }
  if(sp==5)
    return SPADES;
  else if(cl==5)
    return CLUBS;
  else if(he==5)
    return HEARTS;
  else if(di==5)
    return DIAMONDS;
      else
  return NUM_SUITS;
}

unsigned get_largest_element(unsigned * arr, size_t n) {
  unsigned max=0;
  size_t i=0;
  for(i=0;i<n;i++)
    {
      if(arr[i]>max)
	max=arr[i];
    }
  if(max!=0)
  return max;
  return 0;
}

size_t get_match_index(unsigned * match_counts, size_t n,unsigned n_of_akind){
  size_t tbr=-1;
  for(size_t i=0;i<n;i++)
    {
      if(match_counts[i]==n_of_akind)
	{
	  tbr=i;
	  return tbr;
	  break;
	}}
  assert(tbr!=-1);
  return 0;
}
ssize_t  find_secondary_pair(deck_t * hand,
			     unsigned * match_counts,
			     size_t match_idx) {
  size_t num=(*hand).n_cards;
  ssize_t i=match_idx+match_counts[match_idx];
  ssize_t j=i;
  card_t *k;
  card_t ke;
  card_t *l=(*hand).cards[match_idx];
  card_t multi=*l;
  for(j=i;j<num;j++)
    {
      k=(*hand).cards[j];
      ke=*k;
      if((match_counts[j]>1) && (ke.value!=multi.value))
	{
	  return j;
	  break;
	}}
  return -1;
}

int check_for_straight(deck_t *hand, size_t index, suit_t fs,int n)
{
  if(fs==NUM_SUITS)
    {
  int straight=0;
  size_t num=(*hand).n_cards;
  card_t *first;
  card_t *second;
  card_t card1;
  card_t card2;
  for(size_t i=index;i<=num-2;i++)
    {
      first=(*hand).cards[i];
      second=(*hand).cards[i+1];
      card1=*first;
      card2=*second;
      if(card1.value==card2.value)
	continue;
      else if(card1.value-card2.value==1)
	{
	  straight++;
	  if(straight==n-1)
	    return 1;
	}
      else
	return 0;
    }}
  card_t *kk;
  card_t k;
  kk=(*hand).cards[index];
  k=*kk;
  int count=0;
  if(k.suit==fs)
    {
      card_t *fc;
      card_t fcard;
      for(size_t j=index+1;j<(*hand).n_cards;j++)
	{
	  fc=(*hand).cards[j];
	  fcard=*fc;
	  if(fcard.suit!=fs)
	    continue;
	  if(k.value-fcard.value==1){
	    count++;
	    kk=(*hand).cards[j];
	  }}
      if(count==n-1)
	return 1;
    }
  else if(k.suit!=fs)
  return 0;
  return 0;
}
int check_for_ace_low_straight(deck_t * hand,size_t index, suit_t fs)
{
  card_t *point;
  point=(*hand).cards[index];
  card_t ca=*point;
  int check=0;
  if(ca.value!=VALUE_ACE)
    return 0;
  else
    {
      size_t i=index+1;
      card_t *pp;
      card_t c;
      for(size_t j=i;j<(*hand).n_cards-3;j++)
	{
	  pp=(*hand).cards[j];
	  c=*pp;
	  check=check_for_straight(hand,j,fs,4);
	  if(check==1 && c.value==5)
	    {
	      if(fs==NUM_SUITS)
		return 1;
	      if(ca.suit==fs)
		return 1;
	    }}}
	return 0;
    }
int is_straight_at(deck_t * hand, size_t index, suit_t fs) {
  int a1=check_for_ace_low_straight(hand,index,fs);
  int a2=check_for_straight(hand,index,fs,5);
  if(a1==1)
    return -1;
  else if(a2==1)
    return 1;
  else
  return 0;
}

hand_eval_t build_hand_from_match(deck_t * hand,
				  unsigned n,
				  hand_ranking_t what,
				  size_t idx) {
  hand_eval_t ans;
  ans.ranking=what;
  size_t limit=idx+n;
  size_t j=0;
  size_t i=0;
  for(i=idx;i<limit;i++)
    {
      ans.cards[j]=(*hand).cards[i];
      j++;
    }
  for(size_t p=0;p<idx;p++)
    {
	  if(j<5)
	    {
	      ans.cards[j]=(*hand).cards[p];
	      ++j;
	    }}
  if(j<5)
    {
  for(size_t q=limit;q<(*hand).n_cards;q++)
    {
      if(j<5)
	{
	  ans.cards[j]=(*hand).cards[q];
	  ++j;
	}}}
  return ans;
}

int compare_hands(deck_t * hand1, deck_t * hand2) {
  qsort(hand1->cards, hand1->n_cards, sizeof(hand1->cards[0]), card_ptr_comp);
  qsort(hand2->cards, hand2->n_cards, sizeof(hand2->cards[0]), card_ptr_comp);
  hand_eval_t h1=evaluate_hand(hand1);
  hand_eval_t h2=evaluate_hand(hand2);
  if((h1).ranking>(h2).ranking)
    return -1;
  else if((h1).ranking<(h2).ranking)
    return 1;
  else
    {
      size_t i=0;
      card_t *first;
      card_t *second;
      card_t f;
      card_t s;
      for(i=0;i<5;i++)
	{
	  first=h1.cards[i];
	  second=h2.cards[i];
	  f=*first;
	  s=*second;
	  if(f.value>s.value)
	    {
	      return 1;
	      break;
	    }
	  else if(f.value<s.value)
	    {
	      return -1;
	      break;
	    }}}
  return 0;
}



//You will write this function in Course 4.
//For now, we leave a prototype (and provide our
//implementation in eval-c4.o) so that the
//other functions we have provided can make
//use of get_match_counts.
unsigned * get_match_counts(deck_t * hand) ;

// We provide the below functions.  You do NOT need to modify them
// In fact, you should not modify them!


//This function copies a straight starting at index "ind" from deck "from".
//This copies "count" cards (typically 5).
//into the card array "to"
//if "fs" is NUM_SUITS, then suits are ignored.
//if "fs" is any other value, a straight flush (of that suit) is copied.
void copy_straight(card_t ** to, deck_t *from, size_t ind, suit_t fs, size_t count) {
  assert(fs == NUM_SUITS || from->cards[ind]->suit == fs);
  unsigned nextv = from->cards[ind]->value;
  size_t to_ind = 0;
  while (count > 0) {
    assert(ind < from->n_cards);
    assert(nextv >= 2);
    assert(to_ind <5);
    if (from->cards[ind]->value == nextv &&
	(fs == NUM_SUITS || from->cards[ind]->suit == fs)){
      to[to_ind] = from->cards[ind];
      to_ind++;
      count--;
      nextv--;
    }
    ind++;
  }
}


//This looks for a straight (or straight flush if "fs" is not NUM_SUITS)
// in "hand".  It calls the student's is_straight_at for each possible
// index to do the work of detecting the straight.
// If one is found, copy_straight is used to copy the cards into
// "ans".
int find_straight(deck_t * hand, suit_t fs, hand_eval_t * ans) {
  if (hand->n_cards < 5){
    return 0;
  }
  for(size_t i = 0; i <= hand->n_cards -5; i++) {
    int x = is_straight_at(hand, i, fs);
    if (x != 0){
      if (x < 0) { //ace low straight
	assert(hand->cards[i]->value == VALUE_ACE &&
	       (fs == NUM_SUITS || hand->cards[i]->suit == fs));
	ans->cards[4] = hand->cards[i];
	size_t cpind = i+1;
	while(hand->cards[cpind]->value != 5 ||
	      !(fs==NUM_SUITS || hand->cards[cpind]->suit ==fs)){
	  cpind++;
	  assert(cpind < hand->n_cards);
	}
	copy_straight(ans->cards, hand, cpind, fs,4) ;
      }
      else {
	copy_straight(ans->cards, hand, i, fs,5);
      }
      return 1;
    }
  }
  return 0;
}


//This function puts all the hand evaluation logic together.
//This function is longer than we generally like to make functions,
//and is thus not so great for readability :(
hand_eval_t evaluate_hand(deck_t * hand) {
  suit_t fs = flush_suit(hand);
  hand_eval_t ans;
  if (fs != NUM_SUITS) {
    if(find_straight(hand, fs, &ans)) {
      ans.ranking = STRAIGHT_FLUSH;
      return ans;
    }
  }
  unsigned * match_counts = get_match_counts(hand);
  unsigned n_of_a_kind = get_largest_element(match_counts, hand->n_cards);
  assert(n_of_a_kind <= 4);
  size_t match_idx = get_match_index(match_counts, hand->n_cards, n_of_a_kind);
  ssize_t other_pair_idx = find_secondary_pair(hand, match_counts, match_idx);
  free(match_counts);
  if (n_of_a_kind == 4) { //4 of a kind
    return build_hand_from_match(hand, 4, FOUR_OF_A_KIND, match_idx);
  }
  else if (n_of_a_kind == 3 && other_pair_idx >= 0) {     //full house
    ans = build_hand_from_match(hand, 3, FULL_HOUSE, match_idx);
    ans.cards[3] = hand->cards[other_pair_idx];
    ans.cards[4] = hand->cards[other_pair_idx+1];
    return ans;
  }
  else if(fs != NUM_SUITS) { //flush
    ans.ranking = FLUSH;
    size_t copy_idx = 0;
    for(size_t i = 0; i < hand->n_cards;i++) {
      if (hand->cards[i]->suit == fs){
	ans.cards[copy_idx] = hand->cards[i];
	copy_idx++;
	if (copy_idx >=5){
	  break;
	}
      }
    }
    return ans;
  }
  else if(find_straight(hand,NUM_SUITS, &ans)) {     //straight
    ans.ranking = STRAIGHT;
    return ans;
  }
  else if (n_of_a_kind == 3) { //3 of a kind
    return build_hand_from_match(hand, 3, THREE_OF_A_KIND, match_idx);
  }
  else if (other_pair_idx >=0) {     //two pair
    assert(n_of_a_kind ==2);
    ans = build_hand_from_match(hand, 2, TWO_PAIR, match_idx);
    ans.cards[2] = hand->cards[other_pair_idx];
    ans.cards[3] = hand->cards[other_pair_idx + 1];
    if (match_idx > 0) {
      ans.cards[4] = hand->cards[0];
    }
    else if (other_pair_idx > 2) {  //if match_idx is 0, first pair is in 01
      //if other_pair_idx > 2, then, e.g. A A K Q Q
      ans.cards[4] = hand->cards[2];
    }
    else {       //e.g., A A K K Q
      ans.cards[4] = hand->cards[4];
    }
    return ans;
  }
  else if (n_of_a_kind == 2) {
    return build_hand_from_match(hand, 2, PAIR, match_idx);
  }
  return build_hand_from_match(hand, 0, NOTHING, 0);
}

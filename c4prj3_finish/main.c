#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "cards.h"
#include "deck.h"
#include "eval.h"
#include "future.h"
#include "input.h"

int winning_hand(deck_t **deck_array,int n_hands){
  int w[n_hands+1];
  for(int i=0;i<n_hands+1;i++)
    w[i]=0;
  int v=0;
  for(int i=0;i<n_hands-1;i++){
    for(int j=i+1;j<n_hands;j++){
      v=compare_hands(deck_array[i],deck_array[j]);
      if(v>0) w[i]++;
      else if(v<0) w[j]++;
      else w[n_hands]++;
    }}
  unsigned largest=0;
  for (int x = 0; x < n_hands+1; x++){
    if (w[x] > w[largest]) largest = x;
  }
  int count=0;
  if (w[n_hands]> 0){
    for (int x = 0; x < n_hands + 1; x++){
      if (w[x] == w[largest]) count ++;
    }
  }
  if (count > 1) return n_hands;
  return largest;
}

int main(int argc, char ** argv) {
  //YOUR CODE GOES HERE
  if(argc<1 || argc>3){
    fprintf(stderr,"Invalid number of arguments");
    return EXIT_FAILURE;
  }
  else{
    FILE *f=fopen(argv[1],"r");
    if(f==NULL){
      fprintf(stderr,"Invalid input file");
      return EXIT_FAILURE;
    }
    size_t n_hands=0;
    future_cards_t *fc=malloc(sizeof(*fc));
    fc->n_decks=0;
    fc->decks=NULL;
    deck_t **decks=NULL;
    decks=read_input(f,&n_hands,fc);
    deck_t *rem_deck=NULL;
    rem_deck=build_remaining_deck(decks,n_hands);
    int count[n_hands+1];
    for(int i=0;i<n_hands+1;i++){
      count[i]=0;
    }
    int num_trials=10000;
    if(argc==3)
      num_trials=atoi(argv[2]);
    int index;
    for(int i=0;i<num_trials;i++){
      shuffle(rem_deck);
      future_cards_from_deck(rem_deck,fc);
      index=winning_hand(decks,n_hands);
      count[index]++;
  }
    for(size_t j=0;j<n_hands;j++){
      printf("Hand %zu won %u / %u times (%.2f%%)\n",j,count[j],num_trials,(((float) count[j])/num_trials)*100);
    }
    printf("And there were %u ties\n",count[n_hands]);
    for(int l=0;l<n_hands;l++){
      free_deck(decks[l]);
    }
    free(decks);
    for (int o = fc -> n_decks -1; o>=0; o--){
      if (fc -> decks[o].n_cards != 0) free(fc -> decks[o].cards);
    }
    free(fc -> decks);
    free(fc);
    free_deck(rem_deck);
    if (fclose(f) != 0){
      fprintf(stderr, "close file");
      return EXIT_FAILURE;
    }}
  return EXIT_SUCCESS;
}

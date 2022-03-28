#ifndef PLATEFORM_H
#define PLATEFORM_H

#include "train.h"

typedef struct Plateform {
  int plateform_id;
  Train *train;
} Plateform;

// Constructor of plateform
void init_plateform(Plateform **plateform, int plateform_id, Train *train){
  *plateform = (Plateform *)malloc(sizeof(Plateform *));
  (*plateform)->plateform_id = plateform_id;
  (*plateform)->train = train;
}

// show train in the plateform
void show_train(Plateform *plateform){
  printf("Train id: %d", plateform->train->id);
}

#endif
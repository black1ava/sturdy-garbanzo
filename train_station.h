#ifndef TRAIN_STATION_H
#define TRAIN_STATION_H

#include "plateform.h"

typedef struct TrainStation {
  Plateform *plateforms;
  int size;
  int index;
} TrainStation;

// Constructor for train station
void init_train_station(TrainStation **train_station, int number){
  *train_station = (TrainStation *)malloc(sizeof(TrainStation));
  (*train_station)->plateforms = (Plateform *)malloc(sizeof(Plateform) * number);
  (*train_station)->size = number;
  (*train_station)->index = 0;
}

// add plateform to the train
void add_plateform(TrainStation **train_station, Plateform *plateform){
  (*train_station)->plateforms[(*train_station)->index] = *plateform;
  (*train_station)->index++;
}

#endif
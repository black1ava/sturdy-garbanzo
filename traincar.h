#ifndef TRAINCAR_H
#define TRAINCAR_H

#include<stdio.h>
#include<stdlib.h>

typedef struct TrainCar {
  int weight;
  int id;
  struct TrainCar *next;
} TrainCar;


// Constructor for train car 
void init_train_car(TrainCar **trainCar, int id, int weight){
  *trainCar = (TrainCar *)malloc(sizeof(TrainCar *));
  (*trainCar)->weight = weight;
  (*trainCar)->id = id;
  (*trainCar)->next = NULL;
}

#endif
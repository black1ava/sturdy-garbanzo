#ifndef TRAIN_H
#define TRAIN_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "traincar.h"

typedef struct Train {
  int power;
  int id;
  struct TrainCar *head_train_car;
} Train;

// constructor for train
void init_train(Train **train, int train_id, int power){
  *train = (Train *)malloc(sizeof(Train *));
  (*train)->id = train_id;
  (*train)->power = power;
  (*train)->head_train_car = NULL;
}

// add a train car to the head for the train
void add_front_train_car(Train **train, int train_car_id, int train_car_weight){
  if((*train)->head_train_car == NULL){
    init_train_car(&(*train)->head_train_car, train_car_id, train_car_weight);
    return;
  }

  TrainCar *new_train_car = (TrainCar *)malloc(sizeof(TrainCar *));
  init_train_car(&new_train_car, train_car_id, train_car_weight);
  new_train_car->next = (*train)->head_train_car;
  (*train)->head_train_car = new_train_car;
}

// add a train car to the rear of the train
void add_last_train_car(Train **train, int train_car_id, int train_car_weight){
  if((*train)->head_train_car == NULL){
    init_train_car(&(*train)->head_train_car, train_car_id, train_car_weight);
    return;
  }

  TrainCar *tmp_train_car_head = (*train)->head_train_car;
  TrainCar *new_train_car = NULL;
  new_train_car = (TrainCar *)malloc(sizeof(TrainCar *));
  init_train_car(&new_train_car, train_car_id, train_car_weight);

  while(tmp_train_car_head->next != NULL){
    tmp_train_car_head = tmp_train_car_head->next;
  }

  tmp_train_car_head->next = new_train_car;
}

// add a train car to the middle of the train
void add_after_train_car(Train **train, int current_train_car_id, int train_car_id, int train_car_weight){
  TrainCar *tmp_train_car_head = (*train)->head_train_car;
  bool found_train_car = false;

  while(tmp_train_car_head != NULL){
    if(tmp_train_car_head->id == current_train_car_id){
      found_train_car = true;
      break;
    }

    tmp_train_car_head = tmp_train_car_head->next;
  }

  if(found_train_car){

    if(tmp_train_car_head->next == NULL){
      add_last_train_car(train, train_car_id, train_car_weight);
      return;
    }

    TrainCar *new_train_car = NULL;
    new_train_car = (TrainCar *)malloc(sizeof(TrainCar *));
    init_train_car(&new_train_car, train_car_id, train_car_weight);

    new_train_car->next = tmp_train_car_head->next;
    tmp_train_car_head->next = new_train_car;

    return;
  }

  printf("Train car with id `%d` not found\n", current_train_car_id);
  exit(-1);
}

//remove the front train car
void remove_front_train_car(Train **train){
  (*train)->head_train_car = (*train)->head_train_car->next;
}

//remove the last train car
void remove_last_train_car(Train **train){
  TrainCar *tmp_head_train_car = (*train)->head_train_car;

  while(tmp_head_train_car->next->next != NULL){
    tmp_head_train_car = tmp_head_train_car->next;
  }


  tmp_head_train_car->next = NULL;
}

//remove the middle train car
void remove_after_train_car(Train **train, int current_train_car_id){
  TrainCar *tmp_head_train_car = (*train)->head_train_car;
  bool found_train_car = false;

  while(tmp_head_train_car != NULL){
    if(tmp_head_train_car->id == current_train_car_id){
      found_train_car = true;
      break;
    }

    tmp_head_train_car = tmp_head_train_car->next;
  }

  if(found_train_car){

    if(tmp_head_train_car->next == NULL){
      printf("Train car with id `%d` is the last train car", current_train_car_id);
      exit(-1);
    }

    if(tmp_head_train_car->next->next == NULL){
      remove_last_train_car(train);
      return;
    }

    tmp_head_train_car->next = tmp_head_train_car->next->next;
    return;
  }

  printf("Train car with id `%d` not found", current_train_car_id);
  exit(-1);
}

// show all train cars of the train
void show_trian_cars(Train *train){
  TrainCar *tmp_head_train_car = train->head_train_car;

  while(tmp_head_train_car != NULL){
    printf("Train id: %d, weight: %d\n", tmp_head_train_car->id, tmp_head_train_car->weight);
    tmp_head_train_car = tmp_head_train_car->next;
  }
}

#endif
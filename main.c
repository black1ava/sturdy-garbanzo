#include "train.h"
#include "plateform.h"
#include "train_station.h"

int main(){

  Train *train1 = NULL;
  init_train(&train1, 1, 100);
  add_front_train_car(&train1, 1, 10);
  add_front_train_car(&train1, 2, 10);

  Train *train2 = NULL;
  init_train(&train2, 2, 100);
  add_front_train_car(&train2, 3, 100);
  add_front_train_car(&train2, 4, 100);

  Plateform *plateform1 = NULL;
  init_plateform(&plateform1, 1, train1);

  Plateform *plateform2 = NULL;
  init_plateform(&plateform2, 2, train2);

  TrainStation *train_station = NULL;
  init_train_station(&train_station, 2);
  add_plateform(&train_station, plateform1);
  add_plateform(&train_station, plateform2);

  show_train(plateform1);
  return 0;
}


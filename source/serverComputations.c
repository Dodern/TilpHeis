#include "serverComputations.h"

void ServerComputations__clearOrders(){
    for (int i = 0; i < N_FLOORS*3; i++){
        orders_[i] = 0;
    }
}
#ifndef SHOOT_H
#define SHOOT_H

#include "func.h"
#include "CauchyMod.h"

#define MYRAND_MAX 0.5
#define Min(a,b) (((a) < (b)) ? (a) : (b)) 

enum class  STATUS {
  OK = 0,
  ERROR
};

CauchyMod ShootMet(GridFunc const& grid, double(*funcR)(double, double, double), double B);

CauchyMod ShootMetMod(GridFunc const& grid, double(*funcR)(double, double, double), double B, double y0);

CauchyMod ShootMetUPD(GridFunc const& grid, double(*funcR)(double, double, double), double B);

#endif //SHOOT_H
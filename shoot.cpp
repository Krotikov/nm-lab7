#include "shoot.h"


CauchyMod ShootMetUPD(GridFunc const& grid, double(*funcR)(double, double, double), double B) {
  double der1 = 0.5;
  CauchyMod sol1(grid, funcR, der1);

  double der2 = -0.5;
  CauchyMod sol2(grid, funcR, der2);

  double f1 = sol1.resY[grid.numOfPoints - 1] - B;
  double f2 = sol2.resY[grid.numOfPoints - 1] - B;
  //double der3 = der2 - f2 * (der2 - der1) / (f2 - f1);
  double der3 = der1 + der2;
  CauchyMod sol3(grid, funcR, der3);

  return sol3;
}

CauchyMod ShootMetMod(GridFunc const& grid, double(*funcR)(double, double, double), double B, double y0) {
  double der1 = 0.5;
  CauchyMod sol1(grid, funcR, der1, y0);

  double der2 = -0.5;
  CauchyMod sol2(grid, funcR, der2, y0);

  double f1 = sol1.resY[grid.numOfPoints - 1] - B;
  double f2 = sol2.resY[grid.numOfPoints - 1] - B;
  //double der3 = der2 - f2 * (der2 - der1) / (f2 - f1);
  double der3 = der1 + der2;
  CauchyMod sol3(grid, funcR, der3, y0);

  return sol3;
}



CauchyMod ShootMet(GridFunc const& grid, double(*funcR)(double, double, double), double B) {
  srand(123);
  double randMax = MYRAND_MAX;
  double eps = 1e-9;

  int sign = (rand() % 2 == 0) ? 1 : -1;
  double der1 = sign * ((double)rand() / RAND_MAX * randMax);
  double der2 = -sign * ((double)rand() / RAND_MAX * randMax);

  CauchyMod sol1(grid, funcR, der1);
  CauchyMod sol2(grid, funcR, der2);

  double f1 = sol1.resY[grid.numOfPoints - 1] - B;
  double f2 = sol2.resY[grid.numOfPoints - 1] - B;
  double der3 = der2 - f2 * (der2 - der1) / (f2 - f1);

  CauchyMod sol3(grid, funcR, der3);

  return sol3;
}
#include "func.h"

double Func(double x, double y, double z) {
  double res = z * sin(x) - (y + 1) * cos(x) + 1;
  return res;
}

double FuncSol(double x) {
  double res = cos(x);
  return res;
}

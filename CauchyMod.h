#ifndef CAUCHYMOD_H
#define CAUCHYMOD_H

#include "GridFunc.h"

class CauchyMod{
public:
  CauchyMod() {}

  CauchyMod(GridFunc const& grid, double (*func)(double, double, double), double der);

  CauchyMod(GridFunc const& grid, double (*func)(double, double, double), double der, double y0);

  CauchyMod(CauchyMod const& sol);

  void swap(CauchyMod& sol) {
    std::swap(func, sol.func);
    std::swap(resY, sol.resY);
    std::swap(a, sol.a);
    std::swap(grid, sol.grid); 
  }

  CauchyMod& operator=(CauchyMod const& sol) {
    if (this != &sol)
      CauchyMod(sol).swap(*this);

    return *this;
  }

  double MaxErr();

  bool PrintErr(std::string fileName);

  bool PrintY(std::string fileName);

  ~CauchyMod() {
    delete[] resY;
  }

  point_t a;
  double der;
  double (*func)(double, double, double);
  GridFunc grid;
  double* resY;
};


#endif //CAUCHYMOD_H

#pragma once
#define _USE_MATH_DEFINES
#include "func.h"

typedef struct {
  double x;
  double y;
}point_t;


class GridFunc {
public:
  GridFunc() {}

  GridFunc(double lbord, double rbord, size_t numOfPoints, double (*func)(double));

  GridFunc(GridFunc const& grid);

  void swap(GridFunc& a) {
    std::swap(numOfPoints, a.numOfPoints);
    std::swap(func, a.func);
    std::swap(points, a.points);
  }

  GridFunc& operator=(GridFunc const& grid) {
    if (this != &grid)
      GridFunc(grid).swap(*this);

    return *this;
  }

  bool PrintGrid(std::string xfilename, std::string yfilename);

  ~GridFunc() {
    delete[] points;
  }

  size_t numOfPoints;
  point_t* points;
  double lbord;
  double rbord;
  double dx;
  double (*func)(double);
};
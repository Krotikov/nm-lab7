#include "GridFunc.h"

GridFunc::GridFunc(double lbord, double rbord, size_t numOfPoints, double (*func)(double))
  : numOfPoints(numOfPoints), func(func), lbord(lbord), rbord(rbord) {

  points = new point_t[numOfPoints];
  dx = (rbord - lbord) / (numOfPoints - 1);

  for (size_t i = 0; i < numOfPoints; ++i) {
    points[i].x = lbord + (double)i * dx;
    points[i].y = func(points[i].x);
  }
}

GridFunc::GridFunc(GridFunc const& grid)
  :numOfPoints(grid.numOfPoints), func(grid.func), points(new point_t[numOfPoints]), lbord(grid.lbord), rbord(grid.rbord), dx(grid.dx) {
  for (size_t i = 0; i < numOfPoints; ++i) {
    points[i].x = grid.points[i].x;
    points[i].y = grid.points[i].y;
  }
}

bool GridFunc::PrintGrid(std::string xfilename, std::string yfilename) {
  std::ofstream xout, yout;

  if (xfilename == "cout") {
    std::ostream& xout = std::cout;
  }
  else {
    xout.open(xfilename);
    if (!xout.is_open()) {
      return false;
    }
  }

  if (yfilename == "cout") {
    std::ostream& xout = std::cout;
  }
  else {
    yout.open(yfilename);
    if (!yout.is_open()) {
      return false;
    }
  }

  for (size_t i = 0; i < numOfPoints; i++) {
    xout << this->points[i].x << " ";
    yout << this->points[i].y << " ";
  }

  xout.close();
  yout.close();

  return true;
}
#include "CauchyMod.h"

//CauchyMod::CauchyMod(GridFunc const& grid, double (*func)(double, double, double), double der)
//  : grid(grid), func(func), a(grid.points[0]), resY(new double[grid.numOfPoints]), der(der) {
//
//  resY[0] = a.y;
//  double h = grid.dx;
//  double zi = der;
//
//  for (size_t i = 0; i < grid.numOfPoints - 1; ++i) {
//    double k1 = zi;
//    double q1 = func(grid.points[i].x, resY[i], k1);
//    double k2 = zi + q1 * h / 2.0;
//    double q2 = func((grid.points[i].x + h / 2.0), (resY[i] + k1 * h / 2.0), k2);
//    double k3 = zi + q2 * h / 2.0;
//    double q3 = func((grid.points[i].x + h / 2.0), (resY[i] + k2 * h / 2.0), k3);
//    double k4 = zi + q3 * h;
//    double q4 = func((grid.points[i].x + h), (resY[i] + k3 * h), k4);
//
//    zi += h / 6.0 * (q1 + 2 * q2 + 2 * q3 + q4);
//    resY[i + 1] = resY[i] + h / 6.0 * (k1 + 2 * k2 + 2 * k3 + k4);
//  }
//}

CauchyMod::CauchyMod(GridFunc const& grid, double (*func)(double, double, double), double der)
  : grid(grid), func(func), a(grid.points[0]), resY(new double[grid.numOfPoints]), der(der) {

  resY[0] = a.y;
  double h = grid.dx;
  double zi = der;

  for (size_t i = 0; i < grid.numOfPoints - 1; ++i) {
    double k1 = zi;
    double q1 = func(grid.points[i].x, resY[i], k1);
    double k2 = zi + q1 * h / 3.0;
    double q2 = func((grid.points[i].x + h / 3.0), (resY[i] + k1 * h / 3.0), k2);
    double k3 = zi - q1 * h / 3.0 + q2 * h;
    double q3 = func((grid.points[i].x + 2 * h / 3.0), (resY[i] - k1 * h / 3.0 + k2 * h), k3);
    double k4 = zi + q1 * h - q2 * h + q3 * h;
    double q4 = func((grid.points[i].x + h), (resY[i] + k1 * h - k2 * h + k3 * h), k4);

    zi += h / 8.0 * (q1 + 3 * q2 + 3 * q3 + q4);
    resY[i + 1] = resY[i] + h / 8.0 * (k1 + 3 * k2 + 3 * k3 + k4);
  }
}

CauchyMod::CauchyMod(GridFunc const& grid, double (*func)(double, double, double), double der, double y0)
  : grid(grid), func(func), a(grid.points[0]), resY(new double[grid.numOfPoints]), der(der) {

  resY[0] = y0;
  double h = grid.dx;
  double zi = der;

  for (size_t i = 0; i < grid.numOfPoints - 1; ++i) {
    double k1 = zi;
    double q1 = func(grid.points[i].x, resY[i], k1);
    double k2 = zi + q1 * h / 3.0;
    double q2 = func((grid.points[i].x + h / 3.0), (resY[i] + k1 * h / 3.0), k2);
    double k3 = zi - q1 * h / 3.0 + q2 * h;
    double q3 = func((grid.points[i].x + 2 * h / 3.0), (resY[i] - k1 * h / 3.0 + k2 * h), k3);
    double k4 = zi + q1 * h - q2 * h + q3 * h;
    double q4 = func((grid.points[i].x + h), (resY[i] + k1 * h - k2 * h + k3 * h), k4);

    zi += h / 8.0 * (q1 + 3 * q2 + 3 * q3 + q4);
    resY[i + 1] = resY[i] + h / 8.0 * (k1 + 3 * k2 + 3 * k3 + k4);
  }
}

CauchyMod::CauchyMod(CauchyMod const& sol)
  : grid(sol.grid), func(sol.func), a(sol.a), resY(new double[sol.grid.numOfPoints]), der(sol.der){

    for (size_t i = 0; i < sol.grid.numOfPoints; ++i) {
      resY[i] = sol.resY[i];
    }
}

double CauchyMod::MaxErr() {
  double max = 0;
  for (size_t i = 1; i < grid.numOfPoints; ++i) {
    double err = fabs(resY[i] - grid.points[i].y);
    if (max < err)
      max = err;
  }
  return max;
}

bool CauchyMod::PrintErr(std::string fileName) {
  std::ofstream out;

  if (fileName == "cout") {
    std::ostream& out = std::cout;
  }
  else {
    out.open(fileName);
    if (!out.is_open()) {
      return false;
    }
  }
  for (size_t i = 0; i < grid.numOfPoints; ++i) {
    double err = fabs(resY[i] - grid.points[i].y);
    out << err << " ";
  }
  out.close();
  return true;
}

bool CauchyMod::PrintY(std::string fileName) {
  std::ofstream out;

  if (fileName == "cout") {
    std::ostream& out = std::cout;
  }
  else {
    out.open(fileName);
    if (!out.is_open()) {
      return false;
    }
  }
  for (size_t i = 0; i < grid.numOfPoints; ++i)
    out << resY[i] << " ";

  out.close();
  return true;
}

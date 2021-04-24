#ifndef TEST_H
#define TEST_H

#include <cstdio>
#include "func.h"
#include "CauchyMod.h"
#include "shoot.h"

#define LBORD 0
#define RBORD 1.570796326794897
#define NUMP1 8
#define NUMP2 16
#define DER -0.5
#define B 0
#define NUM_DIST 32
#define NUMP_DIST 16
#define ORDER 4

void TestErr(double(*funcSol)(double), double(*funcR)(double, double, double));

void TestMaxErr(double(*funcSol)(double), double(*funcR)(double, double, double));

void TestDisturb(double(*funcSol)(double), double(*funcR)(double, double, double));

#endif //TEST_H

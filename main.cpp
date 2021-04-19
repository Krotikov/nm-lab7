#include "test.h"


int main() {

  TestErr(&FuncSol, &Func);

  TestMaxErr(&FuncSol, &Func);

  TestDisturb(&FuncSol, &Func);

  return 0;
}
#include <cstdlib>
#include <ctime>
#include "evaluator.hpp"

int main(void)
{
  srand(time(NULL));
  Evaluator* evaluator = new Evaluator();
  evaluator->run();
  delete evaluator;
  return 0;
}

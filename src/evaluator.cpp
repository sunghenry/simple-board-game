#include <iostream>
#include "evaluator.hpp"

Evaluator::Evaluator()
{
  _players[0] = new Random(0);
  _players[1] = new Charge(1);
  _game = new Game(_players[0], _players[1]);
}

Evaluator::~Evaluator()
{
  for (int i = 0; i < 2; i++)
    delete _players[i];
  delete _game;
}

void Evaluator::run(void)
{
  int i = 0;
  while (i  < _MAX_TRIAL) {
    _game->run();
    _game->reset();
    i++;
  }

  double chance1 = (double)_players[0]->getWinRecord() / _MAX_TRIAL * 100;
  double chance2 = (double)_players[1]->getWinRecord() / _MAX_TRIAL * 100;

  std::cout << "random player has " << chance1 << "% chance of beating a charge player" << std::endl;
  std::cout << "charge player has " << chance2 << "% chance of beating a random player" << std::endl;
}

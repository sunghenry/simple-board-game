#ifndef EVALUATOR_HPP
#define EVALUATOR_HPP

#include "player.hpp"
#include "game.hpp"

class Evaluator
{
  public:
    Evaluator();
    ~Evaluator();

    void run(void);

  private:
    const int _MAX_TRIAL = 1000;

    Player* _players[2];
    Game* _game;
};

#endif

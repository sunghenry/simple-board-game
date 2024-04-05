#ifndef GAME_HPP
#define GAME_HPP

#include "marker.hpp"
#include "player.hpp"

class Game
{
  public:
    Game();
    Game(Player* player1, Player* player2);
    ~Game();

    void run(void);
    void reset(void);

  private:
    void setStarter(void);
    bool checkWin(void);
    void swapTurns(void);

    const int _BOARD_LENGTH = 64;
    const int _DELAY_AMOUNT = 12;

    Marker _markers[2];

    Player* _current;
    Player* _opponent;
};

#endif

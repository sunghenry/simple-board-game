#include "game.hpp"

Game::Game() {}

Game::Game(Player* player1, Player* player2):
_current(player1), _opponent(player2)
{
  _markers[0] = Marker(_current->getId());
  _markers[1] = Marker(_opponent->getId());
}

Game::~Game() {};

void Game::run()
{
  setStarter();

  while (true) {
    switch(_current->chooseMove()) {
      case ROLL: {
        int amount = _current->rollDie();
        _current->getMarker()->move(amount, _BOARD_LENGTH);
        break;
      }
      case DELAY:
        _opponent->getMarker()->move(-_DELAY_AMOUNT, _BOARD_LENGTH);
        break;
    };

    if (checkWin()) {
      _current->addWin();
      break;
    }
    swapTurns();
  }
}

void Game::setStarter()
{
  _current->setMarker(&_markers[0]);
  _opponent->setMarker(&_markers[1]);
}

bool Game::checkWin()
{
  bool gameover = false;
  for (int i = 0; i < 2; i++) {
    if (_markers[i].getPosition() == _BOARD_LENGTH)
      gameover = true;
  }
  return gameover;
}

void Game::swapTurns()
{
  Player* dummy = _current;
  _current = _opponent;
  _opponent = dummy;
}

void Game::reset()
{
  for (int i = 0; i < 2; i++)
    _markers[i].reset();
}

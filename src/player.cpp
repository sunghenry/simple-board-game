#include <iostream>
#include "player.hpp"

Player::Player() {}
Player::Player(int id): _id(id) {}
Player::~Player() {}

int Player::rollDie()
{
  return (rand() % 6 + 1) + (rand() % 6 + 1);
}

MoveType Player::chooseMove()
{
  return ROLL;
}

int Player::getId()
{
  return _id;
}

int Player::getWinRecord()
{
  return _win_record;
}

Marker* Player::getMarker()
{
  return _marker;
}

void Player::addWin(void)
{
  _win_record++;
}

void Player::setMarker(Marker* marker)
{
  _marker = marker;
}

Random::Random() {}
Random::Random(int id): Player(id) {}
Random::~Random() {}

MoveType Random::chooseMove()
{
  if (rand() % 2 == 0)
    return ROLL;
  return DELAY;
}

Charge::Charge() {}
Charge::Charge(int id): Player(id) {}
Charge::~Charge() {}

MoveType Charge::chooseMove()
{
  return ROLL;
}

Safe::Safe() {}
Safe::Safe(int id): Player(id) {}
Safe::~Safe() {}

MoveType Safe::chooseMove(int opponent_position)
{
  if (_marker->getPosition() < opponent_position)
    return ROLL;
  return DELAY;
}

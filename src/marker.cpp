#include "marker.hpp"

Marker::Marker(): _position(0) {};

Marker::Marker(int id): _id(id), _position(0) {};

Marker::~Marker() {}

void Marker::move(int amount, int board_length)
{
  if (_position+amount <= board_length && _position+amount >= 0)
    _position += amount;
}

void Marker::reset()
{
  _position = 0;
}

int Marker::getId()
{
  return _id;
}

int Marker::getPosition()
{
  return _position;
}

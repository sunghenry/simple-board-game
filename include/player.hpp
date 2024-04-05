#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "marker.hpp"

enum MoveType
{
  ROLL,
  DELAY
};

class Player
{
  public:
    Player();
    Player(int id);
    virtual ~Player();

    int rollDie(void);
    virtual MoveType chooseMove(void);
    int getId(void);
    int getWinRecord(void);
    Marker* getMarker(void);
    void addWin(void);
    void setMarker(Marker*);

  protected:
    int _id;
    int _win_record;
    Marker* _marker;
};

class Random: public Player
{
  public:
    Random();
    Random(int id);
    ~Random();

    MoveType chooseMove(void);
};

class Charge: public Player
{
  public:
    Charge();
    Charge(int id);
    ~Charge();

    MoveType chooseMove(void);
};

class Safe: public Player
{
  public:
    Safe();
    Safe(int id);
    ~Safe();

    MoveType chooseMove(int opponent_position);
};

#endif

#ifndef MARKER_HPP
#define MARKER_HPP

class Marker
{
  public:
    Marker();
    Marker(int id);
    ~Marker();

    void move(int amount, int board_length);
    void reset(void);
    int getId(void);
    int getPosition(void);

  private:
    int _id;
    int _position;
};

#endif

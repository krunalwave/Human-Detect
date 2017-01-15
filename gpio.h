
#ifndef GPIO_H
#define GPIO_H

#include <QFile>

#define GPIO_POL_POSITIVE true
#define GPIO_POL_NEGATIVE false
#define GPIO_INPUT true
#define GPIO_OUTPUT false

class gpio {

  QFile fi;
  QString name;
  bool direction;
  bool polarity;
  int currentLevel;


public:
  gpio();
  ~gpio();
  QString getName();
  int getHandle();
  bool getDirection();

  bool open(bool Direction, bool Polarity, QString Name);
  bool open(bool Direction, bool Polarity, QString edge, QString Name);
  bool close();
  bool setEdge(QString edge);
  int read();
  void write(int value);
  void toggle();
};

#endif // GPIO_H


#include "gpio.h"
#include <fcntl.h>
#include <stdio.h>
#include <poll.h>
#include <QtDebug>

  gpio::gpio()
  {
    this->name = "";
    this->direction = 1;
    this->currentLevel = 1;
  }


  gpio::~gpio()
  {
      if (this->fi.isOpen()) this->close();
  }

  bool gpio::open(bool Direction, bool Polarity, QString Name)
  {
    if (this->fi.isOpen()) this->close();
    this->name=Name;
    this->direction=Direction;
    this->polarity=Polarity;

    QFile exp("/sys/class/gpio/export");
    if (!exp.open(QIODevice::WriteOnly | QIODevice::Text)) return false;
    exp.seek(0);
    exp.write(Name.toAscii());
    exp.close();

    QFile dir("/sys/class/gpio/gpio"+Name+"/direction");
    if (!dir.open(QIODevice::WriteOnly | QIODevice::Text)) return false;
    dir.seek(0);
    if (Direction==GPIO_INPUT)  {
        dir.write("in");
        this->fi.setFileName("/sys/devices/virtual/gpio/gpio"+Name+"/value");
        if (!this->fi.open(QIODevice::ReadOnly | QIODevice::Unbuffered)) return false;
        this->read();  //update currentLevel;
    }else {
        dir.write("out");
        this->fi.setFileName("/sys/devices/virtual/gpio/gpio"+Name+"/value");
        if (!this->fi.open(QIODevice::WriteOnly  | QIODevice::Text)) return false;
    }
    dir.close();

    return true;
  }

  bool gpio::open(bool Direction, bool Polarity, QString edge, QString Name)
  {
      if (open(Direction, Polarity, Name))
          return setEdge(edge);
      else return false;
  }

  bool gpio::setEdge(QString edge)
  {
    QFile edg("/sys/class/gpio/gpio"+this->name+"/edge");
    if (!edg.open(QIODevice::ReadWrite | QIODevice::Text)) return false;
    edg.seek(0);
    edg.write("none"); //Seems to be required to release interrupt that could have been previously requested
    edg.seek(0);
    edg.write(edge.toAscii());
    edg.seek(0);
    QString e = edg.read(edge.length());
    edg.close();
    return (e==edge);
  }

    //private member access functions, used by gpio_monitor
  QString gpio::getName() {return this->name;}
  int gpio::getHandle() {return this->fi.handle();}
  bool gpio::getDirection() {return this->direction;}

  bool gpio::close()
  {
    QFile unexp("/sys/class/gpio/unexport");
    if (!unexp.open(QIODevice::WriteOnly | QIODevice::Text)) return false;
    unexp.seek(0);
    unexp.write(this->name.toAscii());
    unexp.close();

    this->fi.close();
    return true;
  }


  int gpio::read()
  {
      char val;
      if (this->direction == GPIO_INPUT && this->fi.isOpen()) {
           this->fi.seek(0);
           this->fi.getChar(&val);
           if (val=='0') this->currentLevel= 0; else this->currentLevel= 1;
           if (this->polarity == GPIO_POL_POSITIVE) return this->currentLevel; else return !this->currentLevel;
      }
      return -1;
  }

  void gpio::write(int value)
  {
       if (this->direction == GPIO_OUTPUT && this->fi.isOpen()) {
           this->fi.seek(0);
           this->currentLevel = value;
           if (this->polarity == GPIO_POL_NEGATIVE) value = (!value & 0x01) ;
           if (value == 1) this->fi.write("1"); else this->fi.write("0");
           fi.flush();
      }
  }

  void gpio::toggle()
  {
       if (this->direction == GPIO_OUTPUT && this->fi.isOpen()) {
           this->fi.seek(0);
           if (this->currentLevel == 1) {
               this->fi.write("0");
               this->currentLevel = 0;
           }else {
               this->fi.write("1");
               this->currentLevel = 1;
           }
           fi.flush();
      }
  }

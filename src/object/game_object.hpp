#pragma once

#include <iostream>

class GameObject {
public:
  virtual void draw() = 0;
  virtual void update() = 0;
  virtual void clean() = 0;

  virtual void up() = 0;
  virtual void down() = 0;
};

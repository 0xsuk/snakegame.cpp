#include <iostream>

bool gameover;
const int width{20};
const int height{20};
int x, y, fruit_x, fruit_y, score;
enum direction { stop, left, right, up, down };
direction dir;

void setup() {
  gameover = false;
  dir = stop;
  x = width / 2;
  y = height / 2;
  fruit_x = rand() % width;
  fruit_y = rand() % height;
  score = 0;
}

void draw() {
  const std::string gutter = "#";
  std::string map;
  for (int i{0}; i < width; i++) map += gutter;
  map += "\n";
  for (int i{0}; i < height; i++) {
    for (int j{0}; j < width; j++) {
      if (j == 0 || j == width - 1)
        map += gutter;
      else if (i == y && j == x) {
        map += "O";
      } else if (i == fruit_y && j == fruit_x) {
        map += "F";
      } else
        map += " ";
    }
    map += "\n";
  }
  for (int i{0}; i < width; i++) map += gutter;
  map += "\n";

  std::cout << map;
}

void input() {}

void logic() {}

int main() {
  setup();
  while (!gameover) {
    draw();
    input();
    logic();
  }

  std::cout << "Game Over\n";
  return 0;
}

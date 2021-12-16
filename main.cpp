/** Driver for the notakto game.
@file main.cpp
@author MICHAEL URQUIZA
*/

#include <iostream>
#include "notakto.h"
using namespace std;

int main() {
  int game = 1;
  while (game) {
    system("CLS");
    game = Notakto();
  }
  return 0;
}  // Main End

/** Implementation of notakto's game logic
@file notakto.cpp
@author Michael Urquiza
*/

#include <iostream>
using namespace std;

#define FI(i, a, b) for (int i = (a); i < (b); i++)

void draw_board(const bool board[3][3]) {
  int count = 0;
  FI(i, 0, 3) {
    cout << "-------------\n";
    FI(i, 0, 3) { cout << "| " << count + 1 + i << " "; }
    cout << "|" << endl;
    count += 3;
    cout << "|";
    FI(j, 0, 3) {
      if (board[i][j]) {
        cout << " X ";
      } else {
        cout << "   ";
      }
      cout << "|";
    }
    cout << endl;
  }
  cout << "-------------\n";
}

bool has_line(const bool board[3][3]) {
  FI(i, 0, 3) {
    if (board[i][0] == true && board[i][1] == true && board[i][2] == true) {
      return true;
    } else if (board[0][i] == true && board[1][i] == true &&
               board[2][i] == true) {
      return true;
    } else if (board[0][0] == true && board[1][1] == true &&
               board[2][2] == true) {
      return true;
    } else if (board[2][0] == true && board[1][1] == true &&
               board[0][2] == true) {
      return true;
    }
  }
  return false;
}

bool place_x(bool board[3][3], int idx) {
  if (idx >= 1 && idx <= 9) {
    int i = 0;
    int idx_cpy = idx - 1;
    while (idx_cpy > 0) {
      if (idx_cpy % 3 == 0) {
        ++i;
      }
      --idx_cpy;
    }
    while (idx > 3) {
      idx -= 3;
    }
    if (board[i][idx - 1] == false) {
      board[i][idx - 1] = true;
      return true;
    }
  }
  return false;
}

int Notakto(void) {
  int input;
  bool game = true;
  bool player1 = true;
  bool player2 = false;
  // Initialize an empty board
  bool board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  draw_board(board);

  while (game) {
    if (player1) {
      cout << "Player 1's turn (Enter a location to place X):" << endl;
    } else {
      cout << "Player 2's turn (Enter a location to place X):" << endl;
    }

    cin >> input;

    while (place_x(board, input) == false) {
      cout << "Location invalid or already taken. Please try again." << endl;
      cin >> input;
    }

    draw_board(board);

    if (has_line(board) == true) {
      if (player1 && !player2) {
        cout << "Player 2 wins!" << endl;
        game = false;
      } else if (player2 && !player1) {
        cout << "Player 1 wins!" << endl;
        game = false;
      }
    }  // If End

    // Switch Players
    if (player1) {
      player2 = true;
      player1 = false;
    } else {
      player1 = true;
      player2 = false;
    }

  }  // Game Loop End

  char replay;
  cout << "Play again? (y/n): ";
  cin >> replay;
  if (replay == 'n') {
    return 0;
  }
  return 1;
}

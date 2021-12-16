/** Header file for notakto.cpp
@file notakto.h
@author Michael Urquiza
*/

#ifndef NOTAKTO_H
#define NOTAKTO_H

// Given a notakto board as a 2D bool array, draw it out to standard output.
void draw_board(const bool board[3][3]);

// Given a notakto board as a 2D bool array, return whether it has a line of 3
// X's (true's).
bool has_line(const bool board[3][3]);

/* Place an X (true) on the notakto board at the given index, then return true.
 If the index is invalid, return false.
 If the board already contains an X (true) at that index, return false.
*/
bool place_x(bool board[3][3], int idx);

// Creates the board and runs through the entire game logic. Returns 1 to main if
// the user chooses to replay, returns 0 otherwise.
int Notakto(void);

#endif 
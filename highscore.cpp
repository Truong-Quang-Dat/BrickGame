#include <fstream>
#include <string.h>
#include <iostream>

fstream hs_file;
typedef struct player {
  string name;
  int score;
}
data;
data player[10];
bool openfile(bool resetscore = false) {
  if (resetscore) {
    hs_file.open("data/highscore", ofstream::out | ofstream::trunc);
  } else {
    hs_file.open("data/highscore");
  }
  if (hs_file.is_open()) {
    return true;
  } else {
    return false;
  }
}
// Reading scores from file
bool returnscore(bool just_highscore = false) {
  if (openfile()) {
    if (just_highscore) {
      hs_file >> player[0].score >> player[0].name;
    } else {
      for (int i = 0; i < 10; i++) {
        hs_file >> player[i].score >> player[i].name;
      }
    }
  } else {
    cout << "ERROR OPENING FILE TO READ DATA";
    return false;
  }
  hs_file.close();
  return true;
}
//initializing scores
void File_Init() {
  returnscore(true);
  int score_init = player[0].score;
  if (score_init == -1 || score_init == NULL) {
    openfile(true);
    hs_file.close();
  }
  return;
}
//Check struct for sorting
bool sortchecker(data a, data b) {
  if (a.score >= b.score)
    return 1;
  else
    return 0;
}
//Sort scores decending
void sortscores() {
  sort(player, player + 10, sortchecker);
}
//Save scores on file decending order
bool savescore(int score, string name) {
  returnscore();
  player[9].score = score;
  cout << player[9].score;
  player[9].name = name;
  cout << " " << player[9].name;
  sortscores();
  if (openfile(true)) {
    for (register int i = 0; i < 10; i++) {
      hs_file << player[i].score << " " << player[i].name << endl;
    }
  } else {
    cout << "ERROR OPENIN FILE FOR SAVING DATA";
    hs_file.close();
    return false;
  }
  hs_file.close();
  return true;
}
//To check player score while playing
bool checkscore() {
  returnscore();
  sortscores();
  if (playerscore > player[9].score) {
    return true;
  } else {
    return false;
  }
}

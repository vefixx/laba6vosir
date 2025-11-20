#ifndef KRESTIKINOLIKI2_GAME_H
#define KRESTIKINOLIKI2_GAME_H

#include <vector>

using namespace std;

void GameLoop();
void WriteField(int, const vector<vector<int>>&);
void InputStep(int&, int&);
bool HandleStep(int, int, string, vector<vector<int>>&);
bool CheckWin(const vector<vector<int>>& field);

#endif //KRESTIKINOLIKI2_GAME_H
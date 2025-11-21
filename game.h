#ifndef GAME_H
#define GAME_H
#include <vector>
#include <string>

using namespace std;

void GameLoop();
void WriteField(int, const vector<vector<int>>&);
void InputStep(int&, int&);
bool HandleStep(int, int, string, vector<vector<int>>&);
bool CheckWin(const vector<vector<int>>& field);

#endif // GAME_H

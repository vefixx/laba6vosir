#include "game.h"
#include <iostream>
#include "game.h"
#include <vector>

#include "utils.h"

using namespace std;

void WriteField(int step_count, const vector<vector<int> > &field) {
  cout << "Игровое поле (Ход: " << step_count + 1 << "):" << endl;
  cout << "-------------" << endl;
  for (int row = 0; row < 3; row++) {
    cout << "|";
    for (int column = 0; column < 3; column++) {
      int value = field[row][column];
      switch (value) {
        case -1:
          cout << " * |";
          break;
        case 0:
          cout << " O |";
          break;
        case 1:
          cout << " X |";
          break;
        default: break;
      }
    }

    cout << endl << "-------------" << endl;
  }
}

void InputStep(int &row, int &column) {
  while (true) {
    cout << "Введите номер строки и столбца хода через пробел: ";
    cin >> row >> column;

    if ((row > 3 || row < 1) || (column > 3 || column < 1)) {
      cout << "Неверный ввод (строка или столбец не находится в диапазоне 1<=n<=3" << endl;
      continue;
    }

    break;
  }
}

bool HandleStep(int row, int column, string current_step, vector<vector<int> > &field) {
  int field_step_code = current_step == "н" ? 0 : 1;

  if (field[row - 1][column - 1] != -1) {
    cout << "Ячейка уже была сыграна" << endl;
    return false;
  }

  field[row - 1][column - 1] = field_step_code;
  return true;
}

bool CheckWin(vector<vector<int> > &field) {
  for (int i = 0; i < 3; i++) {
    if (field[i][0] == 0 && field[i][1] == 0 && field[i][2] == 0) {
      return true;
    }
    if (field[i][0] == 1 && field[i][1] == 1 && field[i][2] == 1) {
      return true;
    }
  }

  for (int i = 0; i < 3; i++) {
    if (field[0][i] == 0 && field[1][i] == 0 && field[2][i] == 0) {
      return true;
    }
    if (field[0][i] == 1 && field[1][i] == 1 && field[2][i] == 1) {
      return true;
    }
  }

  if (field[0][0] == 0 && field[1][1] == 0 && field[2][2] == 0) {
    return true;
  }
  if (field[0][0] == 1 && field[1][1] == 1 && field[2][2] == 1) {
    return true;
  }

  if (field[0][2] == 0 && field[1][1] == 0 && field[2][0] == 0) {
    return true;
  }
  if (field[0][2] == 1 && field[1][1] == 1 && field[2][0] == 1) {
    return true;
  }

  return false;
}


void GameLoop() {
  int current_player = 0, n, step_count = 0;
  string current_step;
  vector<vector<int> > field = {
    {-1, -1, -1},
    {-1, -1, -1},
    {-1, -1, -1},
  };

  while (true) {
    cout << "Выберите игрока, который будет ходить первый ('1'/'2'), а также его ход ('н'/'к') (через пробел): ";
    cin >> current_player >> current_step;

    if ((current_player != 1 && current_player != 2) || (current_step != "н" && current_step != "к")) {
      cout << "Неверный ввод" << endl;
      continue;
    }
    break;
  }


  int row, column;
  while (true) {
    ClearConsole();
    WriteField(step_count, field);

    cout << "Ход игрока №" << current_player << " (" << current_step << "): ";
    bool success_step = false;
    while (!success_step) {
      InputStep(row, column);
      success_step = HandleStep(row, column, current_step, field);
    }

    step_count++;

    bool is_win_step = CheckWin(field);

    if (step_count >= 5 && is_win_step) {
      ClearConsole();
      WriteField(step_count, field);

      cout << "Победа игрока №" << current_player << " (" << current_step << ")!" << endl;
      break;
    } else if (step_count == 9) {
      cout << "Ничья!" << endl;
      break;
    } else {
      current_step = current_step == "н" ? "к" : "н";
      current_player = current_player == 1 ? 2 : 1;
    }
  }
}

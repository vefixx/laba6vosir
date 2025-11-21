#include <iostream>
#include "windows.h"

#include "game.h"
#include "utils.h"

using namespace std;

int main() {
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);

  cout << "Нажмите Enter, чтобы начать игру...";
  cin.get();

  string a;

  while (true) {
    ClearConsole();
    GameLoop();

    cout << "Желаете сыграть еще раз? (да/нет): ";
    cin >> a;

    if (a == "да")
      continue;
    cout << "Вы закрыли игру.";
    break;
  }

  return 0;
}
#include <iostream>
#include <ncurses.h>

void up() {}

int main() {
  int ch;
  printf("aaa\nbbb\nccc\n");
  up();

	wmove(stdscr, 0, 0);
  while ((ch = getchar()) != 'E') {
    if (ch == 27) // ESC
      break;
    if (ch == KEY_UP)
      up();
    if (ch == KEY_DOWN)
      down();
    if (ch == KEY_LEFT)
      left();
    if (ch == KEY_RIGHT)
      right();
    if (ch == KEY_HOME)
      home();
    if (ch == KEY_END)
      end();
    if (ch == KEY_PPAGE)
      ppage();
    if (ch == KEY_NPAGE)
      npage();
    if (ch == KEY_F(1))
      F1();
    if (ch == KEY_F(2))
      F2();
    if (ch == KEY_F(3))
      F3();
    if (ch == KEY_F(4))
      F4();
    if (ch == KEY_F(5))
      F5();
    if (ch == KEY_F(6))
      F6();
    if (ch == KEY_F(7))
      F7();
    if (ch == KEY_F(8))
      F8();
    if (ch == KEY_F(9))
      F9();
    if (ch == KEY_F(10))
      F10();
    if (ch == KEY_F(11))
      F11();
    if (ch == KEY_F(12))
      F12();
  }
  return 0;
}
}

printf("\nExiting Now\n");

return 0;
}

// 27 91 65 10 UP
// 27 91 66 10 DOWN
// 27 91 67 10 RIGHT
// 27 91 68 10 LEFT
// 27 91 77 10 F1

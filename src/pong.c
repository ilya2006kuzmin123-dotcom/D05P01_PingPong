#include <stdio.h>

void drawField(int ball_x, int ball_y, int paddle1_y, int paddle2_y, int score1,
               int score2) {
  int WIDTH = 80;
  int HEIGHT = 25;
  int PADDLE_HALF_SIZE = 1;
  int PADDLE1_X = 3;
  int PADDLE2_X = (WIDTH - 4);
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      if (y == 0 || y == HEIGHT - 1) {
        printf("#");
      } else if (x == PADDLE1_X && (y >= paddle1_y - PADDLE_HALF_SIZE &&
                                    y <= paddle1_y + PADDLE_HALF_SIZE)) {
        printf("|");
      } else if (x == PADDLE2_X && (y >= paddle2_y - PADDLE_HALF_SIZE &&
                                    y <= paddle2_y + PADDLE_HALF_SIZE)) {
        printf("|");
      } else if (x == ball_x && y == ball_y) {
        printf("O");
      } else if (x == 40) {
        printf("|");
      } else if (y == 2 && x == 36) {
        printf("%d", score1);
      } else if (y == 2 && x == 44) {
        printf("%d", score2);
      } else {
        if (x == 0 || x == WIDTH - 1) {
          printf("#");
        } else {
          printf(" ");
        }
      }
    }
  }
}

int main() {
  char key = ' ';
  int ball_x = 40;
  int ball_y = 13;
  int paddle1_y = 13;
  int paddle2_y = 13;
  int score1 = 0;
  int score2 = 0;
  int s = -1;
  drawField(ball_x, ball_y, paddle1_y, paddle2_y, score1, score2);
  while (ball_x != 0 && ball_x != 80) {
    key = getchar();
    if (key == '\n') {
      continue;
    }
    if (key == 'a') {
      paddle1_y -= 1;
    }
    if (ball_x == 76 && (ball_y == paddle2_y - 1 || ball_y == paddle2_y ||
                         ball_y == paddle2_y + 1)) {
      s = s * -1;
    }
    if (ball_x == 3 && (ball_y == paddle1_y - 1 || ball_y == paddle1_y ||
                        ball_y == paddle1_y + 1)) {
      s = s * -1;
    }
    ball_x += 1;
    drawField(ball_x, ball_y, paddle1_y, paddle2_y, score1, score2);
  }
  return 0;
}
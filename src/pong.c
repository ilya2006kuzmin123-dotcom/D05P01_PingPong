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
        if (score1 >= 10) {
          x++;
        }
      } else if (y == 2 && x == 44) {
        printf("%d", score2);
        if (score2 >= 10) {
          x++;
        }
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
  int s = 1;
  int s_y;
  drawField(ball_x, ball_y, paddle1_y, paddle2_y, score1, score2);
  while (score1 != 21 && score2 != 21) {
    ball_x = 40;
    ball_y = 13;
    paddle1_y = 13;
    paddle2_y = 13;
    s_y = 0;
    while (ball_x > 2 && ball_x < 78) {
      key = getchar();
      if (key == '\n') {
        continue;
      }
      if (key == 'a' && paddle1_y > 2) {
        paddle1_y -= 1;
      }
      if (key == 'z' && paddle1_y < 22) {
        paddle1_y += 1;
      }
      if (key == 'k' && paddle2_y > 2) {
        paddle2_y -= 1;
      }
      if (key == 'm' && paddle2_y < 22) {
        paddle2_y += 1;
      }
      if (ball_x == 75 && ball_y == paddle2_y) {
        s = s * -1;
        s_y = 0;
      }
      if (ball_x == 75 && ball_y == paddle2_y - 1) {
        s = s * -1;
        s_y = -1;
      }
      if (ball_x == 75 && ball_y == paddle2_y + 1) {
        s = s * -1;
        s_y = 1;
      }
      if (ball_x == 4 && ball_y == paddle1_y) {
        s = s * -1;
        s_y = 0;
      }
      if (ball_x == 4 && ball_y == paddle1_y - 1) {
        s = s * -1;
        s_y = -1;
      }
      if (ball_x == 4 && ball_y == paddle1_y + 1) {
        s = s * -1;
        s_y = 1;
      }
      if (ball_y >= 23) {
        s_y = -s_y;
      }
      if (ball_y <= 1) {
        s_y = -s_y;
      }
      ball_x += s;
      ball_y += s_y;
      if (ball_x == 78) {
        score1 += 1;
      }
      if (ball_x == 2) {
        score2 += 1;
      }
      drawField(ball_x, ball_y, paddle1_y, paddle2_y, score1, score2);
    }
  }
  if (score1 > score2) {
    printf("Игрок 1 победил!");
  } else {
    printf("Игрок 2 победил!");
  }
  return 0;
}
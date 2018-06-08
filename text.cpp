#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* macros */
#define MAX 17

int main(void) {
  //変数の定義を実際に使っているところの近くにするのは読みやすくなる。
  /* ファイルのオープン */
  FILE *fp;
  const char *filename = "dictionary";
  if ((fp = fopen(filename, "r")) ==
      NULL) {  // ちゃんとエラーを確認するのは良いことです＾＾
    fprintf(stderr, "%sのオープンに失敗しました.\n", filename);
    exit(EXIT_FAILURE);
  }

  //文字列を与える
  printf("文字列を入力してください\n");
  char ch[MAX];  // MAXを変えたらこの部分も変わって欲しいので
  scanf("%s", ch);

  char ex[MAX];
  strcpy(ex, ch);

  /* ファイルの終端まで文字を読み取り表示する */
  char str[MAX];
  char result[MAX];
  int sc = 0;
  while (fgets(str, MAX - 1, fp) != NULL) {
    strcpy(ch, ex);
    int a = 1;
    int score = 1;
    for (int i = 0; i < strlen(str); ++i) {
      int j;
      for (j = 0; j < strlen(ch) && str[i] != ch[j]; ++j) {
      }
      if(j < strlen(ch)){
        a++;
        ch[j] = '1';
        if (str[i] == 'j' || str[i] == 'k' || str[i] == 'q' || str[i] == 'x' ||
            str[i] == 'z') {
          score = score + 3;
        } else if (str[i] == 'c' || str[i] == 'f' || str[i] == 'h' ||
                   str[i] == 'l' || str[i] == 'm' || str[i] == 'p' ||
                   str[i] == 'v' || str[i] == 'w' || str[i] == 'y') {
          score = score + 2;
        } else {
          score++;
        }
      }
    }

    if (a == strlen(str)) {
      if (sc < score) {
        strcpy(result, str);
        sc = score;
      }
    }
  }

  printf("結果：%s\n", result);

  /* ファイルのクローズ */
  fclose(fp);

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* macros */
#define N 72412
#define MAX 16

int main(void)
{
	//変数の定義
	FILE *fp;
    char *filename = "dictionary";
	char readline[N] = {'\0'};
	int i, j, k, count;
	int a, b;
	char ch[17];
	char str[17];
	char st[17] = "read";
	char c;
	char ex[17];
	char result[17];
	int score, sc;
	

	/* ファイルのオープン */
    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "%sのオープンに失敗しました.\n", filename);
        exit(EXIT_FAILURE);
    }
	
	//文字列を与える
	printf("文字列を入力してください\n");
	scanf("%s", ch);
	
	strcpy(ex,ch);
	
	/* ファイルの終端まで文字を読み取り表示する */
	while ( fgets(str, MAX,fp) != NULL ) {
		strcpy(ch,ex);
		a = 1;
		score = 1;
		for(i = 0; i < strlen(str); ++i){
			for(j = 0; j < strlen(ch) && str[i] != ch[j]; ++j){
			}
			if(j < strlen(ch)){
				a++;
				ch[j] = '1';
				if(str[i] == 'j' || str[i] == 'k' || str[i] == 'q' || str[i] == 'x' || str[i] == 'z'){
					score = score + 3;
				}else if(str[i] == 'c' || str[i] == 'f' || str[i] == 'h' || str[i] == 'l' || str[i] == 'm' || str[i] == 'p' || str[i] == 'v' || str[i] == 'w' || str[i] == 'y'){
					score = score + 2;
				}else{
					score++;
				}
			}
		}
	
		if(a == strlen(str)){
			if(sc < score){
				strcpy(result,str);
				sc = score;
			}
		}else{
		}
	
	}
	
	printf("結果：%s\n", result);

	/* ファイルのクローズ */
	fclose(fp);
	
    return 0;
}

#include <stdio.h>
#include <string.h>

#define MAX_ARRAY 200

int search(char ch, int n, char str[])
{
    int idx = -1;
    for (int i=0; i<n; i++){
        if (str[i] == ch) idx = i;
    }
    return idx +1;
}

int ctoi(char c){
    switch(c){
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        case '0': return 0;
    }
}

void insert(int idx, char ch, char str[]) {
    memmove(str+idx+1, str+idx, strlen(str)-idx+1);
    str[idx] = ch;
}


void eliminate(char *str, char ch) {
    for (; *str != '\0'; str++) { //종료 문자를 만날 때까지 반복
        if (*str == ch) { //ch와 같은 문자일 때
            strcpy(str, str + 1);
            str--;
        }
    }
}




int main(){

    char s1[] = "+98989898989898989898989898.9898989898989898989898";//"+989898989898989898989898989898989898989898989898";
    printf("s1: %s\n", s1);
    char s1_1[MAX_ARRAY];

    char s2[] = "+121212121212121212121212.1212121212121212";//"+1212121212121212121212121212121212121212";
    printf("s2: %s\n", s2);
    char s2_1[MAX_ARRAY];

    char s3[MAX_ARRAY] = " ";
    int result[MAX_ARRAY] = {0, };

    strcpy(s1_1, s1);
    strcpy(s2_1, s2);

    int multi = 0; 
    int tens = 0;
    int ones = 0;

    //소수점 위치
    int idx1 = search('.', strlen(s1), s1);
    if(idx1!=0) {
        idx1 = strlen(s1) - idx1 -1;
        printf("idx1: %d\n", idx1);
    }

    int idx2 = search('.', strlen(s2), s2);
    if(idx2!=0) {
        idx2 = strlen(s2) - idx2 -1;
        printf("idx2: %d\n", idx2);
    }

    int point = idx2 + idx1 +1;
    printf("point: %d\n", point);

    //소수점 제거
    for(int i=0; i<strlen(s1); i++) {
        if (s1[i]=='.') {
            eliminate(s1,'.');
        }
    }
    printf("s1 without point: %s\n", s1);

    for(int j=0; j<strlen(s2); j++) {
        if (s2[j]=='.') {
            eliminate(s2,'.');
        }
    }
    printf("s2 without point: %s\n", s2);

    //한 숫자가 0일 경우
    //todo: 예외처리
    int slen1=strlen(s1);
    int slen2=strlen(s2);
   if (slen1==1 || slen2==1) {
        if(s1[0]=='0' || s2[0]=='0') {
            printf("result: 0\n");
            return 0;
        }
    }

    //result[] 모든 값을 0으로 설정
    for(int i=0;i<=MAX_ARRAY;i++)
        result[i]=0;

    // 곱하는 과정
    for(int i=strlen(s1)-1; i>=1; i--){
            int temp1 = ctoi(s1[i]);
        for(int j=strlen(s2)-1; j>=1; j--){
            int temp2 = ctoi(s2[j]);
            multi = temp1*temp2;
            result[MAX_ARRAY -strlen(s1)+i -strlen(s2)+j] += multi;
            while(1) {
                if(result[MAX_ARRAY -strlen(s1)+i -strlen(s2)+j] >= 10){
                result[MAX_ARRAY -strlen(s1)+i -strlen(s2)+j] -= 10;
                result[MAX_ARRAY -strlen(s1)+i -strlen(s2)+j -1] += 1;
                }
                else {
                    break;
                }
            }
        }
    }

    printf("%s", s1_1);
    printf(" * ");
    printf("%s", s2_1);
    printf(" = ");

    // 부호 판별
    if((s1[0] == '-' && s2[0] == '-') || (s1[0] != '-' && s2[0] != '-' ))
      printf("+");
    else {
        printf("-");
    }


    //소수점 삽입 후 프린트
    for(int i=0; i<MAX_ARRAY; i++) {
        if (MAX_ARRAY-i == point) {
            printf(".");
            printf("%d", result[i]);
        }
        else {
            printf("%d", result[i]); 
        }
    }

    return 0;
}
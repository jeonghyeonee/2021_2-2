#include <stdio.h>
#include <string.h>

void insert(int idx, char ch, char str[]){
    memmove(str+idx+1, str+idx, strlen(str)-idx+1);
    str[idx] = ch;
}

void append(char ch, char str[])
{
     insert(strlen(str), ch, str);
}



int search(char ch, int n, char str[])
{
    int idx = -1;
    for (int i=0; i<n; i++){
        if (str[i] == ch) idx = i;
    }
    return idx;
}

int main()
{
    char s1[] = "98989898989898989898989898.9898989898989898989898";
    char s1_1[100] = "98989898989898989898989898.9898989898989898989898";
    
    printf("s1: %s\n", s1);
    int ss1 = sizeof(s1);
    // printf("size of s1: %d\n", sizeof(s1));
    

    char s2[] = "121212121212121212121212.1212121212121212";
    char s2_1[100] = "121212121212121212121212.1212121212121212";
    int ss2 = sizeof(s2);
    printf("s2: %s\n", s2);
    // printf("size of s2: %d\n", sizeof(s2));

    char s3[101] = "";  //result 배열 초기화
    char n1[100];
    char n2[100];

    int carry = 0;
    int sum = 0;
    int i = 0;

    // 소수점 위치 찾기
    int idx1 = search('.', 100, s1_1);
    // printf("idx1: %d\n", idx1);

    int idx2 = search('.', 100, s2_1);
    // printf("idx2: %d\n", idx2);

    int idx = idx1 - idx2;
    int gap = abs(idx);
    // printf("gap: %d\n", gap);

    // 끝에 0을 추가해 자리수를 맞춰주기
    for (int i = sizeof(s2)-1; i>= sizeof(s2)-(ss1-ss2-gap); i--)
    {
        append('0', s2);
    }

    sprintf_s(n1, sizeof(n1), "%099s", s1);
    sprintf_s(n2, sizeof(n2), "%099s", s2);
    // printf("n1: %s\n", n1);
    // printf("n2: %s\n", n2);

    for (int i = sizeof(n1)-2; i>=0; i--)
    {   
        if (n1[i] == '.') {
            s3[i+1] = n1[i];
            continue;
        }
        sum = (n1[i]-'0') + (n2[i]-'0') + carry;
        carry = sum / 10;
        sum = sum % 10;
        s3[i+1] = sum + '0';
    }
    s3[0] = carry+'0';

    for (i=0; s3[i] == '0'; i++);
    printf("%s\n", s3 + i);

    return 0;
}
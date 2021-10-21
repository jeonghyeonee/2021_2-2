#include <stdio.h>
#include <string.h>

#define MAX_ARRAY 101

void insert(int idx, char ch, char str[]){
    memmove(str+idx+1, str+idx, strlen(str)-idx+1);
    str[idx] = ch;
}

void append(char ch, char str[])
{
     insert(strlen(str), ch, str);
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

char itoc(int i){
    switch(i){
        case 1 : return '1';
        case 2 : return '2';
        case 3 : return '3';
        case 4 : return '4';
        case 5 : return '5';
        case 6 : return '6';
        case 7 : return '7';
        case 8 : return '8';
        case 9 : return '9';
        case 0 : return '0';
    }
}

int search(char ch, int n, char str[])
{
    int idx = -1;
    for (int i=0; i<n; i++){
        if (str[i] == ch) idx = i;
    }
    return idx +1;
}

int main()
{
    char s1[] = "98989898989898989898989898.9898989898989898989898";
    char s1_1[100] = "98989898989898989898989898.9898989898989898989898";

    printf("s1: %s\n", s1);
    int ss1 = sizeof(s1);
    // printf("size of s1: %d\n", ss1);
    

    char s2[] = "121212121212121212121212.1212121212121212";
    char s2_1[100] = "121212121212121212121212.1212121212121212";
    
    printf("s2: %s\n", s2);
    int ss2 = sizeof(s2);
    // printf("size of s2: %d\n", ss2);

    char s3[101] = "";  //result �迭 �ʱ�ȭ
    char n1[100];
    char n2[100];

    int i = 0;

    //�Ҽ��� ��ġ ã��
    int idx1 = search('.', 100, s1_1);
    //printf("idx1: %d\n", idx1);

    int idx2 = search('.', 100, s2_1);
    //printf("idx2: %d\n", idx2);

    int idx = idx1 - idx2;
    int gap = abs(idx);
    //printf("gap: %d\n", gap);

    //���� 0�� �߰��� �ڸ����� �����ֱ�
    for (int i = sizeof(s2)-1; i>= sizeof(s2)-(ss1-ss2-gap); i--)
    {
        append('0', s2);
    }

    sprintf_s(n1, sizeof(n1), "%099s", s1);
    sprintf_s(n2, sizeof(n2), "%099s", s2);
    //printf("n1: %s\n", n1);
    //printf("n2: %s\n", n2);


    int carry = 0;
    int sub = 0;

    // ���� ����
    for (int i = sizeof(n1)-2; i>=0; i--)
    {   
        //printf("%s\n", n1[i]);
        if (n1[i] == '.') {
            s3[i+1] = '.';
            continue;
        }
        else {
            // int temp1 = ctoi(n1[i]);
            int temp1 = n1[i] - '0';
            //printf("%d\n", temp1);
            // int temp2 = ctoi(n2[i]);
            int temp2 = n2[i] - '0';
            //printf("%d\n", temp2);
            temp1 = temp1 - carry;
            //printf("%d\n", carry);
            if (temp2>temp1) {
                carry = 1;
                //printf("%s\n", n2+i);
                sub = 10 -temp2 + temp1;
                //printf("%d\n", sub);
                // s3[i+1] = itoc(sub);
                s3[i+1] = sub + '0';
            }
            else {
                sub = temp1 - temp2;
                //printf("%d\n", sub);
                s3[i+1] = itoc(sub);
                carry=0;
            }
        }
    }
    s3[0] = carry + '0';

    // printf("s3: %s\n", s3);

    for (i=0; s3[i] == '0'; i++);
    // printf("i: %d\n", i);
    printf("result: %s\n", s3 + i);
    
    return 0;
}
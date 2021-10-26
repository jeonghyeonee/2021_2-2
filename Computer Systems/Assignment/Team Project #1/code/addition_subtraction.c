#include <stdio.h>
#include <string.h>


#define _CRT_SECURE_NO_WARNINGS
#define _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS

void insert(int idx, char ch, char str[]) {
    memmove(str + idx + 1, str + idx, strlen(str) - idx + 1);
    str[idx] = ch;
}

void append(char ch, char str[])
{
    insert(strlen(str), ch, str);
}

int search(char ch, int n, char str[])
{
    int idx = -1;
    for (int i = 0; i < n; i++) {
        if (str[i] == ch) idx = i;
    }
    return idx + 1;
}

char itoc(int i) {
    switch (i) {
    case 1:
        return '1';
        break;
    case 2:
        return '2';
        break;
    case 3:
        return '3';
        break;
    case 4:
        return '4';
        break;
    case 5:
        return '5';
        break;
    case 6:
        return '6';
        break;
    case 7:
        return '7';
        break;
    case 8:
        return '8';
        break;
    case 9:
        return '9';
        break;
    case 0:
        return '0';
        break;
    }
}

void Subtraction(char s1[], char s2[], char s1_1[], char s2_1[], int ss1, int ss2)
{
    char n1[100];
    char n2[100];
    char s3[101] = { '\0', };

    // 소수점 위치 찾기
    int idx1 = search('.', 100, s1_1);
    int idx2 = search('.', 100, s2_1);

    int idx = idx1 - idx2;
    int gap = abs(idx);

    int sn1 = sizeof(n1);
    sprintf_s(n1, sn1, "%099s", s1_1);
    for (int i = ss2 - 1; i >= ss2 - (ss1 - ss2 - gap); i--)
    {
        append('0', s2);
    }


    int sn2 = sizeof(n2);
    sprintf_s(n2, sn2, "%099s", s2_1);

    int carry = 0;
    int sub = 0;
    int i = 0;


    if (idx2 > idx1) {

        for (int i = sizeof(n2) - 2; i >= 0; i--)
        {
            if (n2[i] == '.') {
                s3[i + 1] = '.';
                continue;
            }
            else {
                int temp1 = n1[i] - '0';
                int temp2 = n2[i] - '0';
                temp2 = temp2 - carry;
                if (temp1 > temp2) {
                    carry = 1;
                    sub = 10 - temp1 + temp2;
                    s3[i + 1] = itoc(sub);
                }
                else {
                    sub = temp2 - temp1;
                    s3[i + 1] = itoc(sub);
                    carry = 0;
                }
            }
        }
        s3[0] = itoc(carry);
        printf("-");
    }

    else if (idx1 == idx2) {
        if (strlen(s1) >= strlen(s2)) {
            for (int i = sizeof(n1) - 2; i >= 0; i--)
            {
                if (n1[i] == '.') {
                    s3[i + 1] = '.';
                    continue;
                }
                else {
                    int temp1 = n1[i] - '0';
                    int temp2 = n2[i] - '0';

                    temp1 = temp1 - carry;

                    if (temp2 > temp1) {
                        carry = 1;
                        sub = 10 - temp2 + temp1;
                        s3[i + 1] = itoc(sub);
                    }
                    else {
                        sub = temp1 - temp2;
                        s3[i + 1] = itoc(sub);
                        carry = 0;
                    }
                }
            }
            s3[0] = itoc(carry);
        }
        else {
            for (int i = sizeof(n2) - 2; i >= 0; i--)
            {
                if (n2[i] == '.') {
                    s3[i + 1] = '.';
                    continue;
                }
                else {
                    int temp1 = n1[i] - '0';
                    int temp2 = n2[i] - '0';
                    temp2 = temp2 - carry;
                    if (temp1 > temp2) {
                        carry = 1;
                        sub = 10 - temp1 + temp2;
                        s3[i + 1] = itoc(sub);
                    }
                    else {
                        sub = temp2 - temp1;
                        s3[i + 1] = itoc(sub);
                        carry = 0;
                    }
                }
            }
            s3[0] = itoc(carry);
            printf("-");
        }
    }

    else {
        for (int i = sizeof(n1) - 2; i >= 0; i--)
        {
            if (n1[i] == '.') {
                s3[i + 1] = '.';
                continue;
            }
            else {
                int temp1 = n1[i] - '0';
                int temp2 = n2[i] - '0';

                temp1 = temp1 - carry;

                if (temp2 > temp1) {
                    carry = 1;
                    sub = 10 - temp2 + temp1;
                    s3[i + 1] = itoc(sub);
                }
                else {
                    sub = temp1 - temp2;
                    s3[i + 1] = itoc(sub);
                    carry = 0;
                }
            }
        }
        s3[0] = itoc(carry);
    }
    for (i = 0; s3[i] == '0'; i++);
    printf("%s\n", s3 + i);
}

void Addition(char s1[], char s2[], char s1_1[], char s2_1[], int ss1, int ss2)
{
    char n1[100];
    char n2[100];
    char s3[101] = { '\0', };


    // 소수점 위치 찾기
    int idx1 = search('.', 100, s1_1);
    int idx2 = search('.', 100, s2_1);

    int idx = idx1 - idx2;
    int gap = abs(idx);


    int sn1 = sizeof(n1);
    sprintf_s(n1, sn1, "%099s", s1_1);

    for (int i = ss2 - 1; i >= ss2 - (ss1 - ss2 - gap); i--)
    {
        append('0', s2);
    }

    int sn2 = sizeof(n2);

    sprintf_s(n2, sn2, "%099s", s2_1);

    int carry = 0;
    int sum = 0;
    int i = 0;

    for (int i = sn1 - 2; i >= 0; i--)
    {
        if (n1[i] == '.') {
            s3[i + 1] = n1[i];
            continue;
        }
        sum = (n1[i] - '0') + (n2[i] - '0') + carry;
        carry = sum / 10;
        sum = sum % 10;
        s3[i + 1] = sum + '0';
    }
    s3[0] = carry + '0';

    for (i = 0; s3[i] == '0'; i++);
    printf("%s\n", s3 + i);
}

void eliminate(char* str, char ch) {
    for (; *str != '\0'; str++) {
        if (*str == ch) {
            strcpy_s(str, 101, str + 1);
            str--;
        }
    }
}

int compare(int* pt1, int* pt2) {
    if (*pt1 == *pt2)
        return 0;
    else {
        if (*pt1 > *pt2)
            return 1;
        else
            return -1;
    }
}

// void *memmove(void *dest, const void *source, size_t n);


int main()
{
    char s1[] = "+989898989898989898989898989898989898989898989898";//"-98989898989898989898989898.9898989898989898989898";  
    char s1_1[100] = "+989898989898989898989898989898989898989898989898";//"+989898989898989898989898989898989898989898989898"; 


    char s2[] = "+1212121212121212121212121212121212121212"; //"+121212121212121212121212.1212121212121212";
    char s2_1[100] = "+1212121212121212121212121212121212121212"; //"+121212121212121212121212.1212121212121212"; 

    if (s1_1[0] == '+') {
        eliminate(s1_1, '+');
    }
    else if (s1_1[0] == '-') {
        eliminate(s1_1, '-');
    }
    printf("s1_1 without plus or minus sign: %s\n", s1_1);

    if (s2_1[0] == '+') {
        eliminate(s2_1, '+');
    }
    else if (s2_1[0] == '-') {
        eliminate(s2_1, '-');
    }
    printf("s2_1 without plus or minus sign: %s\n", s2_1);

    printf("s1: %s\n", s1);
    int ss1 = strlen(s1) - 1;
    printf("size of s1: %d\n", ss1);

    int ss2 = strlen(s2) - 1;
    printf("s2: %s\n", s2);
    printf("size of s2: %d\n", ss2);

    char n1[100];
    char n2[100];

    int idx1 = search('.', 100, s1_1);
    printf("idx1: %d\n", idx1);

    int idx2 = search('.', 100, s2_1);
    printf("idx2: %d\n", idx2);

    int idx = idx1 - idx2;
    int gap = abs(idx);
    printf("gap: %d\n", gap);

    if (idx > 0) {
        for (int i = ss2 - 1; i >= ss2 - (ss1 - ss2 - gap); i--)
            append('0', s2_1);
    }
    else if (idx < 0) {
        for (int i = ss1 - 1; i >= ss1 - (ss2 - ss1 - gap); i--)
            append('0', s1_1);
    }
    else {
        printf("no change\n");
    }

    int sn1 = sizeof(n1);
    int sn2 = sizeof(n2);
    sprintf_s(n1, sn1, "%099s", s1_1);
    sprintf_s(n2, sn2, "%099s", s2_1);
    printf("n1: %s\n", n1);
    printf("n2: %s\n", n2);

    char operator='-';
    printf("input operator: ");
    printf("%c\n", operator);

    if (operator=='+') {
        if (s1[0] == '+' && s2[0] == '+') {
            Addition(s1, s2, s1_1, s2_1, ss1, ss2);
        }
        else if (s1[0] == '+' && s2[0] == '-') {
            Subtraction(s1, s2, s1_1, s2_1, ss1, ss2);
        }
        else if (s1[0] == '-' && s2[0] == '+') {
            printf("-");
            Subtraction(s1, s2, s1_1, s2_1, ss1, ss2);
            printf("if \'--\', consider \'--\' as \'+\'");
        }
        else if (s1[0] == '-' && s2[0] == '-') {
            printf("-");
            Addition(s1, s2, s1_1, s2_1, ss1, ss2);
        }
        else {
            printf("undefined number");
        }
    }

    else if (operator=='-') {
        if (s1[0] == '+' && s2[0] == '+') {
            Subtraction(s1, s2, s1_1, s2_1, ss1, ss2);
        }
        else if (s1[0] == '+' && s2[0] == '-') {
            Addition(s1, s2, s1_1, s2_1, ss1, ss2);
        }
        else if (s1[0] == '-' && s2[0] == '+') {
            printf("-");
            Addition(s1, s2, s1_1, s2_1, ss1, ss2);
        }
        else if (s1[0] == '-' && s2[0] == '-') {
            printf("-");
            Subtraction(s1, s2, s1_1, s2_1, ss1, ss2);
            printf("if \'--\', consider \'--\' as \'+\'");
        }
        else {
            printf("undefined number");
        }
    }
    printf("if there is no number, value is 0");

    return 0;
}
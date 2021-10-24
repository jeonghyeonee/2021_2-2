#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

//void eliminate(char* str, char ch) {
//    for (; *str != '\0'; str++) { //        ڸ               ݺ 
//        if (*str == ch) { //ch                 
//            strcpy(str, str + 1);
//            str--;
//        }
//    }
//}

void uptodown(char str[], char str2[], char result[]) {
    int carry = 0;
    int sub = 0;
    int i = 0;

    for (int i = strlen(str) - 1; i > 0; i--)
    {
        //printf("%s\n", n1[i]);
        if (str[i] == '.') {
            result[i + 1] = '.';
            continue;
        }
        else {
            // int temp1 = ctoi(n1[i]);
            int temp1 = str[i] - '0';
            //printf("%d\n", temp1);
            // int temp2 = ctoi(n2[i]);
            int temp2 = str2[i] - '0';
            //printf("%d\n", temp2);
            temp1 = temp1 - carry;
            //printf("%d\n", carry);
            if (temp2 > temp1) {
                carry = 1;
                //printf("%s\n", n2+i);
                sub = 10 - temp2 + temp1;
                //printf("%d\n", sub);
                // s3[i+1] = itoc(sub);
                result[i + 1] = sub + '0';
            }
            else {
                sub = temp1 - temp2;
                //printf("%d\n", sub);
                //s3[i+1] = itoc(sub);
                result[i + 1] = sub + '0';
                carry = 0;
            }
            result[0] = carry + '0';
        }
    }
}

void downtoup(char str[], char str2[], char result[]) {
    int carry = 0;
    int sub = 0;
    int i = 0;

    for (int i = strlen(str2) - 1; i > 0; i--)
    {
        //printf("%s\n", n1[i]);
        if (str2[i] == '.') {
            result[i + 1] = '.';
            continue;
        }
        else {
            // int temp1 = ctoi(n1[i]);
            int temp1 = str[i] - '0';
            //printf("%d\n", temp1);
            // int temp2 = ctoi(n2[i]);
            int temp2 = str2[i] - '0';
            //printf("%d\n", temp2);
            temp2 = temp2 - carry;
            //printf("%d\n", carry);
            if (temp1 > temp2) {
                carry = 1;
                //printf("%s\n", n2+i);
                sub = 10 - temp1 + temp2;
                //printf("%d\n", sub);
                // s3[i+1] = itoc(sub);
                result[i + 1] = sub + '0';
            }
            else {
                sub = temp2 - temp1;
                //printf("%d\n", sub);
                //s3[i+1] = itoc(sub);
                result[i + 1] = sub + '0';
                carry = 0;
            }
        }
        result[0] = carry + '0';
    }
    printf("-");
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

void Subtraction(char s1[], char s2[], char s3[], char s1_1[], char s2_1[], int ss1, int ss2)
{
    char n1[100];
    char n2[100];
    // char result[101] = "";

    // 소수점 위치 찾기
    int idx1 = search('.', 100, s1_1);
    int idx2 = search('.', 100, s2_1);

    int idx = idx1 - idx2;
    int gap = abs(idx);


    // printf("!!!!!!!!!!!!!!! in sub s1_1: %s\n", s1_1);
    int sn1 = sizeof(n1);
    sprintf_s(n1, sn1, "%099s", s1_1);
    for (int i = ss2 - 1; i >= ss2 - (ss1 - ss2 - gap); i--)
    {
        append('0', s2);
    }


    int sn2 = sizeof(n2);
    sprintf_s(n2, sn2, "%099s", s2_1);

    printf("in sub n1: %s\n", n1);
    printf("in sub n2: %s\n", n2);

    int carry = 0;
    int sub = 0;
    int i = 0;


    if (idx2 > idx1) {

        printf("idx2>idx1");
        //downtoup(n1, n2, s3);

        for (int i = sn2 - 2; i > 0; i--)
        {
            //printf("%s\n", n1[i]);
            if (n2[i] == '.') {
                s3[i + 1] = '.';
                continue;
           }
            else {
                // int temp1 = ctoi(n1[i]);
                int temp1 = n1[i] - '0';
                //printf("%d\n", temp1);
                // int temp2 = ctoi(n2[i]);
                int temp2 = n2[i] - '0';
                //printf("%d\n", temp2);
                temp2 = temp2 - carry;
                //printf("%d\n", carry);
                if (temp1 > temp2) {
                    carry = 1;
                    //printf("%s\n", n2+i);
                    sub = 10 - temp1 + temp2;
                    //printf("%d\n", sub);
                    // s3[i+1] = itoc(sub);
                    s3[i + 1] = sub + '0';
                }
                else {
                    sub = temp2 - temp1;
                    //printf("%d\n", sub);
                    //s3[i+1] = itoc(sub);
                    append(itoc, s3);
                    carry = 0;
                }
            }
        }
        s3[0] = carry + '0';
        printf("-");
    }

    else {
        printf("idx1>=idx2\n");
        //uptodown(n1, n2, s3);
        for (int i = sn1 - 2; i > 0; i--)
        {
            // printf("s3: %s\n", s3+i);
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
                    //printf("%s\n", n2+i);
                    sub = 10 - temp2 + temp1;
                    s3[i + 1] = sub + '0';
                    //char s = itoc(sub);
                    //printf("%c\n", s);
                }
                else {
                    sub = temp1 - temp2;
                    printf("#### sub_s: %s\n", s3);
                    // char s = itoc(sub);
                    // printf("%s\n", s);
                    s3[i+1] = sub + '0';
                    carry = 0;
                }
            }
        }
        s3[0] = itoc(carry);
    }
    printf("last s3: %s\n", s3);
    /*for (i=0; i<strlen(s3); i++)
        printf("s3: %s\n", s3);*/
    for (i = 0; s3[i] == '0'; i++);
    //printf("%d\n", i);
//for (i; i<strlen(s3); i++)
    printf("Subtraction result: %s\n", s3 + i);
}

void Addition(char s1[], char s2[], char s3[], char s1_1[], char s2_1[], int ss1, int ss2)
{
    printf("in add s1_1: %s\n", s1_1);
    char n1[100];
    char n2[100];
    //char s3[101] = " ";


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

    printf("in plus n1: %s\n", n1);
    printf("in plus n2: %s\n", n2);

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
    printf("Addition result: %s\n", s3 + i);
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
    char s1[] = "+98989898989898989898989898.9898989898989898989898"; //"+989898989898989898989898989898989898989898989898"; 
    char s1_1[100] = "+98989898989898989898989898.9898989898989898989898";//"+989898989898989898989898989898989898989898989898"; 


    char s2[] = "+121212121212121212121212.1212121212121212"; //"+1212121212121212121212121212121212121212";
    char s2_1[100] = "+121212121212121212121212.1212121212121212"; //"+1212121212121212121212121212121212121212"; 

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
    printf("s1_1 without plus or minus sign: %s\n", s2_1);

    printf("s1: %s\n", s1);
    int ss1 = strlen(s1) - 1;
    printf("size of s1: %d\n", ss1);

    int ss2 = strlen(s2) - 1;
    printf("s2: %s\n", s2);
    printf("size of s2: %d\n", ss2);

    char s3[101] = "";
    char n1[100];
    char n2[100];
    // char result[101] = "";

    //  Ҽ      ġ
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
    //scanf_s("%c", &operator);
    printf("%c\n", operator);

    if (operator=='+') {
        if (s1[0] == '+' && s2[0] == '+') {
            Addition(s1, s2, s3, s1_1, s2_1, ss1, ss2);
        }
        else if (s1[0] == '+' && s2[0] == '-') {
            Subtraction(s2, s1, s3, s2_1, s1_1, ss2, ss1);
        }
        else if (s1[0] == '-' && s2[0] == '+') {
            downtoup(n1, n2, s3);
        }
        else if (s1[0] == '-' && s2[0] == '-') {
            printf("-");
            Addition(s1, s2, s3, s1_1, s2_1, ss1, ss2);
        }
        else {
            printf("undefined number");
        }
    }

    else if (operator=='-') {
        if (s1[0] == '+' && s2[0] == '+') {
            Subtraction(s1, s2, s3, s1_1, s2_1, ss1, ss2);
        }
        else if (s1[0] == '+' && s2[0] == '-') {
            Addition(s1, s2, s3, s1_1, s2_1, ss1, ss2);
        }
        else if (s1[0] == '-' && s2[0] == '+') {
            printf("-");
            Addition(s1, s2, s3, s1_1, s2_1, ss1, ss2);
        }
        else if (s1[0] == '-' && s2[0] == '-') {
            Subtraction(s2, s1, s3, s2_1, s1_1, ss2, ss1);
        }
        else {
            printf("undefined number");
        }
    }
    // printf("s1_1: %s\n", s1_1);
    //Subtraction(s1, s2, s3, s1_1, s2_1, ss1, ss2);
    // Addition(s1, s2, s3, s1_1, s2_1, ss1, ss2);
    // int* add = Addition(n1, n2, s3);
    // for (i = 0; add[i] == '0'; i++);
    // printf("idx: %d\n", i);
    // printf("Addition result: %s\n", add + i);
    return 0;
}
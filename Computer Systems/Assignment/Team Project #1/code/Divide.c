#include <string>
#include <cstring>
#include <algorithm>
#include <stdexcept>
#include <iostream>

class LargeInt{
public:
    char sign;
    std::string num; 
    const std::size_t base = 10; 
    short indexing(std::size_t index) 
    const {return index >= 0 && index < num.size() ? num[index] - '0' : 0;}
protected: 
    void norma();
    LargeInt& divide(const LargeInt &Divisor, LargeInt* remaining);
public:
    LargeInt(); 
    LargeInt(const std::string &value); 
    inline bool neg() const {return sign == '-';} 
    inline bool pos() const {return sign == '+';} 
    inline bool maintaining() const {return sign == '~';}   
    inline std::string toString() const {
        std::string num = this->num; 
        std::reverse(num.begin(), num.end());
        if (!maintaining()) {
            std::string sign; 
            sign += this->sign; 
            return sign + num; 
        }
        return num;
    }
    bool operator < (const LargeInt &other) const; 
    bool operator > (const LargeInt &other) const;
    bool operator <= (const LargeInt &other) const;
    bool operator >= (const LargeInt &other) const;
    bool operator == (const LargeInt &other) const;
    bool operator != (const LargeInt &other) const;
    LargeInt& operator /= (const LargeInt &other);
    LargeInt operator / (const LargeInt &other) const;
    LargeInt remaining(const LargeInt &other) const;
};
LargeInt::LargeInt() : sign('~'), num(1, '0') {}
LargeInt::LargeInt(const std::string &value) : sign('~'), num(value){
    sign = num.empty() ? '~' : num[0] == '-' ? '-' : '+';
    if (num[0] == '+' || num[0] == '-') num.erase(0, 1); 
    std::reverse(num.begin(), num.end());
    norma(); 
    for (std::size_t I = 0; I < num.size(); ++I){
        if (!isdigit(num[I])){
            sign = '~';
            num = "0";
            break;
        }
    }
}
void LargeInt::norma(){
    for (int I = num.size() - 1; I >= 0; --I) {
        if (num[I] != '0') 
            break;
        num.erase(I, 1);
    } 
    if (num.empty()){
        num = "0";
        sign = '~';
    }
}
bool LargeInt::operator < (const LargeInt &other) const{
    if (maintaining() || other.maintaining())
    {return maintaining() ? other.pos() : neg();} 
    if (sign != other.sign)
    {return neg();}
    if (num.size() != other.num.size())
    {return (num.size() < other.num.size() && pos()) || (num.size() > other.num.size() && neg());}
    for (int I = num.size() - 1; I >= 0; --I){
        if (indexing(I) < other.indexing(I)) 
            return pos();
        if (indexing(I) > other.indexing(I))
            return neg();
    }
    return false;
}
bool LargeInt::operator > (const LargeInt &other) const{
    if (maintaining() || other.maintaining())
    {return maintaining() ? other.neg() : pos();}
    if ((sign != other.sign) && !(maintaining() || other.maintaining()))
    {return pos();}
    if (num.size() != other.num.size())
    {return (num.size() > other.num.size() && pos()) || (num.size() < other.num.size() && neg());}
    for (int I = num.size() - 1; I >= 0; --I){
        if (indexing(I) > other.indexing(I))
            return pos();
        if (indexing(I) < other.indexing(I))
            return neg();
    }
    return false;
}
bool LargeInt::operator <= (const LargeInt &other) const
{return (*this < other) || (*this == other);}
bool LargeInt::operator >= (const LargeInt &other) const
{return (*this > other) || (*this == other);}
bool LargeInt::operator == (const LargeInt &other) const{
    if (sign != other.sign || num.size() != other.num.size())
        return false;
    for (int I = num.size() - 1; I >= 0; --I){
        if (indexing(I) != other.indexing(I))
            return false;
    }
    return true;
}
bool LargeInt::operator != (const LargeInt &other) const
{return !(*this == other);}
 
LargeInt& LargeInt::divide(const LargeInt &Divisor, LargeInt* remaining){
    char rem_sign = sign;
    bool neg_res = sign != Divisor.sign;
    if (!maintaining()) sign = '+';
    if (*this < Divisor){
        if (remaining){
            remaining->sign = this->sign;
            remaining->num = this->num;
        }
        sign = '~';
        num = "0";
        return *this;
    }
    if (this == &Divisor){
        if (remaining){
            remaining->sign = this->sign;
            remaining->num = this->num;
        }
        sign = '+';
        num = "1";
        return *this;
    }
    LargeInt dividend(*this); 
    LargeInt divisor(Divisor); 
    LargeInt quotient("0"); 
    divisor.sign = '+'; 
    std::size_t len = std::max(dividend.num.size(), divisor.num.size());
    std::size_t diff = std::max(dividend.num.size(), divisor.num.size()) - std::min(dividend.num.size(), divisor.num.size());
    std::size_t offset = len - diff - 1; 
    dividend.num.resize(len, '0'); 
    divisor.num.resize(len, '0');
    quotient.num.resize(len, '0');
    memmove(&divisor.num[diff], &divisor.num[0], len - diff); 
    memset(&divisor.num[0], '0', diff); 
 
    while(offset < len){
        while (dividend >= divisor){
            int borrow = 0, total = 0;
            for (std::size_t I = 0; I < len; ++I){
                total = dividend.indexing(I) - divisor.indexing(I) - borrow;
                borrow = 0;
                if (total < 0){
                    borrow = 1;
                    total += 10;
                }
                dividend.num[I] = total + '0';
            }
            quotient.num[len - offset - 1]++;
        }
        if (remaining && offset == len - 1){
            remaining->num = dividend.num;
            remaining->sign = rem_sign;
            remaining->norma();
            if (remaining == this){
                return *this;
            }
        }
        memmove(&divisor.num[0], &divisor.num[1], len - 1);
        memset(&divisor.num[len - 1], '0', 1);
        ++offset;
    }
    quotient.sign = neg_res ? '-' : '+';
    quotient.norma();
 
    this->sign = quotient.sign;
    this->num = quotient.num;
    return *this;
}
LargeInt& LargeInt::operator /= (const LargeInt &other)
{return divide(other, nullptr);}
LargeInt LargeInt::operator / (const LargeInt &other) const
{return LargeInt(*this) /= other;} 
LargeInt LargeInt::remaining(const LargeInt &other) const{
    LargeInt remaining;
    LargeInt(*this).divide(other, &remaining);
    return remaining;
} 
void eliminate(char *str, char ch) {
    for (; *str != '\0'; str++) { 
        if (*str == ch) { 
            strcpy(str, str + 1);
            str--;
        }
    }
}
int search(char ch, int n, char str[]) {
    int idx = -1;
    for (int i=0; i<n; i++) {
        if (str[i] == ch) idx = i;
    }
    return idx;
}
void insert (char *m, char *s, int n) { 
   memmove(m, m, strlen(m));
   memmove(m+n, s, strlen(s)); 
}
int main(){
char s1[] = "98989898989898989898989898.9898989898989898989898";
char s2[] = "121212121212121212121212.1212121212121212";
 
    int idx1 = search('.', strlen(s1), s1);
    idx1 = strlen(s1) - idx1 -1;
    printf("idx1: %d\n", idx1);
 
    int idx2 = search('.', strlen(s2), s2);
    idx2 = strlen(s2) - idx2 -1;
    printf("idx2: %d\n", idx2);
 
    int point = - idx2 + idx1;
    printf("point: %d\n", point);
 
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
 
    LargeInt a{s1};
    LargeInt b{s2};
    LargeInt result = a/b;
    std::cout<<result.toString()<<std::endl;
 
    char cStr2[result.toString().length()];
    strcpy(cStr2,result.toString().c_str());
 
    char *sqq2=".";
    insert(cStr2, sqq2, strlen(cStr2)-point);
    printf("%s\n", cStr2);
}


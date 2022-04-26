#include <stdio.h>

#define DBG 1

#define dp(msg)\
{\
    printf(msg);\
    printf(" > in func: < %s >", __FUNCTION__);\
    printf("\n");\
}

void leaper( int a )
{
    int* p    = &a;
    if ( a ){
        for( int i = 0; i < 64; i ++ ){
            if ( ( *(p+i) > (long)leaper ) && ( ( *(p+i) - (long)leaper ) < 0x1000 ) ){
                *(p+i) += 5;
                break;
            }
            if ( ( *(p+i) < (long)leaper ) && ( ( (long)leaper - *(p+i) ) < 0x1000 ) ){
                *(p+i) += 5;
                break;
            }
        }
    }
    return;
}

void func_a()
{
    dp("here!");
}

int main( int argc, char* argv[] )
{
    leaper(1);
    func_a();
    dp("end");
    return 0;
}
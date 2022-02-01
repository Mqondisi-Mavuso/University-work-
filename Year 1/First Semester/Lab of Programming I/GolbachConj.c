#include<stdio.h>
#include<stdbool.h>

bool isPrime(int x);

int main(void){
    int number, i;
    int pairs = 0;

    scanf("%d", &number);

    for (i = 2; i <= number / 2; i++){
        if (isPrime(i)){
            if (isPrime(number - i)){
                pairs++;
            }
        }
    }

    printf("%d", pairs);

    return 0;
}

bool isPrime(int x){
    int divisor;

    if (x <= 1){
        return false;
    }

    for (divisor = 2; divisor * divisor <= x; divisor++){
        if (x % divisor == 0){
            return false;
        }
    }
    return true;
}

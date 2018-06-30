#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int printBinary(int x[]){
    int i;
    for(i=63; i>=0; i--){
        printf("%d",x[i]);
    }
    printf("\n");

}


int *addBinary(int *x,int *y){


    printf("x:\n");
    printBinary(x);
    printf("y:\n");
    printBinary(y);

    int i = 0;
    int carry = 0;
    int *sum = calloc(64, sizeof(int));
    for(i = 0; i < 64; i++){
        if(x[i]==0 && y[i]==0 && carry==0){
            sum[i] = 0;
            carry = 0;
        }
        else if(x[i]==0 && y[i]==0 && carry==1){
            sum[i] = 1;
            carry = 0;
        }
        else if(((x[i]==1 && y[i]==0)||(x[i]==0 && y[i]==1)) && carry==0){
            sum[i] = 1;
            carry = 0;
        }
        else if(((x[i]==1 && y[i]==0)||(x[i]==0 && y[i]==1)) && carry==1){
            sum[i] = 0;
            carry = 1;
        }
        else if(x[i]==1 && y[i]==1 && carry==0){
            sum[i] = 0;
            carry = 1;
        }
        else if(x[i]==1 && y[i]==1 && carry==1){
            sum[i] = 1;
            carry = 1;
        }
    }
    printf("sum:\n");
    printBinary(sum);

    return sum;
}


int *decToBinary(int number) {

    int * binaryNum = calloc(64, sizeof(int));
    int i = 0;
    int j = 0;
    int k = 0;
    int is_negative = 0;
    int carry = 0;

    if(number < 0){
        is_negative = 1;
        number = number * -1;
    }

    while (number > 0) {

        binaryNum[i] = number % 2;
        number = number / 2;
        i++;
    }

    if(is_negative == 1){

        for(k = 0; k < 64; k++){

            if(binaryNum[k] == 0){
                binaryNum[k] = 1;
            }

            else if(binaryNum[k] == 1){
                binaryNum[k] = 0;
            }
        }
        printBinary(binaryNum);
        int one[64] = {0};
        one[0] = 1;
        printf("one:\n");
        printBinary(one);
        int * twoscomplement = addBinary(binaryNum, (int *) &one);
        free(binaryNum);
        binaryNum = twoscomplement;

    }




    printBinary(binaryNum);

    printf("\n\n");

    return binaryNum;
}


int decToInt(char * input){

    char array[64] = {0};
    memcpy(array,input,64);

    int number = 0;
    int neg = array[0] == '-';
    int i = neg ? 1 : 0;
    while ( array[i] >= '0' && array[i] <= '9' )
    {
        number *= 10;
        number += array[i] - '0';
        i ++;
    }
    if ( neg )
        number *= -1;

    printf( "string %s -> number %d\n\n", array, number);

    return  number;
}


int octToInt(char * input){

    char array[64] = {0};
    memcpy(array,input,64);
    int number = 0;
    int neg = array[0] == '-';
    int i = neg ? 1 : 0;
    while ( array[i] >= '0' && array[i] <= '7' )
    {
        number *= 8;
        number += array[i] - '0';
        i ++;
    }
    if ( neg )
        number *= -1;

    printf( "string %s -> number %d\n\n", array, number);

    return  number;
}


int hexToInt(char * input){

    char array[64] = {0};
    memcpy(array,input,64);

    int number = 0;
    int neg = array[0] == '-';
    int i = neg ? 1 : 0;
    while ( array[i] >= '0' && array[i] <= 'f' )
    {
        if(array[i] >= 'A' && array[i] <= 'F'){
            array[i] += 32;
        }

        if( array[i] >= 'a' && array[i] <= 'f') {
            number *= 16;
            number += array[i] - 87;
            i++;
        }

        else if(array[i] >= '0' && array[i] <= '9'){
            number *= 16;
            number += array[i] - '0';
            i++;

        }
    }
    if ( neg )
        number *= -1;

    printf( "string %s -> number %d\n\n", array, number);

    return  number;
}


int binToInt(int *array){

    int number = 0;
    int i = 63;
    for(i; i >= 0; i--){

        if (array[i] == 1) number = number * 2 + 1;
        else if (array[i] == 0) number *= 2;
    }


    return number;
}

int main(int argc, char *argv[]){



//    if((strlen(argv[1]) >  (size_t) 64 )|| (strlen(argv[2]) >  (size_t )64) ){
//        fprintf(stderr, "ERROR");
//    }

    int num1 = decToInt("-10");
    int num2 = decToInt("-10");
    int *ptr1 = decToBinary(num1);
    int *ptr2 = decToBinary(num2);
    int *sum = addBinary(ptr1, ptr2);
    int convertedInt = binToInt(sum);
    printf("\n\n");
    printf("converted int: ");
    printf("%i", convertedInt);
    free(ptr1);
    free(ptr2);
    free(sum);


    return 0;
}


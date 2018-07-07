#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//int printBinary(int x[]){
//    int i;
//    for(i=63; i>=0; i--){
//        printf("%d",x[i]);
//    }
//    printf("\n");
//
//}
//
//
//int *addBinary(int *x,int *y){
//
////
////    printf("x:\n");
////    printBinary(x);
////    printf("y:\n");
////    printBinary(y);
//
//    int i = 0;
//    int carry = 0;
//    int *sum = (int *) calloc(64, sizeof(int));
//    for(i = 0; i < 64; i++){
//        if(x[i]==0 && y[i]==0 && carry==0){
//            sum[i] = 0;
//            carry = 0;
//        }
//        else if(x[i]==0 && y[i]==0 && carry==1){
//            sum[i] = 1;
//            carry = 0;
//        }
//        else if(((x[i]==1 && y[i]==0)||(x[i]==0 && y[i]==1)) && carry==0){
//            sum[i] = 1;
//            carry = 0;
//        }
//        else if(((x[i]==1 && y[i]==0)||(x[i]==0 && y[i]==1)) && carry==1){
//            sum[i] = 0;
//            carry = 1;
//        }
//        else if(x[i]==1 && y[i]==1 && carry==0){
//            sum[i] = 0;
//            carry = 1;
//        }
//        else if(x[i]==1 && y[i]==1 && carry==1){
//            sum[i] = 1;
//            carry = 1;
//        }
//    }
//
//
//    return sum;
//}
//
//
//int *decToBinary(int number) {
//
//    int * binaryNum = (int *) calloc(64, sizeof(int));
//    int i = 0;
//    int j = 0;
//    int k = 0;
//    int is_negative = 0;
//    int carry = 0;
//
//    if(number < 0){
//        is_negative = 1;
//        number = number * -1;
//    }
//
//    while (number > 0) {
//
//        binaryNum[i] = number % 2;
//        number = number / 2;
//        i++;
//    }
//
//    if(is_negative == 1){
//
//        for(k = 0; k < 64; k++){
//
//            if(binaryNum[k] == 0){
//                binaryNum[k] = 1;
//            }
//
//            else if(binaryNum[k] == 1){
//                binaryNum[k] = 0;
//            }
//        }
////        printBinary(binaryNum);
//        int one[64] = {0};
//        one[0] = 1;
//        int * twoscomplement = addBinary(binaryNum, one);
//        free(binaryNum);
//        binaryNum = twoscomplement;
//
//    }
//
//
//
//
//    printBinary(binaryNum);
//
//    printf("\n\n");
//
//    return binaryNum;
//}
//
//
//int decToInt(char * input){
//
//    char array[64] = {0};
//    memcpy(array,input,64);
//
//    int number = 0;
//    int neg = array[0] == '-';
//    int i = neg ? 1 : 0;
//    while ( array[i] >= '0' && array[i] <= '9' )
//    {
//        number *= 10;
//        number += array[i] - '0';
//        i ++;
//    }
//    if ( neg )
//        number *= -1;
//
//    printf( "string %s -> number %d\n\n", array, number);
//
//    return  number;
//}
//
//
//int octToInt(char * input){
//
//    char array[64] = {0};
//    memcpy(array,input,64);
//    int number = 0;
//    int neg = array[0] == '-';
//    int i = neg ? 1 : 0;
//    while ( array[i] >= '0' && array[i] <= '7' )
//    {
//        number *= 8;
//        number += array[i] - '0';
//        i ++;
//    }
//    if ( neg )
//        number *= -1;
//
//    printf( "string %s -> number %d\n\n", array, number);
//
//    return  number;
//}
//
//
//int hexToInt(char * input){
//
//    char array[64] = {0};
//    memcpy(array,input,64);
//
//    int number = 0;
//    int neg = array[0] == '-';
//    int i = neg ? 1 : 0;
//    while ( array[i] >= '0' && array[i] <= 'f' )
//    {
//        if(array[i] >= 'A' && array[i] <= 'F'){
//            array[i] += 32;
//        }
//
//        if( array[i] >= 'a' && array[i] <= 'f') {
//            number *= 16;
//            number += array[i] - 87;
//            i++;
//        }
//
//        else if(array[i] >= '0' && array[i] <= '9'){
//            number *= 16;
//            number += array[i] - '0';
//            i++;
//
//        }
//    }
//    if ( neg )
//        number *= -1;
//
//    printf( "string %s -> number %d\n\n", array, number);
//
//    return  number;
//}
//
//
//int binToInt(int *array){
//
//    int number = 0;
//    int i = 63;
//    for(i; i >= 0; i--){
//
//        if (array[i] == 1) number = number * 2 + 1;
//        else if (array[i] == 0) number *= 2;
//    }
//
//
//    return number;
//}

int decascii_long(char * string, long * number){
    long value = 0;
    int is_negative = 0;
    int i = 0;
    if(strlen(string) == 0){
        printf("ERROR");
        exit(EXIT_FAILURE);
    }
    if(string[0] == '-'){
        is_negative = 1;
        i = 1;

    }
    while(string[i] != '\0'){
        if(isdigit(string[i])){
            value = value * 10 + string[i] - '0';


        }
        else{
            printf("ERROR");
            exit(EXIT_FAILURE);
        }
        i++;
    }

    if(is_negative){
        value = value * -1;
    }

    *number = value;

    return 0;

}

int hexascii_long(char * string, long * number) {

    long value = 0;
    int is_negative = 0;
    int i = 0;
    if(strlen(string) == 0){
        printf("ERROR");
        exit(EXIT_FAILURE);
    }
    if(string[0] >= '8'){

        is_negative = 1;
        i = 1;
        if(string[0] >= 'A' && string[0] <= 'F'){

            value += 15 - (string[0] - 55);
        }

        else if( string[0] >= 'a' && string[0] <= 'f') {
            value +=  15 - (string[0] - 87);
        }

        else if(isdigit(string[0])){
            value += 15 - (string[0] - '0');

        }

        printf("value0: %ld\n", value);

    }
    while(string[i] != '\0'){

        if(isdigit(string[i]) || isalpha(string[i]) ){
            value = value * 16 ;

            if(string[i] >= 'A' && string[i] <= 'F'){
                if(is_negative) {
                    value +=  15 - (string[i] - 55);
                    printf("value: %i\n", 15 - (string[i] - 55));
                }

                else{

                    value += string[i] - 55;

                }

            }

            else if( string[i] >= 'a' && string[i] <= 'f') {
                if(is_negative) {
                    value += 15 - (string[i] - 87) ;
                    printf("value: %i\n", 15 - (string[i] - 87));

                }

                else{

                    value += string[i] - 87;

                }
            }

            else if(isdigit(string[i])){

                if(is_negative) {
                    value += 15 - (string[i] - '0') ;
                    printf("value: %i\n", 15 - (string[i] - '0'));

                }

                else {
                    value += string[i] - '0';
                }

            }


        } else{
            printf("ERROR");
            exit(EXIT_FAILURE);
        }
        i++;

    }

    if(is_negative){
        value += 1;
        value = value * -1;
    }

    *number = value;




    return 0;

}



int octascii_long(char * string, long * number){

    long value = 0;
    int is_negative = 0;
    int i = 0;
    if(strlen(string) == 0){
        printf("ERROR");
        exit(EXIT_FAILURE);
    }
    if(string[0] >= '2'){

        is_negative = 1;
        i = 1;
        value += 3 - (string[0] - '0');

        printf("value0: %i\n", (string[i] - '0'));

        printf("value0 %ld\n", value);


    }
    while(string[i] != '\0'){

        if(isdigit(string[i])){
            value = value * 8 ;

                if(is_negative) {
                    value += 7 - (string[i] - '0') ;
                }

                else {
                    value += string[i] - '0';
                }



        } else{
            printf("ERROR");
            exit(EXIT_FAILURE);
        }
        i++;

        printf("value %ld\n", value);
    }

    if(is_negative){

        value += 1;
        value = value * -1;
    }

    *number = value;



}


int main(int argc, char *argv[]){

    long number1 = 0;
    long number2 = 0;
    octascii_long("377777777401", &number1);


    printf("%ld\n", number1);

//    hexascii_long("0BB03F45", &number2);
//
//
//    printf("%ld\n", number2);




//    if((strlen(argv[1]) >  (size_t) 64 )|| (strlen(argv[2]) >  (size_t )64) ){
//        fprintf(stderr, "ERROR");
//    }

//    int num1 = decToInt("0");
//    int num2 = decToInt("-10");
//    int *ptr1 = decToBinary(num1);
//    int *ptr2 = decToBinary(num2);
//    int *sum = addBinary(ptr1, ptr2);
//    printf("sum:\n");
//    printBinary(sum);
//    int convertedInt = binToInt(sum);
//    printf("\n\n");
//    printf("converted int: ");
//    printf("%i", convertedInt);
//    free(ptr1);
//    free(ptr2);
//    free(sum);


    return 0;
}


#include "calc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



int printBinary(const long * array){
    int i;
    for(i=63; i>=0; i--){
       if(array[i] == 1){
           printf("1");
       }
       else if(array[i] == 0){
           printf("0");
       }
    }
    printf("\n");

    return 0;

}


int printoctal(const long * array){

    long value = 0;
    int i = 62;
    char c = NULL;


    value =  array[63];

    c = (char) (value + '0');

    printf("%c", c);

    while(i>0){

        value =  array[i-2] + (2 * array[i-1]) + (4 * array[i]);

        c = (char) (value + '0');

        printf("%c", c);

        i = i - 3;
    }

    printf("\n");



    return 0;

}

int printhex(const long * array){

    long value = 0;
    int i = 63;
    char c = '0';

    while(i>0){

        value =  array[i-3] + (2 * array[i-2]) + (4 * array[i-1]) + (8 * array[i]);


        if( value <= 9  ) {

            c = (char) (value + '0');

        }


        else{

            c = (char) (value%10 + 'A');

        }

        printf("%c", c);

        i = i - 4;
    }

    printf("\n");



    return 0;

}


long *addBinary(long *x,long *y){

    int i = 0;
    long carry = 0;
    long *sum = (long *) calloc(64, sizeof(long));
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


    return sum;
}


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

    return 0;

}


int binascii_long(char * string, long * number){

    long value = 0;
    int is_negative = 0;
    int i = 0;
    if(strlen(string) == 0){
        printf("ERROR");
        exit(EXIT_FAILURE);
    }
    if(string[0] == '1'){

        is_negative = 1;
        i = 1;

    }
    while(string[i] != '\0'){

        if(isdigit(string[i])){
            value = value * 2 ;

            if(is_negative) {
                value += 1 - (string[i] - '0') ;
            }

            else {
                value += string[i] - '0';
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


int long_decascii(long number, char * string){

    long value = number;
    long x = 0;
    int is_negative = 0;
    int i = 0;


    if(string == 0 ){
        printf("ERROR");
        exit(EXIT_FAILURE);
    }



    if(number < 0){
        is_negative = 1;
        value = number * -1;
    }

    do {

        x = value % 10;
        string[i] = (char ) ('0' +  x);
        value = value/10;
        i++;
    } while (value >0 );

    if (is_negative){
        string[i] = '-';
        i++;
    }

    string[i] = '\0';

    i--;

    printf("output: ");

    for(i; i >= 0; i--){
        printf("%c", string[i]);
    }


    printf("\n\n");

    return 0;

}


long * long_binascii(long number, char * string , long * binaryNum){

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
//        printBinary(binaryNum);
        long one[64] = {0};
        one[0] = 1;
        long * twoscomplement = addBinary(binaryNum, one);
        free(binaryNum);
        binaryNum = twoscomplement;

    }


    printBinary(binaryNum);

    printoctal(binaryNum);

    printhex(binaryNum);

    printf("\n\n");

    return binaryNum;


}


void convertInput(char * string, long * number){
    char type = string[0];
    char * input = (char *) calloc(strlen(string), sizeof(char));
    memset(input, '0' ,strlen(string) * sizeof(char));
    memcpy(input, string + 1, strlen(string) * sizeof(char));

    if(type == 'd'){

        decascii_long(input, number);

    }

    else if(type == 'b'){
        binascii_long(input, number);
    }

    else if(type == 'h'){
        hexascii_long(input, number);
    }

    else if( type == 'o' ){
        octascii_long(input, number);
    }

    else{

        free(input);
        printf("ERROR");
        exit(EXIT_FAILURE);

    }

    free(input);

}



void printOuput(long sum, const char * format){

    char diplayFormat = format[0];
    char * pcharArray = NULL;

    if(diplayFormat == 'd'){

        pcharArray = (char *)  calloc(65, sizeof(char));
        long_decascii(sum, pcharArray);
        free(pcharArray);
    }
//
//    else if(type == 'b'){
//        binascii_long(input, number);
//    }
//
//    else if(type == 'h'){
//        hexascii_long(input, number);
//    }
//
//    else if( type == 'o' ){
//        octascii_long(input, number);
//    }
//
//    else{
//
//        free(input);
//        printf("ERROR");
//        exit(EXIT_FAILURE);
//
//    }
//
//    free(input);






}

int main(int argc, char *argv[]){

    char * operation = NULL;
    long number1 = 0;
    long number2 = 0;
    long sum = 0;


    if(argv[1] && argv[2] && argv[3] && argv[4]) {

        operation = argv[1];


        convertInput(argv[2], &number1);
        convertInput(argv[3], &number2);

        if(strcmp(operation, "-") == 0){
            number2 = number2 * -1;
        }

        sum = number1 + number2;


        printOuput(sum, argv[4]);

    }


    else{

        printf("ERROR");
        exit(EXIT_FAILURE);

    }


    return 0;
}


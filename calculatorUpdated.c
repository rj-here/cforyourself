/*
This program will be a simple calculator, performing basic operations. I intend to add history as well, and also implementing multi-calculation (such as adding several numbers to understand finances or grades).
This idea came to me as an AI suggestion.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//Declaring the methods, so they can be used later!
int add(int num1, int num2);
int subtract(int num1, int num2);
int multiply(int num1, int num2);
int divide(int num1, int num2);
double exponents(int base, int power);
double logOf10(int num);
void fractions(int numerator1, int denominator1, int numerator2, int denominator2, int func);

int main() {
printf("Welcome! This will be a simple calculator.\n");
printf("This being a simple one, means it'll do simple addition, subtraction, multiplication and division.\n");
printf("We'll calculate away!\n");

printf("Before we proceed further, select one of the options, to decide which calculation you'd like to perform:\n");
printf("1. Addition\n");
printf("2. Subtraction\n");
printf("3. Multiplication\n");
printf("4. Division\n");
printf("5. Exponents\n");
printf("6. Log [Base 10]\n");
printf("7. Fractions\n");

int choice;
scanf("%d", &choice); //scanf takes user input.

if (choice == 1) {//for addition
printf("Adding away! Provide 2 numbers as input. Keep one space between them.\n");

int num1, num2;

scanf("%d %d", &num1, &num2);

int sum = add(num1, num2);

printf("The sum of the 2 numbers will be: %d\n", sum);

}

else if (choice == 2) {//for subtraction
{
printf("Subtracting it'll be. Provide 2 numbers as input (it will be first number - second number). Keep one space between them.\n");

int num1, num2;

scanf("%d %d", &num1, &num2);

int difference = subtract(num1, num2);

printf("The difference in the 2 numbers is: %d\n", difference);
}

}

else if (choice == 3) {//for multiplication
printf("Multiplying it is. Provide 2 numbers as input. Keep one space between them.\n");

int num1, num2;

scanf("%d %d", &num1, &num2);

int product = multiply(num1, num2);

printf("The product of the 2 numbers is %d\n", product);
}

else if (choice == 4) {//for division
printf("Dividing. Provide 2 numbers as input (it will be first number ÷ second number). Keep one space between them.\n");

int num1, num2;

scanf("%d %d", &num1, &num2);

int dividedAnswer = divide(num1, num2);

printf("Upon dividing the 2 numbers, the answer is: %d\n", dividedAnswer);
}

else if (choice == 5) {//for exponents.
printf("Exponents here we come! Input 2 numbers, first the base, followed by the power. Keep one space between them.\n");

int base, power;

scanf("%d %d", &base, &power);

int poweredBase = exponents(base, power);

printf("%d to the power of %d is: %d", base, power, poweredBase);
}

else if (choice == 6) {
printf("Log base 10! Which number would you like to get the log base 10 value of?\n");

int num;

scanf("%d", &num);

printf("%d in log base 10 is: %d\n", num, log(num));
}

else if (choice == 7) {//for fractions
printf("Fractions! Provide 2 fractions as input, in this format: the numerator of the first, followed by the denominator of the first, then the numerator of the second, followed by the denominator of the second. Keep a space between each of them.\n");

int numerator1, denominator1, numerator2, denominator2;

scanf("%d %d %d %d", &numerator1, &denominator1, &numerator2, &denominator2);

printf("Which function would you like to perform on the fractions?\n1. Add,\n2. Subtract,\n3. Multiply,\n4. Divide,\n5. Exponents\n");

int func;
scanf("%d", &func);
if ((func >= 1) && (func <=4)) {
    fractions(numerator1, denominator1, numerator2, denominator2, func);
}
else {
    printf("Sorry! Need a valid function!\n Try again.\n");
}
}
}

/*
The coming functions will perform: addition, subtraction, mutliplication, division [the essentials]
We will take 2 numbers in each case, then return the according result.
The call to these functions are dependent on user selection.
*/
int add(int num1, int num2) {
int sum = num1 + num2; //adding
return sum;
}

int subtract(int num1, int num2) {
int difference = num1 - num2; //subtracting
return difference;
}

int multiply(int num1, int num2) {
int product = num1 * num2; //multiplying
return product;
}

int divide(int num1, int num2) {
if (num2 == 0) {
    printf("Error: Division by zero is not allowed.\n");
    return 0; // or another error code
}
int answer = num1 / num2; //dividing
return answer;
}
/*
Extras
*/
double exponents(int base, int power) {
double value = 1;
if (power > 1) {//for positive powers
for (int i = 0; i < power; i++) {
    value = value * base;
}
}
else if (power > 0 && power < 1) {//for fractional powers
double fractionalPower = pow(base, power);
}
else if (power < 0) { //for negative powers
for (int i = 0; i > power; i--) {
value = value/base; 
}
}
else if (power == 0) {
    return 1; //any n^0 is 1
}
return value; //get x^n
}

double logOf10(int num) {
return log10(num); //get log of base 10 values
}

void fractions(int numerator1, int denominator1, int numerator2, int denominator2, int func) {
//involving fractions
int numerator, denominator; //declaring final
if (func == 1) { //add
if (denominator1 == denominator2) { //if same denominator
    numerator = numerator1 + numerator2;
    printf("The fraction is: %d / %d", numerator, denominator1);
}
else {
    numerator = (numerator1 * denominator2) + (numerator2 * denominator1);
    denominator = denominator1 * denominator2;
}
}

else if (func == 2) { //subtract
    numerator = numerator1 * denominator2 - numerator2 * denominator1; //final numerator
    denominator = denominator1 * denominator2; //final denominator
    printf("The fraction is %d / %d", numerator, denominator);
}

else if (func == 3) { //multiply
if (denominator1 == numerator2) { //if denominator of first is numerator of second
    numerator = numerator1; //final numerator
    denominator = denominator2; //final denominator
    printf("The fraction is %d / %d", numerator, denominator);
}
else if (denominator2 == numerator1) { //if denominator of second is numerator of first
    numerator = numerator2; //final numerator
    denominator = denominator1; //final denominator
    printf("The fraction is $d / %d", numerator, denominator);
}
else {
    numerator = numerator1 * numerator2; //final numerator
    denominator = denominator1 * denominator2; //final denominator
    printf("The fraction is %d / %d", numerator, denominator);
}
}

else if (func == 4) { //divide; dividing a fraction by another is multiplying by the reciprocal
    numerator = numerator1 * denominator2; //final numerator
    denominator = denominator1 * numerator2; //final denominator
    if (denominator == 0) {
        printf("Error: Division by zero is not allowed.\n");
        return;
    }
    printf("The fraction is %d / %d", numerator, denominator);
}

else if (func == 5) { //exponents
    double numeratorOne = exponents(numerator1, numerator2); //first numerator
    double denominatorOne = exponents(denominator1, numerator2); //first denominator
    double fractionOne = numeratorOne / denominatorOne; //Fraction One result
    //These One numbers, are powering the numerator and denominator of fraction 1 by the numerator of fraction 2
    double numeratorTwo = exponents(numerator1, denominator2); //second numerator
    double denominatorTwo = exponents(denominator1, denominator2); //second denominator
    double fractionTwo = numeratorTwo / denominatorTwo; //Fraction Two result
    //These Two Numbers, power the numerator & denominator of fraction by denominator of fraction 2
    double finalFraction = fractionOne / fractionTwo; //final fraction result
    printf("The fraction is: %lf", finalFraction);
}

}

/*
© 2025 Rishi
Last updated: 22nd July, 2025
*/


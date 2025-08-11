/*
This program will be a simple calculator, performing basic operations. I intend to add history as well, and also implementing multi-calculation (such as adding several numbers to understand finances or grades).
This idea came to me as an AI suggestion.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_LEN 100 //The maximum length

char hist[MAX_LEN][MAX_LEN]; // the most amount of expressions
char decision[3] = "Yes"; //storing the user's decision to continue using the calculator or not (Yes or No)
int histIndex = 0; // declaring the # of expressions done so far
//Declaring the methods, so they can be used later!
int add(int num1, int num2);
int subtract(int num1, int num2);
int multiply(int num1, int num2);
int divide(int num1, int num2);
double exponents(double base, double power);
double logOf10(int num);
void fractions(int numerator1, int denominator1, int numerator2, int denominator2, int func);
void addToHistory(char* expression, char[][MAX_LEN]);
void history(char[][MAX_LEN]);

int main() {
printf("Welcome! This will be a simple calculator.\n");
printf("This being a simple one, means it'll do simple addition, subtraction, multiplication and division.\n");
printf("We'll calculate away!\n");
while (strcmp(decision, "Yes") == 0 || strcmp(decision, "yes") == 0 || strcmp(decision, "YES") == 0) {//while the user wants to continue using the calculator

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

char expression[MAX_LEN];
sprintf(expression, "%d + %d = %d", num1, num2, sum); //formatting the expression, to add to history
addToHistory(expression, hist); //Adding to history

}

else if (choice == 2) {//for subtraction
{
printf("Subtracting it'll be. Provide 2 numbers as input (it will be first number - second number). Keep one space between them.\n");

int num1, num2;
scanf("%d %d", &num1, &num2);

int difference = subtract(num1, num2);
char expression[MAX_LEN];
sprintf(expression, "%d - %d = %d", num1, num2, difference); //formatting the expression, to add to history
addToHistory(expression, hist); //Adding to history

printf("The difference in the 2 numbers is: %d\n", difference);
}

}

else if (choice == 3) {//for multiplication
printf("Multiplying it is. Provide 2 numbers as input. Keep one space between them.\n");

int num1, num2;
scanf("%d %d", &num1, &num2);

int product = multiply(num1, num2);
char expression[MAX_LEN];
sprintf(expression, "%d * %d = %d", num1, num2, product); //formatting the expression, to add to history
addToHistory(expression, hist); //Adding to history

printf("The product of the 2 numbers is %d\n", product);
}

else if (choice == 4) {//for division
printf("Dividing. Provide 2 numbers as input (it will be first number ÷ second number). Keep one space between them.\n");

int num1, num2;
scanf("%d %d", &num1, &num2);

int dividedAnswer = divide(num1, num2);
char expression[MAX_LEN];
sprintf(expression, "%d ÷ %d = %d", num1, num2, dividedAnswer); //formatting the expression, to add to history
addToHistory(expression, hist); //Adding to history

printf("Upon dividing the 2 numbers, the answer is: %d\n", dividedAnswer);
}

else if (choice == 5) {//for exponents.
printf("Exponents here we come! Input 2 numbers, first the base, followed by the power. Keep one space between them.\n");

int base, power;
scanf("%d %d", &base, &power);

int poweredBase = exponents(base, power);
char expression[MAX_LEN];
sprintf(expression, "%d ^ %d = %d", base, power, poweredBase); //formatting the expression, to add to history
addToHistory(expression, hist); //Adding to history

printf("%d to the power of %d is: %d", base, power, poweredBase);
}

else if (choice == 6) {
printf("Log base 10! Which number would you like to get the log base 10 value of?\n");

int num;
scanf("%d", &num);
double logBase10 = logOf10(num); //get log of base 10 values

char expression[MAX_LEN];
sprintf(expression, "log10(%d) = %f", num, logBase10); //formatting the expression, to add to history
addToHistory(expression, hist); //Adding to history

printf("%d in log base 10 is: %f\n", num, logBase10);
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
printf("Would you like to see the history of previous calculations? (Either Type 'Yes' or 'No')\n");
char viewOrNot[3];
scanf("%s", viewOrNot); //taking the user's decision to view history or not
if (strcmp(viewOrNot, "Yes") == 0 || strcmp(viewOrNot, "yes") == 0 || strcmp(viewOrNot, "YES") == 0) {
    history(hist); //viewing the history
}
else {
    printf("Okay! No history will be shown.\n");
}
printf("Do you desire to do another caluclation? (Either Type 'Yes' or 'No')\n");
scanf("%s", decision); //taking the user's decision to continue using the calculator or not
}//while loop
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
double exponents(double base, double power) {
return pow(base, power);
}

double logOf10(int num) {
return log10(num); //get log of base 10 values
}

void fractions(int numerator1, int denominator1, int numerator2, int denominator2, int func) {
if (denominator1 == 0 || denominator2 == 0) { //checking for zero denominators
    printf("Error: Denominator cannot be zero.\n");
    return;
}
//involving fractions
int numerator, denominator; //declaring final
if (func == 1) { //add
if (denominator1 == denominator2) { //if same denominator
    numerator = numerator1 + numerator2;
    printf("The fraction is: %d / %d\n", numerator, denominator1);
}
else {//for different denominators
    numerator = (numerator1 * denominator2) + (numerator2 * denominator1);
    denominator = denominator1 * denominator2;
    printf("The fraction is: %d / %d\n", numerator, denominator);
}
}

else if (func == 2) { //subtract
    numerator = numerator1 * denominator2 - numerator2 * denominator1; //final numerator
    denominator = denominator1 * denominator2; //final denominator
    printf("The fraction is %d / %d\n", numerator, denominator);
}

else if (func == 3) { //multiply
if (denominator1 == numerator2) { //if denominator of first is numerator of second
    numerator = numerator1; //final numerator
    denominator = denominator2; //final denominator
    printf("The fraction is %d / %d\n", numerator, denominator);
}
else if (denominator2 == numerator1) { //if denominator of second is numerator of first
    numerator = numerator2; //final numerator
    denominator = denominator1; //final denominator
    printf("The fraction is %d / %d\n", numerator, denominator);
}
else {
    numerator = numerator1 * numerator2; //final numerator
    denominator = denominator1 * denominator2; //final denominator
    printf("The fraction is %d / %d\n", numerator, denominator);
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
double base = numerator1 / denominator1; //base
double power = numerator2 / denominator2; //power
double finalFraction = exponents(base, power); //powered fraction
}

}

void addToHistory(char* expression, char[][MAX_LEN]) {
    for (int i = 0; i < MAX_LEN; i++) {
        if (hist[i][0] == '\0') { //finding the first vacant slot
              strcpy(hist[i], expression); //bringing in the expression to the history
              break; //this stops subseqeunt additions of the same expression
        }
        else {
            continue; //just go to the next one
        }
    }
}

void history(char[][MAX_LEN]) {
printf("Here are the previous calculations:\n");
for (int i = 0; i < MAX_LEN; i++) {
    if (hist[i][0] != '\0') { //string not empty
        printf("%s\n", hist[i]);
    }
    else {
        break; //if empty, stop
    }
}
}

/*
© 2025 Rishi
Last updated: 11th August, 2025
*/


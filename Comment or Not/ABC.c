#include<stdio.h> //Header file 
int main(){ 
printf("Hello !!!!!!\n\n"); // for printing Hello 
/* 
Program to find max nu from three numbers 
using ternary operations 
without if elsestatements 
*/ 
int a =10,b=12 , c =5; 
int z = a>b&&a>c?a:b>c?b:c; 
printf("%d",z); //printing greatest number 
}
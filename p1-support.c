#include "p1-support.h"
#include <stdio.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////
//
// File           : p1support.c
// Description    : This is a set of general-purpose utility functions 
//                  we use for the 257 project #1. Fall 2022
// Author         :	Feyza Sakin
// Date           :	10/10/22
// Notes          : 


////////////////////////////////////////////////////////////////////////
// Function Definitions
////////////////////////////////////////////////////////////////////////

//Function definitions as decribed in the project manual 

//This function prints out the array of integer values
void display_array(unsigned int* arr, int size){
	int i;
	printf("{");
	for(i = 0;i<size;i++){
		printf("%4d%s",arr[i],(i==9)?"":",");
	}
	printf("}\n");

}


//Additional function definitions for helper functions
//Shortly describe each function above the function definition.

//Description: num1 is added 1 until i value becomes num2
//Completion date: 10/06/22
int bitwise_add(int num1, int num2)
{
	//check if num2 is 0 or not and iterate until there is a carry	
	while (num2 != 0) 
	{
		//m is the carry
		//it becomes the common of num1 and num2
		unsigned m = num1 & num2; 
		//sum of num1 and num2 when at least one of the bits is not set
		num1 = num1 ^ num2;
		//carry is shifter by one so that num1 gives the requied sum
		num2 = m << 1;
	}
	return num1;
}

//Description: Left shifting num1 until i value becomes num2
//Completion date: 10/06/22
int bitwise_shift_left(int num1, int num2)
{
	int i=1;
	//the carry
	int m=1;
	//if num2 is bigger than 0, then left shift num1 until i value becomes num2
	//left shift num1 until i value becomes bigger than num2
	while(i<=num2){
		//left shifting num1 while i value is smaller or equal to num2 
		num1<<=1;
		//adding one to i value until i value becomes bigger than num2
		while (i&m)
		{
			i = i ^ m;
			m<<=1;
		}
		i = i^m;
		m=1;

	}
	return num1;	
}


//Description:Starting from the most significant of the num, the "if function" adds 1 to the counter as long as the significant is 1
//Completion date: 10/07/22
int count_set_bits(int num){
	int m=1;
	int counter=0;
	int i;
	//Starting from the least significant to the most, the for loop adds one to the counter whenever digit is 1
	for(i=1; i<=32; i++){
		//if the digit is 1, then add one to the counter
		if(num&m){
			counter++;
		}
		//move to the next more significant
		num = num^m;
		//moves to the more significant
		m<<=1;
	}
	return counter;
}


//Description: To have the string of an unsigned integer, we'll have a string with 35 variables. The first two variables are '0b' and '\0' needs to be added to have a null character as the last index  
//Completion date:10/10/22
void binary_string(unsigned int num, char str[BUFSZ]){	
	//setting '0b' as the first two elements of the str array
	str[0]='0';
	str[1]='b';
	//setting '\0' as the last index
	str[34]='\0';
	int a;
	//rest of the variables are set to the binary number of the number 
	for(a=2; a<=33;a++){
		str[a]=bit_get(num,33-a)+'0';
	}

}


//Description: 32 mod of an input is the last 5 least significants of a binary number. To find it,we add 31 to the given number since using and operation with the given number and 31(with 11111 binary number) would return the last 5 digits of the number  
//Completion date: 10/10/22
int bitwise_mod32(int num){
	//number 31 has '1111' as its binary number
	int mod=31;
	//using and operation with number 31 will return the 32 mod of the number
	num=mod&num;
	return num;
}

//Description:if the most significant of the binary number is 1, then it means the number is a negative number. To turn it into a positive number, we flip all the binary numbers and add 1. If it's a positive number, then we return the number 
//Completion Date: 10/09/22
int bitwise_abs(int num){
	int increase=1;
	//the position of the most significant
	int position =31;
	//if the most significant is 1, then it's negative
	if((num>>position)&1){
		//flip the number
		num=~num;
		//add 1
		while(num&increase){
			num=num^increase;
			increase<<=1;
		}
		num=num^increase;
		increase<<=1;
		//return the number
		return num;
	}
	//if the most significant is 0, then it's positive
	else if((num>>position)^1){
		//return the number
		return num;
	}
}

//Description:To look to the offset(nth) digit of the given input, we use left shift for offset. Then we return that number.
//Completion date: 10/10/22
int bit_get(int num,int offset){
	//if the nth significant of the binary number is 1, then return 1
	if((num>>offset)&1){
		return 1;
	}
	//if the flipped of the nth significant of the binary number is 1,then return 0.  
	else if(((~num)>>offset)&1){
		return 0;
	}
}

//Description: If the input has a 1 in its least significant, then it'll be true in the "if statement" and return 1 since it's an odd number. If the input has a 0 in its least significant, then it'll be true in the "else if statement" and return 0 since it's an even number.
//Completion date: 10/8/22
int odd_or_even(unsigned int num){
	int m=1;
	//if the least significant is 1, then it is an odd number
	if(num&m){
		return 1;  
	}
	//if the least significant is 0, then it is an even number
	else if((~num)&m){
		return 0;
	}

}

//Description:To swap two integers, we use XOR operation three times. 
//Completion date: 10/10/22
void swap_ints(int *a,int *b){
	//*b equals to the addition or difference between a and b
	*b=*b^*a;
	//*a equals to the addition or subtraction of *b(difference between a and b) and *a will set *a to *b 
	*a=*b^*a;
	//*b equals to the addition or subtraction of *b(difference between a and b) and *b wil set *b to *a
	*b=*b^*a;
}



#include "inputvalidation.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/*
  function checks if format is correct
  @numArgsRead: number of args the user entered
  @numArgsNeed: number of args for the format to be valid
  @return: true if format is valid
  */
bool isValidFormat(const int numArgsRead, const int numArgsNeed)
{
  bool formatIsGood = numArgsRead == numArgsNeed;
  char character;
  do{
    scanf("%c", &character);
		if(!isspace(character)){ 
			formatIsGood = false;
		}
	}while(character != '\n'); 
  return formatIsGood;
}
/*
  function checks if a value is between a lower and upper bound
  @value: the value to check
  @lower: lower bound
  @upper: upper bound
  @return: true if the function is between the two values
  */
bool isBetween(int value, int lower, int upper)
{
    return value >= lower && value <= upper;
}

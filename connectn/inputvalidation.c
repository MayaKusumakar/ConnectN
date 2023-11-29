#include "inputvalidation.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

bool isBetween(int value, int lower, int upper)
{
    return value >= lower && value <= upper;
}




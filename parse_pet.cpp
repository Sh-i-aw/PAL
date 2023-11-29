/*
* Problem statement: 
    Define a struct which represent a pet that has three fields: 
        1. string holding its name 
        2. int holding its age 
        3. float holding its weight 
    Given a string delimited with commas that represent information about a pet. (name, age, weight)
    Write a function that takes a pointer to a pet struct, and populate the struct using the parsed information.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#pragma warning (disable:4996)

#define kOpenErr -1

#define kName 20
#define kBuf 100

typedef struct Pet
{
    char name[kName];
    int age;
    float weight;
} Pet;

void clearNewLine(char* sentence);
int parsePet(Pet* newPet, char* record);

int main(void) {


    char line[] = "momo,8,4.5";
    Pet newPet;
    
    int result = parsePet(&newPet, line); 
    
    printf("\nPet name: %s, Pet age: %d, Pet weight: %.2f kg", newPet.name, newPet.age, newPet.weight); 


    return 0;
    
}


int parsePet(Pet* newPet, char* record)
{
    // finds the 2 commas in the string that was just read in from file 
    // clear the new line character 

    char* firstComma = strchr(record, ',');
    char* secondComma = strrchr(record, ',');

    if (firstComma == NULL || secondComma == NULL)
    {
        return -1;
    }
    else
    {
        clearNewLine(record);
    }


    int len = strlen(record);

    // parse out the name 
    int nameLen = firstComma - record;

    char pName[kBuf] = { 0 };
    if (strncpy(pName, record, nameLen) == NULL)
    {
        return -1; 
    }
    else
    {
        pName[nameLen] = '\0';
        printf("Pet name: %s\n", pName);
        strcpy(newPet->name, pName); 
    }

    // parse out the age

    int ageLen = secondComma - firstComma - 1;

    char pAge[kBuf] = { 0 };
    if (strncpy(pAge, firstComma + 1, ageLen) == NULL)
    {
        return -1; 
    }
    else 
    {
        pAge[ageLen] = '\0';
        printf("Pet age: %s\n", pAge);
        newPet->age = atoi(pAge);
    }



    // parse out the weight 
    char pWeight[kBuf] = { 0 };
    if (strcpy(pWeight, secondComma + 1) == NULL)
    {
        return -1;
    }
    else
    {
        printf("Pet weight: %s", pWeight); 
        newPet->weight = atof(pWeight);
    }


    return 0; 
    
}

void clearNewLine(char* sentence)
{
    char* newLine = strrchr(sentence, '\n'); 
    if (newLine != NULL)
    {
        *newLine = '\0';
    }
}

#include<iostream>
#include "../include/string_functions.h"

void ToUpper(char * text)
{
    int counter =0;
    while(text[counter] != '\0')
    {
        if(text[counter] >= 'a' && text[counter] <= 'z' )
        {
            text[counter] -= 32;
        }
        counter++;
    }
}

void ToLower(char * text)
{
    int counter =0;
    while(text[counter] != '\0')
    {
        if(text[counter] >= 'A' && text[counter] <= 'Z' )
        {
            text[counter] += 32;
        }
        counter++;
    }
}

// compare by length and by string value
bool StringCompare(char * str1 , char * str2)
{
    int counter = 0;
    while(str1[counter] != '\0' && str2[counter] != '\0')
    {
        if(str1[counter] != str2[counter])
            return false;
        
        counter ++;
    }
    if(str1[counter] == '\0' && str2[counter] == '\0')
        return true;

    if(str1[counter] != '\0')
    {
        std::cout<<"Strings dont have the same length first string longer in length"<<std::endl;
        return false;
    }

    if(str2[counter] != '\0')
    {
        std::cout<<"Strings dont have the same length second string longer in length"<<std::endl;
        return false;
    }
    return false;
}

char* StringCopy(char* str)
{
    // get string size
    int counter = 0;
    while(str[counter] != '\0')
    {
        counter++;
    }
    char * str_copy = new char[counter + 1]; // declaring it dynamic to be allocated in heap to be able to be returned by the func

    for(int i =0;i<counter;i++)
    {
        str_copy[i] = str[i];
    }

    str_copy[counter] = '\0';

    return str_copy;
}
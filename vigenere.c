#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    int shift;
    int KeyValue;
    
    if (argc != 2)
    {
        printf("Incorrect command line input.");
        return 1;
    }
    
    string key = argv[1];
    
    for (int n = 0, keylength = strlen(argv[1]); n < keylength; n++)
    {
        if ((key[n] >= '0') && (key[n] <= '9'))
        {
            printf("Letters only.");
            return 1;
        }
    }   
    
    string phrase = GetString();
        
    for (int i = 0, j = 0, length = strlen(phrase); i < length; i++, j++)
    {
        if (j >= strlen(key))
        {
            j = 0;
        }
            
        KeyValue = key[j];
            
        if (!isalpha(phrase[i]))
        {
            j = (j - 1);
        }
            
        if ((KeyValue >= 'A') && (KeyValue <= 'Z'))
        {
            KeyValue = (KeyValue - 'A');
        }
            
        if ((KeyValue >= 'a') && (KeyValue <= 'z'))
        {
            KeyValue = (KeyValue - 'a');
        }
            
        shift = (phrase[i] + KeyValue);
            
        if (isupper(phrase[i]) && (shift > 'Z'))
        {
            shift = (shift - 26);
        }
        
        if (islower(phrase[i]) && (shift > 'z'))
        {
            shift = (shift - 26);
        }
    
        if (isalpha(phrase[i]))
        {
            printf("%c", shift);
        }
         
        else
        {
            printf("%c", phrase[i]);
        }
    }
    printf("\n");
    return 0;
}
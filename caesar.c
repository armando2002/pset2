#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    bool keytrue = false;
    int key = 0;
    int keylength = 0;
    string phrase = "";
 
    do
    {
        if(argc != 2)
        {
            printf("Enter a single encryption key.\n");
            return 1;
        }
        else
        {
            key = atoi(argv[1]);
            keytrue = true;
        }
    }
    while(!keytrue);
    
    phrase = GetString();
    keylength = strlen(phrase);
    for(int i = 0; i < keylength; i++)
    {
        if(isalpha(phrase[i]))
        {
            if(islower(phrase[i]))
            {
                printf("%c", ((((phrase[i] - 97)+key)%26)+97));
            }
            else
            {
                printf("%c", ((((phrase[i] - 65)+key)%26)+65));
            }

        }
        else
        {
            printf("%c", phrase[i]);
        }
    }
    printf("\n");
    return 0;
}

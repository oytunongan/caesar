#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rotate(string text);
int key = 0;

int main(int argc, string argv[])
{
    if ((argc != 2))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int length = strlen(argv[1]);
    int check = 0;
    for (int i = 0; i < length; i++)
    {
        if (isdigit(argv[1][i]) == 0)
        {
            check++;
        }
    }
    if (check != 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    key = atoi(argv[1]);
    string text = get_string("plaintext:  ");
    rotate(text);
    return 0;
}
void rotate(string text)
{
    printf("ciphertext: ");
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
        {
            for (int k = 0; k < key; k++)
            {
                if (isalpha(text[i]) != 0)
                {
                    text[i]++;
                }
                if (isalpha(text[i]) == 0)
                {
                    text[i] -= 26;
                }
            }
            printf("%c", text[i]);
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}
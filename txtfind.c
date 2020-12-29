#include <stdio.h>

int main(int argc, char const *argv[])
{
    char **word;
    char command;
    getCommand(word, &command);

    if (command == 'a') //line
    {
        /* code */
    }
    else if (command == 'b') //word
    {
        /* code */
    }

    return 0;
}

int getCommand(char **word, char *command);

int substring(char *str1, char *str2);

int getNextWord(char *txt, char *str, int pos);

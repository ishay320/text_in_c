#include <stdio.h>

#define WORD 30
#define LINE 256

int substring(char *str1, char *str2);
int getNextWord(char *txt, char *str, int pos);
int getCommand(char *word, char *command);

int main()
{
    char word[WORD];
    char command = '0';
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
/**
 * @brief Get the Command and the word
 * 
 * @param word the place to put the word
 * @param command the place for the command
 * @return int 1 if succeeded -1 if failed
 */
int getCommand(char *word, char *command)
{
    char current;
    scanf(" %c", &current);

    for (int i = 0; i < WORD; i++)
    {
        if (current == ' ')
        {
            *command = current;
            i = WORD;
        }
        else if (current == '\n')
        {
            i = WORD;
        }

        word[i] = current;
        current = *(word + 1);
    }
    return 1;
}

/**
 * @brief check if str2 is in str1
 * @param str1 the word to be checked
 * @param str2 the word that checks
 * @return int 
 *      if true return the diff size,
 *      if false return -1
 */
int substring(char *str1, char *str2)
{
    int sizeDiff = 0;
    char c1 = *str1;
    char c2 = *str2;
    int i = 1;
    int j = 1;
    while (c1 != '\0' && c2 != '\0')
    {
        if (c1 == c2)
        {
            c1 = *(str1 + i++);
            c2 = *(str2 + j++);
        }
        else
        {
            c1 = *(str1 + i++);
            sizeDiff++;
        }
    }
    if (c2 == '\0')
    {
        while (c1 != '\0')
        {
            c1 = *(str1 + i++);
            sizeDiff++;
        }
        return sizeDiff;
    }

    return -1;
}

/**
 * @brief Get the next Line
 * 
 * @param line is the pointer to empty array
 * @return int the length of the line if error -1
 */
int getLine(char *line)
{
    int sizeOfLine = 0;
    char c;
    if (scanf(" %c", &c) == 0)
    {
        printf("error");
        return -1;
    }
    *line = c;
    while (c != '\n')
    {
        if (scanf(" %c", &c) == 0)
        {
            printf("error");
            return -1;
        }
        *(line + ++sizeOfLine) = c;
    }

    return sizeOfLine;
}
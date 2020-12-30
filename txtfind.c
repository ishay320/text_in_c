#include <stdio.h>

#define WORD 30
#define LINE 256

int substring(char *str1, char *str2);
int getNextWord(char *txt, char *str, int wordSize, int wordNumber);
int getCommand(char *line, char *word, char *command);

int main()
{
    char word[WORD];
    char wordInLine[WORD];
    char command = '0';
    char line[LINE];
    fgets(line, LINE, stdin); //gets the line
    getCommand(line, word, &command);

    if (command == 'a') //line
    {
        int lineCount = 1;
        while (lineCount++ != 250)
        {
            if (fgets(line, LINE, stdin) == 0) //gets the line
            {
                break;
            }

            int i = 1;
            int hasAWord = 0;
            while (getNextWord(line, wordInLine, WORD, i++)) //get next word
            {
                if (substring(wordInLine, word) > -1 && substring(wordInLine, word) < 2)
                {
                    hasAWord = 1;
                    break;
                }
            }
            if (hasAWord)
            {
                printf("%s", line);
            }
        }
    }
    else if (command == 'b') //word
    {
        int lineCount = 1;
        while (lineCount++ != 250)
        {
            if (fgets(line, LINE, stdin) == 0) //gets the line
            {
                break;
            }

            int i = 1;
            while (getNextWord(line, wordInLine, WORD, i++)) //get next word
            {
                if (substring(wordInLine, word) > -1 && substring(wordInLine, word) < 2)
                {
                    printf("%s\n", wordInLine);
                }
            }
        }

        return 0;
    }
}

/**
 * @brief Get the Command and the word
 * 
 * @param line is the line to read from
 * @param word the place to put the word
 * @param command the place for the command
 * @return int 1 if succeeded -1 if failed
 */
int getCommand(char *line, char *word, char *command)
{
    char temp[WORD];
    if (!getNextWord(line, word, WORD, 1))
    {
        printf("error");
        return -1;
    }
    if (!getNextWord(line, temp, WORD, 2))
    {
        printf("error");
        return -1;
    }
    *command = *temp;
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
 * @brief Get the Next Word number "wordNumber"
 *        starts from 1
 * @param txt the txt to look in
 * @param str the returned word
 * @param wordSize the size of word array
 * @param wordNumber what number of word to look
 * @return int return 1 if succeeded 0 if no word found
 */
int getNextWord(char *txt, char *str, int wordSize, int wordNumber)
{
    int i = 0;
    int posInWord = 0;
    int passedWord = 0;
    while (*(txt + i) != '\n' && *(txt + i) != '\0' && passedWord != wordNumber)
    {
        if (*(txt + i) != '\t' && *(txt + i) != ' ' && *(txt + i) != '\r')
        {
            if (posInWord + 2 >= wordSize)
            {
                printf("error: word is too big");
                return -1;
            }
            *(str + posInWord++) = *(txt + i++);
            *(str + posInWord) = '\0';
        }
        else
        {
            if (posInWord)
            {
                passedWord++;
            }
            posInWord = 0;
            i++;
        }
    }
    if (passedWord == wordNumber && wordNumber > 0)
    {
        return 1;
    }
    *(str) = '\0';
    return 0;
}

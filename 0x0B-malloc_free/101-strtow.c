#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **strtow(char *str) {
    if (str == NULL || *str == '\0') {
        return NULL;
    }
    
    char *temp_str = str;
    int word_count = 0;
    
    /* Count the number of words */
    while (*temp_str != '\0') {
        while (*temp_str == ' ') {
            temp_str++;
        }
        if (*temp_str != '\0') {
            word_count++;
            while (*temp_str != ' ' && *temp_str != '\0') {
                temp_str++;
            }
        }
    }
    
    /* Allocate memory for the array of strings */
    char **words = (char **)malloc((word_count + 1) * sizeof(char *));
    if (words == NULL) {
        return NULL;
    }
    
    temp_str = str;
    
    /* Extract words and store them in the array */
    int index = 0;
    while (*temp_str != '\0') {
        while (*temp_str == ' ') {
            temp_str++;
        }
        if (*temp_str != '\0') {
            char *start = temp_str;
            while (*temp_str != ' ' && *temp_str != '\0') {
                temp_str++;
            }
            int word_length = temp_str - start;
            char *word = (char *)malloc((word_length + 1) * sizeof(char));
            if (word == NULL) {
                /* Memory allocation failed, free previously allocated memory */
                for (int i = 0; i < index; i++) {
                    free(words[i]);
                }
                free(words);
                return NULL;
            }
            strncpy(word, start, word_length);
            word[word_length] = '\0';
            words[index] = word;
            index++;
        }
    }
    
    words[word_count] = NULL;  /* Set the last element to NULL */
    
    return words;
}

int main() {
    char str[] = "This is a test string";
    char **words = strtow(str);
    
    if (words != NULL) {
        int i;
        for (i = 0; words[i] != NULL; i++) {
            printf("%s\n", words[i]);
            free(words[i]);
        }
        free(words);
    }
    
    return 0;
}

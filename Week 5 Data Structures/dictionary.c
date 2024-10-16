// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    node *p = NULL;
    for (p = table[hash(word)]; p != NULL; p = p->next)
    {
        if (!strcasecmp(word, p->word))
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *p = fopen(dictionary, "r");
    if (p == NULL)
    {
        return false;
    }
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    char *word = malloc(LENGTH + 1);
    if (word == NULL)
    {
        fclose(p);
        return false;
    }
    while (fscanf(p, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            free(word);
            fclose(p);
            return false;
        }
        strcpy(n->word, word);
        n->next = table[hash(word)];
        table[hash(word)] = n;
    }
    free(word);
    fclose(p);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    int num = 0;
    node *p = NULL;
    for (int i = 0; i < N; i++)
    {
        for (p = table[i]; p != NULL; p = p->next)
        {
            num++;
        }
    }
    return num;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    node *p = NULL;
    node *tmp = NULL;
    for (int i = 0; i < N; i++)
    {
        p = table[i];
        while (p != NULL)
        {
            tmp = p;
            p = p->next;
            free(tmp);
        }
    }
    return true;
}

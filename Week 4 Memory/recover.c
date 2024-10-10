#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define BLOCK 512

// 这勾八作业做得我是云里雾里的，怎么突然就跑起来了？

int main(int argc, char *argv[])
{
    // Check correctly
    if (argc != 2)
    {
        printf("Usage: ./recover raw\n");
        return 1;
    }
    // Open the card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Cannot open the file.\n");
        return 1;
    }
    // Check the header
    uint8_t buffer[BLOCK];
    int check = 0;
    int file_num = 0;
    char *filename = malloc(8);
    FILE *file = NULL;
    while (fread(&buffer, BLOCK, 1, card) != 0)
    {
        // If is JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(filename, "%03i.jpg", file_num);
            // First
            if (check == 0)
            {
                check++;
                file = fopen(filename, "w");
                if (file != NULL)
                {
                    fwrite(&buffer, BLOCK, 1, file);
                }
            }
            // A new one
            else
            {
                fclose(file);
                sprintf(filename, "%03i.jpg", file_num);
                file = fopen(filename, "w");
                if (file != NULL)
                {
                    fwrite(&buffer, BLOCK, 1, file);
                }
            }
            file_num++;
        }
        // Else
        else
        {
            if (file != NULL)
            {
                fwrite(&buffer, BLOCK, 1, file);
            }
        }
    }
    fclose(file);
    fclose(card);
    free(filename);
}

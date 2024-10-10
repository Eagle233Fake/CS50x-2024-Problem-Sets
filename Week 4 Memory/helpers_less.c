#include "helpers.h"

#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    double avg;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avg = round((image[i][j].rgbtGreen + image[i][j].rgbtRed + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = (int) avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen +
                                    .189 * image[i][j].rgbtBlue);
            double sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen +
                                      .168 * image[i][j].rgbtBlue);
            double sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen +
                                     .131 * image[i][j].rgbtBlue);
            if ((int) sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if ((int) sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if ((int) sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            image[i][j].rgbtRed = (int) sepiaRed;
            image[i][j].rgbtGreen = (int) sepiaGreen;
            image[i][j].rgbtBlue = (int) sepiaBlue;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image_reflect[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image_reflect[i][width - 1 - j].rgbtRed = image[i][j].rgbtRed;
            image_reflect[i][width - 1 - j].rgbtGreen = image[i][j].rgbtGreen;
            image_reflect[i][width - 1 - j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = image_reflect[i][j].rgbtRed;
            image[i][j].rgbtGreen = image_reflect[i][j].rgbtGreen;
            image[i][j].rgbtBlue = image_reflect[i][j].rgbtBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double avg_r = 0, avg_g = 0, avg_b = 0;
            int check = 0;
            for (int k = i - 1; k <= i + 1; k++)
            {
                for (int l = j - 1; l <= j + 1; l++)
                {
                    if (k >= 0 && l >= 0 && k <= height - 1 && l <= width - 1)
                    {
                        check++;
                        avg_r += image[k][l].rgbtRed;
                        avg_g += image[k][l].rgbtGreen;
                        avg_b += image[k][l].rgbtBlue;
                    }
                }
            }
            avg_r = round(avg_r / check);
            avg_g = round(avg_g / check);
            avg_b = round(avg_b / check);
            copy[i][j].rgbtRed = (int) avg_r;
            copy[i][j].rgbtGreen = (int) avg_g;
            copy[i][j].rgbtBlue = (int) avg_b;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = copy[i][j].rgbtRed;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
            image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
        }
    }
    return;
}

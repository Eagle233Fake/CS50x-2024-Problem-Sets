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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int Gx[3] = {0}, Gy[3] = {0};
            int x[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
            int y[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
            for (int k = i - 1; k <= i + 1; k++)
            {
                for (int l = j - 1; l <= j + 1; l++)
                {
                    if (k >= 0 && l >= 0 && k <= height - 1 && l <= width - 1)
                    {
                        Gx[0] += x[k - i + 1][l - j + 1] * image[k][l].rgbtRed;
                        Gy[0] += y[k - i + 1][l - j + 1] * image[k][l].rgbtRed;
                        Gx[1] += x[k - i + 1][l - j + 1] * image[k][l].rgbtGreen;
                        Gy[1] += y[k - i + 1][l - j + 1] * image[k][l].rgbtGreen;
                        Gx[2] += x[k - i + 1][l - j + 1] * image[k][l].rgbtBlue;
                        Gy[2] += y[k - i + 1][l - j + 1] * image[k][l].rgbtBlue;
                    }
                }
            }
            double check[3];
            for (int n = 0; n < 3; n++)
            {
                check[n] = round(sqrt(Gx[n] * Gx[n] + Gy[n] * Gy[n]));
            }
            if (check[0] > 255)
            {
                copy[i][j].rgbtRed = 255;
            }
            else
            {
                copy[i][j].rgbtRed = (int) check[0];
            }
            if (check[1] > 255)
            {
                copy[i][j].rgbtGreen = 255;
            }
            else
            {
                copy[i][j].rgbtGreen = (int) check[1];
            }
            if (check[2] > 255)
            {
                copy[i][j].rgbtBlue = 255;
            }
            else
            {
                copy[i][j].rgbtBlue = (int) check[2];
            }
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

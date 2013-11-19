/****************************************************************************
 * resize.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, and changes it's size.
 ***************************************************************************/
       
#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: copy infile outfile\n");
        return 1;
    }

    // remember filenames
    float n = atoi(argv[1]);
    char* infile = argv[2];
    char* outfile = argv[3];

    if (n < 0 || n > 100)
    {
        printf("Enter a number greater than 0 and less than 100.\n");
        return 1;
    }

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // save old image dimensions
    int old_width = bi.biWidth;
    int old_height = bi.biHeight;

    // save new image dimensions
    bi.biWidth = bi.biWidth * n;
    bi.biHeight = bi.biHeight * n;
    
    // determine padding for scanlines
    int old_padding =  (4 - (old_width * sizeof(RGBTRIPLE)) % 4) % 4;
    int new_padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // determine new header sizes
    bi.biSizeImage = (((bi.biWidth + new_padding) * abs(bi.biHeight)) * sizeof(RGBTRIPLE));
    bf.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + bi.biSizeImage;

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER                                                                          
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // allocate space in memory to hold copy of scanline
    RGBTRIPLE *scanline_copy = malloc(sizeof(RGBTRIPLE) * bi.biWidth);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(old_height); i < biHeight; i++)
    {
        int tracker = 0;
        // iterate over pixels in scanline
        for (int j = 0; j < old_width; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // save pixels to scanline copy 'n' times
            for (int counter = 0; counter < n; counter++)
            {
                *(scanline_copy + (tracker)) = triple;
                tracker++;
            }
        }

        // skip over padding, if any
        fseek(inptr, old_padding, SEEK_CUR);

        // write RGB triple to outfile
        for (int m = 0; m < n; m++)
        {
            // original code commented out
            // "fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);""
            fwrite(scanline_copy, sizeof(RGBTRIPLE), bi.biWidth, outptr);

            // add padding to outfile
            // "then add it back (to demonstrate how)""
            for (int k = 0; k < new_padding; k++)
                fputc(0x00, outptr);
        }
    }

    // free memory from scanline_copy
    free(scanline_copy);

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}

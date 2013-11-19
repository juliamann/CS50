/****************************************************************************
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 ***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;

int main(void)
{
	// open jpeg input file
	FILE* infile = fopen("card.raw", "r");

	// exit if there's a problem with opening the jpg file
	if (infile == NULL)
    {
        printf("Could not open %s.\n", "card.raw");
        return 1;
    }

    // declare jpeg outfile
    FILE* outfile = NULL;

    // save size of jpg block
    int jpg_blocksize = 512;

    // make buffer to store jpg blocks
    BYTE buffer[jpg_blocksize];

    // create jpeg filename
    char jpg_name[8];

    // variable to keep track of jpg number found out of 51
    int jpg_number = 1;

    // keep track of when a jpg is found
    bool jpg_found = false;

    // search for jpgs until EOF
    while (feof(infile) == 0)
    {
    	// read 512 byte block into buffer
    	fread(buffer, jpg_blocksize, 1, infile);

    	// check buffer for jpeg match 
    	if (buffer[0] == 255 && buffer[1] == 216 && buffer[2] == 255 && (buffer[3] == 224 || buffer[3] == 225))
    	{
    		// if previous jpg was found, close file
    		if (jpg_found == true)
    		{
    			fclose(outfile);
    		}

    		jpg_found = true;

    		// name the new jpg image
    		sprintf(jpg_name, "%3d.jpg", jpg_number);
    		jpg_number++;

    		// write jpg image to outfile
    		outfile = fopen(jpg_name, "w");
    		if (outfile == NULL)
    		{
    			printf("Could not create %s.\n", jpg_name);
    			return 3;
    		}

    		// write jpg block byte to jpg file
    		fwrite(buffer, jpg_blocksize, 1, outfile);
    	}

    	// keep writing jpg to file on disk
    	else if (jpg_found == true)
    	{
    		fwrite(buffer, jpg_blocksize, 1, outfile);
    	}
    }

    // close files
    fclose(infile);
    fclose(outfile);
}
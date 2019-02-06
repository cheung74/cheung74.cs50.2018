#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    //Make sure to have one command line argument
    if (argc != 2)
    {
       fprintf(stderr, "Please enter the file\n");
       return 1;
    }
    //Open the file entered into the command line
    FILE *file = fopen(argv[1], "r");

    if (file  == NULL)
    {
      fprintf(stderr, "Could not open %s.\n", argv[1]);
      return 2;
    }

    //Create outfile for pic
    FILE *img = NULL;

    //Create buffer and filename arrays
    unsigned char buffer [512];
    char filename[8];

    //Set up counter for filename
    int counter = 0;

    //Set flag
    bool flag = false;

    //Read the file
    while (fread(buffer, 512, 1, file) == 1)
    {
        //Check if there at the beginning of JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (flag == true)
            {
                fclose(img);
            }
            //condition found JPEG
            else
            {
                flag = true;
            }

            sprintf(filename, "%0.3i.jpg", counter);
            img = fopen(filename, "w");
            counter++;
        }

        if (flag == true)
        {
            fwrite(&buffer, 512, 1, img);
        }
    }
    fclose(file);
    fclose(img);

    return 0;
}
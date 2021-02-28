

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * file_1;
    char sentence[50];

    char c;
    int characters, words, lines;


    //enter the path (f.text)
    printf("Enter the path: ");
    scanf("%s",sentence);

    //opening in read mode
    file_1 = fopen(sentence, "read");


   //check if it open successfully if any error output as printf statement as printf command
    if (file_1 == NULL)
    {
        printf("\nUnable to open file.\n");
        printf("Please check if file exists and you have read privilege.\n");

        exit(EXIT_FAILURE);
    }

    
      //Logic to count characters, words and lines.

    characters = words = lines = 0;
    while ((c = fgetc(file_1)) != EOF)
    {
        characters++;

        // Check new line 
        if (c == '\n' || c == '\0')
            lines++;

        // Check words 
        if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
            words++;
    }

    /* Increment words and lines for last word */
    if (characters > 0)
    {
        words++;
        lines++;
    }

    //printing the result
    printf("\n");
    printf("Total characters = %d\n", characters);
    printf("Total words      = %d\n", words);
    printf("Total lines      = %d\n", lines);


    /* Close files to release resources */
    fclose(file_1);

    return 0;
}

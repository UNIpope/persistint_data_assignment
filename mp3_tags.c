#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

   char tag[3];
   char title[30];
   char artist[30];
   char album[30];
   char year[4];
   char comment[30];
   char genre;

}mp3Tags;


int main()
{

   mp3Tags currentTags;

   char fileName[101];
   FILE *mp3File;


   printf("MP3 file name: ");
   fgets(fileName, 100, stdin);

   fileName[strlen(fileName)-1] = '\0';



   // Open mp3 file and gen
   mp3File = fopen(fileName, "rb");


   if (mp3File == NULL)
   {

      printf("\nError.\n");
      exit(0);

   }

    fseek(mp3File, 0, SEEK_END);
    long pos = ftell(mp3File);// Get position
    fseek(mp3File, (pos - sizeof(mp3Tags)), SEEK_SET);


   // Read mp3 tags
   if(fread(&currentTags, sizeof(mp3Tags), 1, mp3File) != 1)
   {
      printf("\nUnable to read tags!\n");

      exit(0);

  }

    //printing stuff
   printf("\n\nFile reads:\n");
   printf("Title: %s\n", currentTags.title);
   printf("Artist: %s\n", currentTags.artist);
   printf("Album: %s\n", currentTags.album);
   printf("Year: %.4s\n", currentTags.year);
   printf("Comment: %s\n", currentTags.comment);
   printf("Genre: %d\n", (int)currentTags.genre);


   // Close mp3 file
   printf("\nClosing mp3 file!\n");
   fclose(mp3File);



   return(0);

}

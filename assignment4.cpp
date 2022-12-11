#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char wordToFind[30];
int count[1]={wordToFind[30]};
void finding();
int main(){
    printf("Enter a word to find : ");
    gets(wordToFind);
    finding();


    return 0;
}

void finding(){
    FILE *reading;
    reading = fopen("word.txt" , "r");

    if (reading == NULL){
        printf("Cannot read the file.\n");
        exit(1);
    } else{
        char tempC;
        int index=0;
        tempC = fgetc(reading);
        while(!feof(reading)){
            if (tempC == wordToFind[index]){
                index++;
                tempC = fgetc(reading);
                if (index == strlen(wordToFind)){
                    count[0]++;
                }
            } else{
                index=0;
                tempC = fgetc(reading);
            }
        }
        fclose(reading);
        if (count[0]>1){
            printf("Found '%s' for %d times.\n",wordToFind,count[0]);
        } else if (count[0]==1){
            printf("Found '%s' for %d time.\n",wordToFind,count[0]);    //just to remove 's' from time.
        } else{
            printf("Not found '%s'.\n",wordToFind);
        }
    }

}

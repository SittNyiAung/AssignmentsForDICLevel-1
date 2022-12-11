//
// Created by Saito on 12/11/2022.
//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void findingWinHtut();
void findingNCC();

char toFind1[7]={'w','i','n','h','t','u','t'};
char toFind2[17]={'N','a','t','i','o','n','a','l','C','y','b','e','r','C','i','t','y'};
int wordsToFind[2]={toFind1[7],toFind2[17]};

int main(){
    findingWinHtut();
    findingNCC();
    return 0;
}

void findingWinHtut(){
    FILE *read1;
    read1 = fopen("word.txt","r");
    if (read1 == NULL){
        printf("[-]Cannot read word.txt file!\n");
        exit(1);
    }else{
        char tempC;
        int index=0;
        tempC = fgetc(read1);
        while(!feof(read1)){
            while(tempC==toFind1[index]){
                index++;
                tempC= fgetc(read1);
                if(index==7){
                    wordsToFind[0]++;
                }
            }
            index=0;
            tempC= fgetc(read1);
        }
        if(wordsToFind[0]==1){
            printf("We found 'winhtut' for %d time.\n",wordsToFind[0]);
        }else if (wordsToFind[0]>1){
            printf("We found 'winhtut' for %d times.\n",wordsToFind[0]); //just for 's' at 'time'
        }else{
            printf("NOt found : %s\n",toFind1);
        }

        fclose(read1);
    }

}

void findingNCC(){
    FILE *read2;
    read2 = fopen("word.txt","r");
    if (read2==NULL){
        printf("[-]Cannot read word.txt file!\n");
        exit(2);
    } else{
        char tempC;
        int index=0;
        tempC = fgetc(read2);
        while(!feof(read2)){
            while(tempC==toFind2[index]){
                index++;
                tempC= fgetc(read2);
                if(index==17){
                    wordsToFind[1]++;
                }
            }
            index=0;
            tempC= fgetc(read2);
        }
        if(wordsToFind[1]==1){
            printf("We found 'NationalCyberCity' for %d time.\n",wordsToFind[1]);
        }else if(wordsToFind[1]>1){
            printf("We found 'NationalCyberCity' for %d times.\n",wordsToFind[1]);
        }else{
            printf("Not Found : %s\n",toFind2);
        }

        fclose(read2);
    }
}
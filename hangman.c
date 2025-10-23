// 6th Hangman game  AK,KS,LL,AT 
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

    //KS list and randomizer
int main(void){
    char words[]= {"ocean","water","kenji","ducky","lukas","smoke","train", "layer","alone","brain","craft","paint","flute","beach","heart","human","image","lemon","lucky","mouse","metal","noise","plane","phone","power","quiet","ready","store","sport","storm","today","table","under","video","watch","young", "slate", "crane", "brick", "slate", "stare", "raise", "arise", "farts", "bread",} ;
    srand(time(NULL));
    int num = rand() %45;
    printf("%c\n",words[num]);
    printf("Hi welcome to hangman!\nThis game consists of an unkown five letter word. First, begin to assemble the word by guessing one letter at a time. Second, if you guess a letter that is not in the word, a strike will appear. If you gain 6 strikes, you're out. Lastly, if you think you know the word, you can guess the whole word at once. Try to fill in the whole word with minimal strikes. Have fun playing!");
    
    //AT if you guess it correctly 
    if %default == "";
    printf("guess a valid letter.");
    return 0;
    else if %default == char word
        exit("Horray! you guessed the word rerun to play again.");
        return 0;
    else if scrl (%default) >1;
    

    // AK if you lose and keeping tack of hangman parts
    int incorrect_hangman_guesses;
    if (incorrect_hangman_guesses ==6){
        printf ("That is incorrect you have 0 worng gueses left. You lose.");
    }else if (incorrect_hangman_guesses == 5){
        printf("That is incorrect. You have ")
    }

    

    
}








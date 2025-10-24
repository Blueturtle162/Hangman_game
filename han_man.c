// LW AT KS AK 6th Team Game Hangman


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// KS made the list and random of the code
const char* words[] = {"ocean","water","kenji","ducky","kayze","eliza","smoke","train", "layer","alone","brain","craft","paint","flute","beach","heart","human","image","lemon","lucky","mouse","metal","noise","plane","phone","power","quiet","ready","store","sport","storm","today","table","under","video","watch","young", "slate", "crane", "brick", "slate", "stare", "raise", "arise", "farts", "bread","among"};
// AK added extra instructions
//AT made the variables that are later used for the input 

int num_words = sizeof(words) / sizeof(words[0]);
char guessed_letters[26] = {0};
int guessed_count = 0;

//AT added user input
//this code is taking  and asking the user input with the letter they guessed and putting it through to see if the letter corresponds with the word and telling it its incorrect if it doesnt and correct if it does with the else and if statments and detecting it
int guess(const char* word) {
    char user_input[100];
    printf("Guess a letter: ");
    fgets(user_input, sizeof(user_input), stdin);
    user_input[strcspn(user_input, "\n")] = 0;
    if (strlen(user_input) == 0) {
        printf("Please enter a valid letter.\n");
        return 0;
    }
    for (int i = 0; i < guessed_count; i++) {
        if (user_input[0] == guessed_letters[i]) {
            printf("You already guessed that letter!\n");
            return 0;
        }
    } 
    if (strcmp(user_input, word) == 0) {
        printf("Horray! You guessed the word! Rerun the code to play again.\n");
        exit(0);
    }
    if (strlen(user_input) > 1) {
        printf("Incorrect. Only guess one letter.\n");
        return 0;
    } else {
        guessed_letters[guessed_count++] = user_input[0];
    }
    if (strchr(word, user_input[0]) != NULL) {
        printf("Correct!\n");
        return 0;
    } else {
        printf("Incorrect, guess again.\n");
        return 1;
    }

    }

//AK built hangman
//53-84 prints hangman
void build_hangman(int strikes){
    if (strikes == 1){
        printf(" O\n");
    }else if (strikes == 2){
        printf(" O\n");
        printf("/\n");
    }else if (strikes == 3){
        printf(" O\n");
        printf("/|\n");
    }else if (strikes == 4){
        printf(" O\n"); 
        printf("/|\\");
        printf("\n");
    }else if (strikes == 5){
        printf(" O\n");
        printf("/|\\");
        printf("\n");
        printf(" |\n");
    }else if (strikes == 6){
        printf(" O\n");
        printf("/|\\");
        printf("\n");
        printf(" |\n");
        printf("/\n");
    }else if (strikes == 7){
        printf(" O\n");
        printf("/|\\");
        printf("\n");
        printf(" |\n");
        printf("/ \\");
        printf("\n");
    }

    
}
// KS random and instructions
int main() {
    srand((unsigned) time(NULL));
    const char* word = words[rand() % num_words];


    const char* space = "_";


    int strikes = 0;


    printf("Hi welcome to hangman! This game consists of an unkown five letter word. First, begin to assemble the word by guessing one letter at a time make sure to only enter lowercase letters with no extra spaces. Second, if you guess a letter that is not in the word, a strike will appear. If you gain 6 strikes, you're out. Lastly, if you think you know the word, you can guess the whole word at once. Try to fill in the whole word with minimal strikes. Have fun playing!\n"); //AK print statement
//AK added extra instructions to make the game more clear
    
    char output_list[6] = {0};



    // Lucas until the end, for all the strikes and printing if you win or lose
     while (strikes < 7) {
        strikes += guess(word);
        guessed_count = strlen(guessed_letters);
        printf("Strikes: %d\n", strikes);
        build_hangman(strikes);
        for (int i = 0; i < strlen(word); i++) {
            char letter = word[i];
            int found = 0;
            for (int j = 0; j < guessed_count; j++) {
                if (letter == guessed_letters[j]) {
                    found = 1;
                    break;
                }
            }
            if (found) {
                output_list[i] = letter;
            } else {
                output_list[i] = space[0];
            }
        }
        output_list[strlen(word)] = '\0';
        printf("%s\n", output_list);
        if (strcmp(word, output_list) == 0) {
            printf("Hooray! You guessed the word! Rerun the code to play again.\n");
            break;


        } else if (strikes==7){

        printf("Sorry, you lost! The word was: %s\n", word);  {
            break;
        }
       
        }
    }


    
     return 0;   
    }
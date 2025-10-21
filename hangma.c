#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <time.h>   
#include <ctype.h>  

int main(void) {
    char* list_of_words[] = {
        "ocean", "water", "kenji", "ducky", "lucas", "smoke", "train", "layer",
        "alone", "brain", "craft", "paint", "flute", "beach", "heart", "human",
        "image", "lemon", "lucky", "mouse", "metal", "noise", "plane", "phone",
        "power", "quiet", "ready", "store", "sport", "storm", "today", "table",
        "under", "video", "watch", "young", "slate", "crane", "brick", "stare",
        "raise", "arise", "farts", "bread","birdy","among"
    };
    int num_words = sizeof(list_of_words) / sizeof(list_of_words[0]);

    srand(time(NULL)); 
    char* secret_word = list_of_words[rand() % num_words];
    int word_len = strlen(secret_word);

    char player_progress[word_len + 1]; 
    for (int i = 0; i < word_len; i++) {
        player_progress[i] = '_';
    }
    player_progress[word_len] = '\0';

    int wrong_guesses = 0;
    const int max_wrong_guesses = 5;
    char guessed_letters[27] = ""; 
    int guessed_count = 0;

    printf("Welcome to Hangman!\n");


    while (wrong_guesses < max_wrong_guesses) {
        

        if (strcmp(player_progress, secret_word) == 0) {
            break;
        }

    
        printf("\n--------------------\n");
        printf("Word: %s\n", player_progress);
        printf("Lives left: %d\n", max_wrong_guesses - wrong_guesses);
        printf("Guessed letters: %s\n", guessed_letters);
        char guess;
        printf("Enter your guess (a single letter): ");
       
        scanf(" %c", &guess); 
        guess = tolower(guess);

      
        if (strchr(guessed_letters, guess)) {
            printf("You already guessed '%c'. Try again.\n", guess);
            continue;
        }

     
        guessed_letters[guessed_count++] = guess;
        guessed_letters[guessed_count] = '\0'; 

      
        int correct_guess = 0;
        for (int i = 0; i < word_len; i++) {
            if (secret_word[i] == guess) {
                player_progress[i] = guess; 
                correct_guess = 1;
            }
        }

       
        if (correct_guess) {
            printf("Good guess!\n");
        } else {
            printf("Wrong guess!\n");
            wrong_guesses++;
        }

    } 

    if (strcmp(player_progress, secret_word) == 0) {
        printf("You won!\n");
        printf("The word was: %s\n", secret_word);
    } else {
        printf("You ran out of lives.\n");
        printf("The word was: %s\n", secret_word);
    }

    return 0;
}
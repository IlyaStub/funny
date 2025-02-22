#include "ui_service.h"
#include <stdio.h>
#include <string.h>

void print_rules() {
    printf("Player chooses the difficulty level (easy/medium/hard).\n");
    printf("Then a random word is selected from a list.\n");
    printf("The player guesses the word one letter at a time.\n");
    printf("The player wins if he manages to guess the word. The player loses if he has no more tries remaining to do so.\n");
}

void print_progress_bar(int tries_left) {
    printf("[");
    for (int i = 0; i < tries_left; i++) {
        printf("=");
    }
    for (int i = 0; i < (6 - tries_left); i++) {
        printf(" ");
    }
    printf("] ");
    printf("Tries: %d/6\n", tries_left);
}

void print_game_state(game_t *game) {
    switch (game->hangman_state) {
        case 1:
            printf("+------------+\n");
            printf("|            |\n");
            printf("|            |\n");
            printf("|            |\n");
            printf("|            |\n");
            printf("|     0      |\n");
            printf("|    /|\\     |\n");
            printf("|    / \\     |\n");
            printf("+------------+\n");
            break;
        case 2:
            printf("+------------+\n");
            printf("|            |\n");
            printf("|            |\n");
            printf("|            |\n");
            printf("|            |\n");
            printf("|     0      |\n");
            printf("| |  /|\\     |\n");
            printf("|/|\\ / \\     |\n");
            printf("+------------+\n");
            break;
        case 3:
            printf("+------------+\n");
            printf("|            |\n");
            printf("| |          |\n");
            printf("| |          |\n");
            printf("| |          |\n");
            printf("| |   0      |\n");
            printf("| |  /|\\     |\n");
            printf("|/|\\ / \\     |\n");
            printf("+------------+\n");
            break;
        case 4:
            printf("+------------+\n");
            printf("| ________   |\n");
            printf("| |          |\n");
            printf("| |          |\n");
            printf("| |          |\n");
            printf("| |   0      |\n");
            printf("| |  /|\\     |\n");
            printf("|/|\\ / \\     |\n");
            printf("+------------+\n");
            break;
        case 5:
            printf("+------------+\n");
            printf("| ________   |\n");
            printf("| |       |  |\n");
            printf("| |          |\n");
            printf("| |          |\n");
            printf("| |   0      |\n");
            printf("| |  /|\\     |\n");
            printf("|/|\\ / \\     |\n");
            printf("+------------+\n");
            break;
        case 6:
            printf("+------------+\n");
            printf("| ________   |\n");
            printf("| |       |  |\n");
            printf("| |       0  |\n");
            printf("| |      /|\\ |\n");
            printf("| |      / \\ |\n");
            printf("| |          |\n");
            printf("|/|\\         |\n");
            printf("+------------+\n");
            break;
        default:
            break;
    }

    printf("Category: %s\n", game->category);
    printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z\n");
    printf("The remaining letters: ");
    for (int i = 0; i < strlen(game->chosen_alphas); i++)
    {
        printf("%c ", game->chosen_alphas[i]);
    }
    printf("\n");
    printf("Guessed word: %s\n", game->guessed_word);
}
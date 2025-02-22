#pragma once

#include "global.h"

void print_rules(){
    printf("Игрок может выбрать категорию и сложность (easy/medium/hard)","\n");
    printf("Потом по категории случайно выбирается слово из списка","\n");
    printf("Игрок угадывает слово по одной букве","\n");
    printf("Игра заканчивается победой игрока, если он угадал слово, или проигрышем, если он истратил все попытки","\n");
};

void print_progress_bar(int tries_left){
    printf("[");
    for(int i = 0; i < tries_left; i++){
        printf("=");
    }
    printf("] ");
    printf("%c%d", "Tries:", tries_left);
};

void print_game_state(game_t *game){
    if(game->hangman_state == 1){
        printf("+------------+","\n");
        printf("|            |","\n");
        printf("|            |","\n");
        printf("|            |","\n");
        printf("|            |","\n");
        printf("|     0      |","\n");
        printf("|    /|\     |","\n");
        printf("|    / \     |","\n");
        printf("+------------+","\n");
    }
    if(game->hangman_state == 2){
        printf("+------------+","\n");
        printf("|            |","\n");
        printf("|            |","\n");
        printf("|            |","\n");
        printf("|            |","\n");
        printf("|     0      |","\n");
        printf("| |  /|\     |","\n");
        printf("|/|\ / \     |","\n");
        printf("+------------+","\n");
    }
    if(game->hangman_state == 3){
        printf("+------------+","\n");
        printf("|            |","\n");
        printf("| |          |","\n");
        printf("| |          |","\n");
        printf("| |          |","\n");
        printf("| |   0      |","\n");
        printf("| |  /|\     |","\n");
        printf("|/|\ / \     |","\n");
        printf("+------------+","\n");
    }
    if(game->hangman_state == 4){
        printf("+------------+","\n");
        printf("| ________   |","\n");
        printf("| |          |","\n");
        printf("| |          |","\n");
        printf("| |          |","\n");
        printf("| |   0      |","\n");
        printf("| |  /|\     |","\n");
        printf("|/|\ / \     |","\n");
        printf("+------------+","\n");
    }
    if(game->hangman_state == 5){
        printf("+------------+","\n");
        printf("| ________   |","\n");
        printf("| |       |  |","\n");
        printf("| |          |","\n");
        printf("| |          |","\n");
        printf("| |   0      |","\n");
        printf("| |  /|\     |","\n");
        printf("|/|\ / \     |","\n");
        printf("+------------+","\n");
    }
    if(game->hangman_state == 6){
        printf("+------------+","\n");
        printf("| ________   |","\n");
        printf("| |       |  |","\n");
        printf("| |       0  |","\n");
        printf("| |      /|\ |","\n");
        printf("| |      / \ |","\n");
        printf("| |          |","\n");
        printf("|/|\         |","\n");
        printf("+------------+","\n");
    }
    
};

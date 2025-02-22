#pragma once

#include "ui_service.h"
#include "word_service.h"
#include "game.h"
#include "global.h"

int get_random(int max)
{
    return rand() % max;
}

int select_category(categories_t *categories);

int select_level()
{
    int level = 0;
    printf("Выбери уровень сложности (1 - легко, 2 - средне, 3 - сложно):\n");
    while (level != 1 || level != 2 || level != 3)
    {
        printf("Число от 1 до 3:");
        scanf("%d", &level);
    }
    return level;
}

void initialize_game(game_t *game, categories_t *categories);

void check_guess(game_t *game, char guess)
{
    int correctFlag = 0;

    for (int i = 0; i < strlen(game->word); i++)
    {
        if (guess == game->word[i])
        {
            game->guessed_word[i] = guess;
            correctFlag = 1;
        }
    }

    if (!correctFlag)
    {
        game->tries_left--;
        game->hangman_state++;
    }

    game->chosen_alphas[guess - 'A'] = '-';
    return 0;
}

int is_game_won(game_t *game);

void play_game(game_t *game)
{
    while (game->tries_left != 0 && !is_game_won(game))
    {
        char guess;
        scanf("Введи букву: %c", &guess);
        int correctFlag = 0;
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            if (guess == game->chosen_alphas)
            {
                correctFlag = 1;
            }
        }
        if (!correctFlag)
        {
            printf("Нет такой буквы\n");
            continue;
        }
        else
        {
            check_guess(game, guess);
            if (game->tries_left == 0)
            {
                printf("Вы проиграли\n");
            }
            else
            {
                if (is_game_won)
                {
                    printf("Вы выиграли");
                }
                else
                {
                    print_progress_bar(game->tries_left);
                    print_game_state(game);
                }
            }
        }
    }
}

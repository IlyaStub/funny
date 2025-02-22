#pragma once

#include "ui_service.h"
#include "word_service.h"
#include "game.h"
#include "global.h"

int get_random(int max)
{
    return rand() % max;
}

int select_category(categories_t *categories)
{
    int category;
    printf("%s\n", "Выберите категорию: (введите число)");
    for (int i = 1; i < categories->categories_cnt + 1; i++)
    {
        printf("%d. %s\n", i, categories->category_words[i]);
    }
    scanf("%d\n", &category);
    return category;
}

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

void initialize_game(game_t *game, categories_t *categories)
{
    int level = select_level();
    game->level = level;

    game->hangman_state = 0;

    game->tries_left = MAX_TRIES;

    int category = select_category(categories);
    strcpy(game->category, categories->category_words[category].category);

    int word_index = get_random(categories->category_words[category].words_lvls[level].words_cnt);
    char word[MAX_WORD_LEN] = categories->category_words[category].words_lvls[level].words[word_index];
    strcpy(game->word, word);

    char *guessed_word = (char *)malloc((strlen(game->word)) * sizeof(char));
    memset(guessed_word, '_', (strlen(game->word)));

    char chosen_alphas[ALPHABET_SIZE] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
}

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

int is_game_won(game_t *game)
{
    for (int i = 0; i < (strlen(game->word)); i++)
    {
        if (game->word[i] == '_')
        {
            return 0;
        }
    }
    return 1;
}

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

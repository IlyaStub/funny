#pragma once

#include "ui_service.h"
#include "word_service.h"
#include "global.h"

int get_random(int max);

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

int select_level();

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

void check_guess(game_t *game, char guess);

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
}
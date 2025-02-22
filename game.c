#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "ui_service.h"
#include "word_service.h"
#include "game.h"
#include "global.h"

int get_random(int max)
{
    return 0 + rand() % max;
}

int select_category(categories_t *categories)
{
    int category;
    printf("Choose a category: (enter a number)\n");
    for (int i = 0; i < categories->categories_cnt; i++)
    {
        printf("%d. %s\n", i + 1, categories->category_words[i]);
    }
    scanf(" %d", &category);
    return category - 1;
}

int select_level()
{
    int level = 0;
    printf("Choose the difficulty level (1 - easy, 2 - medium, 3 - hard):\n");
    while (level < 1 || level > 3)
    {
        printf("Enter a number from 1 to 3: ");
        scanf(" %d", &level);
    }
    return level - 1;
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
    strcpy(game->word, categories->category_words[category].words_lvls[level].words[word_index]);


    memset(game->guessed_word, '_', strlen(game->word));
    game->guessed_word[strlen(game->word)] = '\0';
    for (int i = 0; i < strlen(game->word); i++) {
        game->word[i] = toupper(game->word[i]);  
    }

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        game->chosen_alphas[i] = 'A' + i;
    }
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
}

int is_game_won(game_t *game)
{
    for (int i = 0; i < (strlen(game->word)); i++)
    {
        if (game->guessed_word[i] == '_')
        {
            return 0;
        }
    }
    return 1;
}

void play_game(game_t *game)
{
    while (game->tries_left > 0)
    {
        print_progress_bar(game->tries_left);
        print_game_state(game);
        char guess;
        printf("Enter a letter: ");
        scanf(" %c", &guess);
        guess = toupper(guess);
        int correctFlag = 0;
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            if (guess == game->chosen_alphas[i])
            {
                correctFlag = 1;
                break;
            }
        }
        if (!correctFlag)
        {
            printf("======No such letter====\n");
            continue;
        }
        else
        {
            check_guess(game, guess);
            if (game->tries_left == 0)
            {
                print_game_state(game);
                printf("You lost\n");
                printf("The word was %s\n", game->word);
                break;
            }
            else
            {
                if (is_game_won(game))
                {
                    printf("You won\n");
                    printf("The word was %s\n", game->word);
                    break;
                }
            }
        }
    }
}
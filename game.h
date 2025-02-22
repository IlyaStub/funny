#pragma once

#include "ui_service.h"
#include "word_service.h"

int get_random(int max);

int select_category(categories_t *categories);

int select_level();

void initialize_game(game_t *game, categories_t *categories);

void check_guess(game_t *game, char guess);

int is_game_won(game_t *game);

void play_game(game_t *game);
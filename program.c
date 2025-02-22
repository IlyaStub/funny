#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "game.h"

int main() {
    //srand(time(NULL));
    categories_t categories = load_categories("words");

    for (int i = 0; i < categories.categories_cnt; i++) {
        category_words_t cat = categories.category_words[i];
        printf("cat: %s\n", cat.category);
        for (int j = 0; j < MAX_LVL; j++) {
            printf("  lvl: %d\n", j);
            words_level_t words_level = cat.words_lvls[j];
            for (int m = 0; m < words_level.words_cnt; m++) {
                printf("   word: %s\n", words_level.words[m]);
            }
        }
    }
    
    //game_t game;
    //print_rules();
    //initialize_game(&game, &categories);
    //play_game(&game);
    return 0;
}
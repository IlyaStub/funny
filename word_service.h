#pragma once

#include "global.h"

#include <string.h>

categories_t load_categories(const char *filename) {
    FILE* input = fopen(filename, "r");

    categories_t cats;
    fscanf(input, "%d", &cats.categories_cnt);

    for (int i = 0; i < cats.categories_cnt; i++) {
        category_words_t cat;
        
        char cat_name[MAX_WORD_LEN];
        fscanf(input, "%s", cat_name);
        strcpy(cat.category, cat_name);
        
        // get words
        for (int j = 0; j < MAX_LVL; j++) {
            words_level_t words_level;

            int level;
            fscanf(input, "%d %d", &level, &words_level.words_cnt);

            for (int m = 0; m < words_level.words_cnt; m++) {
                fscanf(input, "%s", words_level.words[m]);
            }

            cat.words_lvls[level] = words_level;
        }

        cats.category_words[i] = cat;
    }

    fclose(input);

    return cats;
}
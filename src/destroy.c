/*
** EPITECH PROJECT, 2022
** detroy
** File description:
** detroy
*/

#include "../include/my.h"

int destroy_all(sfTexture *back_t, sfSprite *back_s, sfTexture *button_t,
    sfSprite *button_s)
{
    sfSprite_destroy(button_s);
    sfSprite_destroy(back_s);
    sfTexture_destroy(button_t);
    sfTexture_destroy(back_t);
}

int re_destroy_all(sfTexture *game_t, sfSprite *game_s, sfTexture *sprite_t,
                    sfSprite *sprite_s)
{
    sfSprite_destroy(game_s);
    sfSprite_destroy(sprite_s);
    sfTexture_destroy(game_t);
    sfTexture_destroy(sprite_t);
}

/*
** EPITECH PROJECT, 2022
** game function
** File description:
** game_view
*/

#include "../include/my.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void creat_rect(sfIntRect *rect)
{
    rect->top = 0;
    rect->height = 110;
    rect->left = 0;
    rect->width = 110;
}

void move_rect(sfIntRect *rect)
{
    if ((rect->left) < 220) {
        rect->left += 110;
    } else {
        rect->left = 0;
    }
}

void game_2(sfRenderWindow *window, sfEvent event, sfSprite *game_s,
            sfSprite *sprite_s)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
    }
    sfRenderWindow_drawSprite(window, game_s, NULL);
    sfRenderWindow_drawSprite(window, sprite_s, NULL);
    sfRenderWindow_display(window);
}

void display_sprite(sfSprite **sprite_s, sfIntRect *rect,
                        sfVector2f sprite_speed, sfClock *clock)
{
    if ((sfClock_getElapsedTime(clock).microseconds / 1000000.0) > 0.1) {
        sfClock_restart(clock);
        move_rect(rect);
    }
    if (sfSprite_getPosition(*sprite_s).x + 110 > 1920) {
        sfSprite_setPosition((*sprite_s),(sfVector2f)
        {0, sfSprite_getPosition((*sprite_s)).y});
    }
    sfSprite_move(*sprite_s, sprite_speed);
    sfSprite_setTextureRect(*sprite_s, *rect);
}

void game_function(sfRenderWindow *window, sfEvent event)
{
    int x_sprite = 0;
    sfTexture *game_t = sfTexture_createFromFile("./content/fond1.png", NULL);
    sfSprite *game_s = sfSprite_create(); sfVector2f game_scale = {1.25, 1.25};
    sfSprite_setTexture(game_s, game_t, sfTrue);
    sfSprite_setScale(game_s, game_scale);
    sfTexture *sprite_t = sfTexture_createFromFile("./content/sprit.png", NULL);
    sfIntRect rect; sfSprite *sprite_s = sfSprite_create();
    sfVector2f sprite_pos = {x_sprite, 1};
    sfVector2f sprite_speed = {4, 0};
    sfSprite_setTexture(sprite_s, sprite_t, sfTrue);
    sfSprite_setTextureRect(sprite_s, rect);
    sfSprite_setPosition(sprite_s, sprite_pos); creat_rect(&rect);
    sfClock *clock = sfClock_create();
    while (sfRenderWindow_isOpen(window)) {
        display_sprite(&sprite_s, &rect, sprite_speed, clock);
        game_2(window, event, game_s, sprite_s);
        kill_duck(window, event, sprite_pos);
    }
    re_destroy_all(game_t, game_s, sprite_t, sprite_s);
    sfClock_destroy(clock);
}

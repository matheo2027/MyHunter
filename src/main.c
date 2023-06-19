/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "../include/my.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


void if_click(sfRenderWindow *window, sfEvent event)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    if (mouse.x >= 874 && mouse.x <= 1028 && mouse.y >= 508 && mouse.y <= 558) {
        if (event.type == sfEvtMouseButtonPressed)
            game_function(window, event);
    }
}

int openwindow_help(sfRenderWindow *window, sfEvent event, sfSprite *back_s,
                        sfSprite *button_s)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
    }
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, back_s, NULL);
    sfRenderWindow_drawSprite(window, button_s, NULL);
    sfRenderWindow_display(window);
    if_click(window, event);
}

int open_window(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window; sfEvent event;
    sfTexture *back_t = sfTexture_createFromFile("./content/fond.png", NULL);
    sfSprite *back_s = sfSprite_create();
    sfTexture *button_t =
    sfTexture_createFromFile("./content/bouton.png", NULL);
    sfSprite *button_s = sfSprite_create(); sfVector2f button_pos = {870, 480};
    sfVector2f back_scale = {1.25, 1.25}; sfVector2f button_scale = {5, 5};
    sfSprite_setTexture(back_s, back_t, sfTrue);
    sfSprite_setScale(back_s, back_scale);
    sfSprite_setTexture(button_s, button_t, sfTrue);
    sfSprite_setScale(button_s, button_scale);
    sfSprite_setPosition(button_s, button_pos);
    window = sfRenderWindow_create(mode, "my_hunter", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window))
        openwindow_help(window, event, back_s, button_s);
    destroy_all(back_t, back_s, button_t, button_s);
    sfRenderWindow_destroy(window);
    return (0);
}

int check_argv(int argc, char **argv)
{
    if (argc == 2) {
        if (((argv[1][1] == 'h')) && ((argv[1][0] == '-')) &&
            ((argv[1][2] == '\0'))) {
            flag();
            return (0);
            } else {
                mini_printf("Make ./my_hunter -h for the rules!\n");
                return (84);
            }
    } else
        open_window();
}

int main (int argc, char **argv)
{
    check_argv(argc, argv);
    return (0);
}

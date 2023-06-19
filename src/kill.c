/*
** EPITECH PROJECT, 2022
** kill
** File description:
** kill
*/

#include "../include/my.h"

void kill_duck(sfRenderWindow *window, sfEvent event, sfVector2f sprite_pos)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
        if (event.type == sfEvtMouseButtonPressed && mouse.x >= sprite_pos.x &&
            mouse.x <= sprite_pos.x + 110 && mouse.y >= sprite_pos.y &&
            mouse.y <= sprite_pos.y + 110) {
                mini_printf("Touché!");
        }
    }
}

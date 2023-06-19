/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/System/Clock.h>
    #include <SFML/System/Time.h>

    #define sfCf sfTexture_createFromFile
    #define sfWc sfRenderWindow_create

    int my_strlen(char const *str);
    void game_function(sfRenderWindow *window, sfEvent event);
    int mini_printf(const char *format, ...);
    int flag(void);
    int destroy_all(sfTexture *back_t, sfSprite *back_s, sfTexture *button_t,
        sfSprite *button_s);
    int re_destroy_all(sfTexture *game_t, sfSprite *game_s, sfTexture *sprite_t,
    sfSprite *sprite_s);
    void kill_duck(sfRenderWindow *window, sfEvent event,
        sfVector2f sprite_pos);

#endif

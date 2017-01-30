#include "std.h"
inherit "room/room";
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset()
{
    object dog, weapon;
    int n,i,class,value,weight;
    string w_name,alt_name;

    i = 0;
    if (!present("dog")) {
        while(i<7) {
            i += 1;
            dog = clone_object("obj/monster.c");
            call_other(dog, "set_name", "dog");
            call_other(dog, "set_alias", "hound");
            call_other(dog, "set_race", "dog");
            call_other(dog, "set_level", random(4) + 1);
            call_other(dog, "set_hp", 50);
            call_other(dog, "set_ep", 1014);
            call_other(dog, "set_al", -60);
            call_other(dog, "set_short", "A hell hound");
/* Changed this from 0 to 2 so they'll have some worth with the new xp system. -Feldegast 9-24-00 */
            call_other(dog, "set_ac", 2);
            call_other(dog, "set_aggressive", 1);
            call_other(dog, "set_a_chat_chance", 50);
            call_other(dog, "load_a_chat", "Dog says: I'll rip your head off!\n");
            call_other(dog, "load_a_chat", "Dog says: Damn religious bastards!\n");
            call_other(dog, "load_a_chat", "Dog says: Kill him!!\n");
            call_other(dog, "load_a_chat", "Dog says: MMmMmmMmm.. dog food!!\n");
            call_other(dog, "load_a_chat", 
                "Dog says: Let's rip out his guts!\n");
            call_other(dog, "load_a_chat", 
               "Dog says: Kill him before he runs away!\n");
            call_other(dog, "load_a_chat", 
               "Dog says: You're not gonna make it outta here!\n");
            n = random(3);
            weapon = clone_object("obj/weapon");
            if (n == 0) {
                w_name = "studded collar";
                class = 5;
                value = 8;
                weight = 1;
                alt_name = "collar";
            }
            if (n == 1) {
                w_name = "razor collar";
                class = 9;
                value = 150;
                weight = 2;
                alt_name = "collar";
            }
            if (n == 2) {
                w_name = "fire collar";
                class = 11;
                value = 300;
                weight = 1;
                alt_name = "collar";
            }
            call_other(weapon, "set_name", w_name);
            call_other(weapon, "set_class", class);
            call_other(weapon, "set_value", value);
            call_other(weapon, "set_weight", weight);
            call_other(weapon, "set_alt_name", alt_name);
            transfer(weapon, dog);
            call_other(dog, "init_command", "wield "+w_name);
            move_object(dog, this_object());
        }
    }
}
TWO_EXIT ("players/paulasx/temple/temple3", "north",
          "players/paulasx/temple/temple_warning", "south",
          "Gathering area within the Temple of Bishamon",
          "This is the opening to the gathering area within the Temple of Bishamon.\n" +
          "The room is completely empty except an altar to the north.\n",1)

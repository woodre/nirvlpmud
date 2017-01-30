
#include "std.h"


#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset()
{
object blue, shears;
int i;
i = 0;
if (!blue || !living(blue)) {
    while (i < random(5)) {
     i += 1;
    blue = clone_object("obj/monster.talk");
     call_other(blue, "set_name", "blue");
    call_other(blue, "set_level", 8);
    call_other(blue, "set_ep", 13600);
     call_other(blue, "set_al", 0);
     call_other(blue, "set_alias", "meanie");
     call_other(blue, "set_short", "A Blue Meanie");
    call_other(blue, "set_long", "A real nasty Blue Meanie armed\n"
              +"with a vicious looking pair of garden shears !\n"
              +"He hates you ! He hates everything that is good !\n");
    call_other(blue, "set_al", -20);
    call_other(blue, "set_aggressive", 1);
    call_other(blue, "set_ac", 8);
    call_other(blue, "set_a_chat_chance", 60);
    call_other(blue, "load_a_chat", "DIE DIE DIE DIE !!\n");
    call_other(blue, "load_a_chat", "I spit on your grave !!\n");
    shears = clone_object("obj/weapon");
    call_other(shears, "set_name", "shears");
    call_other(shears, "set_class", 16);
    call_other(shears, "set_weight", 5);
    call_other(shears, "set_value", 2000);
    call_other(shears, "set_short", "A pair of garden shears");
    call_other(shears, "set_long", "A pair of ordinary garden shears\n");
    move_object(shears, blue);
    call_other(blue, "init_command", "wield shears");
    move_object(blue, this_object());
    }
  }
}
  
TWO_EXIT("players/morgoth/CASTLE/field3", "north",
    "players/morgoth/CASTLE/field8", "west",
    "Strawberry Fields...",
    "Strawberry Fields - The place where nothing is real\n",1)
  
  

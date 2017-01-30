
#include "std.h"

object bat, money;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset()
{
int i;
i = 0;
if (!bat || !living(bat)) {
  while (i < 10)  {
    i += 1;
    money = clone_object("obj/money");
    money->set_money(random(50));
    bat = clone_object("obj/monster");
    call_other(bat, "set_name", "bat");
    call_other(bat, "set_level", 10);
    call_other(bat, "set_al", -50);
    call_other(bat, "set_short", "A nasty little bat");
    call_other(bat, "set_long", "An evil denizen of Strawberry Fields\n"
             +"The bat's claws and teeth are quite sharp.\n");
    call_other(bat, "set_wc", 10);
    call_other(bat, "set_ac", 8);
    call_other(bat, "set_chat_chance", 10);
    call_other(bat, "load_chat", "EEP EEP !\n");
    move_object(money, bat);
    move_object(bat, this_object());
   }
  }
 }

THREE_EXIT("players/morgoth/CASTLE/field5", "east",
    "players/morgoth/CASTLE/field10", "south",
    "players/morgoth/CASTLE/field13", "west",
    "Strawberry Fields forever....",
    "This is another nesting ground for the bats that\n"
   +"inhabit Strawberry Fields\n",1)


#include "std.h"
#include "living.h"
object pluto;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

THREE_EXIT("players/mistress/child/disney/hill","east",
           "players/mistress/child/disney/room4","west",
           "players/mistress/child/disney/bag","north",
    "Pluto",
    "\nDoggy bones are scattered about....  Why didn't the dog just bury\n" +
    "them?  Oh well.  You notice a large doggy dish with the name:\n" +
    "\n                PLUTO\n .\n",1)

extra_reset() {
  if(!pluto || !living(pluto)) {
   pluto = clone_object("obj/monster");
   call_other(pluto, "set_name", "Pluto");
   call_other(pluto, "set_short", "Pluto");
   call_other(pluto, "set_long", "A friendly yet strange looking dog.\n");
   call_other(pluto, "set_level", 4);
   call_other(pluto, "set_wc", 8);
   call_other(pluto, "set_ac", 4);
   call_other(pluto, "set_hp", 400);
   call_other(pluto, "set_race", "dog");
   call_other(pluto, "set_al", 1000);
   call_other(pluto, "set_chat_chance", 8);
   call_other(pluto, "load_chat", "Pluto tries to lick your face off!\n");
   call_other(pluto, "add_money", 20);
   call_other(pluto, "set_alias", "pluto");
  move_object(pluto, this_object()); }
  }

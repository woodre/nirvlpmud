#include "std.h"
#include "living.h"
object yoda;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
THREE_EXIT("players/mistress/sci_fi/star_wars/hans.c","north",
          "players/mistress/sci_fi/star_wars/chewy.c","south",
          "players/mistress/sci_fi/star_wars/obi_wan.c","west",
    "Yoda",
    "\n" +
    "This is a very small yet strangely comfortable tunnel... the ceiling\n" +
    "is a little low for you,  but the warmth is welcoming.\n",0)
 
extra_reset()
{
if (!yoda || !living(yoda) )
{
 
   object armor;
yoda = clone_object("obj/monster");
call_other(yoda, "set_ac", 8);
call_other(yoda, "set_name", "Yoda,  The Jedi Master");
call_other(yoda, "set_wc", 14);
call_other(yoda, "set_al", 879);
call_other(yoda, "set_short", "Yoda");
call_other(yoda, "set_alias", "yoda");
call_other(yoda, "set_race", "jedi");
call_other(yoda, "set_long", "The Jedi Master.\n");
call_other(yoda, "set_alt_name", "master");
call_other(yoda, "set_aggressive", 0);
call_other(yoda, "set_level", 10);
 
move_object(yoda, this_object() );
armor = clone_object("obj/armor");
call_other(armor, "set_name", "A Beautiful Cloak");
call_other(armor, "set_alias", "cloak");
call_other(armor, "set_short", "A Jedi Cloak");
call_other(armor, "set_long", "A Jedi Master`s Cloak");
call_other(armor, "set_type", "armor");
call_other(armor, "set_value", 300);
call_other(armor, "set_weight", 3);
call_other(armor, "set_read", "This once belonged to Yoda,  the Jedi Master");
call_other(armor, "set_ac", 2);
transfer(armor,yoda);
}
}

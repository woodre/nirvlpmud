#include "std.h"
#include "living.h"
object serena;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
TWO_EXIT("players/mistress/sci_fi/galactica/boxey.c","east",
          "players/mistress/sci_fi/galactica/apollo.c","west",
    "Serena",
    "\n" +
    "You find yourself in a small and well-lived in room... this appears to\n" +
    "be part of a set of living quarters.\n",1)
 
extra_reset()
{
if (!serena || !living(serena) )
{
 
   object armor;
serena = clone_object("obj/monster");
call_other(serena, "set_name", "Serena");
call_other(serena, "set_ac", 9);
call_other(serena, "set_wc", 16);
call_other(serena, "set_al", 400);
call_other(serena, "set_short", "Serena");
call_other(serena, "set_long", "A stunning woman with long-flowing hair.\n");
call_other(serena, "set_alias", "serena");
call_other(serena, "set_aggressive", 0);
call_other(serena, "add_money", 111);
call_other(serena, "set_level", 12);
 
move_object(serena, this_object() );
armor = clone_object("obj/armor");
call_other(armor, "set_name", "Veil");
call_other(armor, "set_alias", "veil");
call_other(armor, "set_short", "Wedding veil");
call_other(armor, "set_long", "This appears to be the wedding veil Serena wore when she married Apollo\n");
call_other(armor, "set_type", "helmet");
call_other(armor, "set_value", 75);
call_other(armor, "set_weight", 1);
call_other(armor, "set_ac", 1);
transfer(armor,serena);
}
}

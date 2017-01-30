#include "std.h"
#include "living.h"
object baltar;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
ONE_EXIT("players/mistress/sci_fi/galactica/leader.c","east",
    "Baltar",
    "\n" +
    "This room is too dark for comfort.  You can barely make out the\n" +
    "image of a large pedastal.\n",0)
 
extra_reset()
{
if (!baltar || !living(baltar) )
{
 
   object armor;
baltar = clone_object("obj/monster");
call_other(baltar, "set_name", "Baltar");
call_other(baltar, "set_ac", 8);
call_other(baltar, "set_wc", 14);
call_other(baltar, "set_al", -567);
call_other(baltar, "set_short", "Baltar");
call_other(baltar, "set_long", "Traitor to the human race.\n");
call_other(baltar, "set_alias", "baltar");
call_other(baltar, "set_race", "traitor");
call_other(baltar, "set_aggressive", 0);
call_other(baltar, "set_whimpy",1);
call_other(baltar, "set_level", 10);
 
move_object(baltar, this_object() );
armor = clone_object("obj/armor");
call_other(armor, "set_name", "Ring of Death");
call_other(armor, "set_alias", "ring");
call_other(armor, "set_short", "Ring of Death");
call_other(armor, "set_long", "This ring was given to Baltar by the Cylon Imperial Leader.\n");
call_other(armor, "set_type", "ring");
call_other(armor, "set_value", 400);
call_other(armor, "set_weight", 2);
call_other(armor, "set_ac", 2);
transfer(armor,baltar);
}
}

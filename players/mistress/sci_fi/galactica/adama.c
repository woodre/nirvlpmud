#include "std.h"
#include "living.h"
object adama;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
TWO_EXIT("players/mistress/sci_fi/galactica/entrance.c","east",
          "players/mistress/sci_fi/galactica/tighe.c","south",
    "Commander Adama",
    "\nAs you step  onto the lower bridge,  you find yourself face to face with a\n" +
    "spectacular view of the stars...  A dream...  A future...\n",1)
 
extra_reset()
{
if (!adama || !living(adama) )
{
 
   object armor;
adama = clone_object("obj/monster");
call_other(adama, "set_name", "Cdr. Adama");
call_other(adama, "set_ac", 9);
call_other(adama, "set_wc", 16);
call_other(adama, "set_al", 500);
call_other(adama, "set_short", "Cdr. Adama");
call_other(adama, "set_long", "Commander of the Battlestar Galactica.\n");
call_other(adama, "set_alias", "adama");
call_other(adama, "set_race", "cdr");
call_other(adama, "set_alt_name", "commander");
call_other(adama, "set_aggressive", 0);
call_other(adama, "add_money", 300);
call_other(adama, "set_level", 13);
 
move_object(adama, this_object() );
armor = clone_object("obj/armor");
call_other(armor, "set_name", "Medallion");
call_other(armor, "set_alias", "medallion");
call_other(armor, "set_short", "Medallion");
call_other(armor, "set_alt_name", "medallion");
call_other(armor, "set_long", "Medallion of the High Council\n");
call_other(armor, "set_type", "amulet");
call_other(armor, "set_value", 400);
call_other(armor, "set_weight", 3);
call_other(armor, "set_read", "Engraved is a symbol unrecognizable to you... You can read High Council.\n");
call_other(armor, "set_ac", 2);
transfer(armor,adama);
}
}


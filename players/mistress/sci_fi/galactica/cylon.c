#include "std.h"
#include "living.h"
object cylon;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
ONE_EXIT("players/mistress/sci_fi/galactica/space2.c","east",
    "Cylon warrior",
    "A strange feeling comes over you and you slowly lose conciousness.\n" +
    " \n" +
    " \n" +
    " \n" +
    " \n" +
    " \n" +
    " \n" +
    " \n" +
    " \n" +
    " \n" +
    " \n" +
    "\n" +
    " \n" +
    " \n" +
    " \n" +
    " \n" +
    " \n" +
    "You open your eyes and find yourself in a strange room... An eerie\n" +
    "hum surrounds you and you are hypnotized by a flashing red light....\n",0)
 
extra_reset()
{
if (!cylon || !living(cylon) )
{
 
   object armor;
cylon = clone_object("obj/monster");
call_other(cylon, "set_name", "Cylon");
call_other(cylon, "set_ac", 7);
call_other(cylon, "set_wc", 13);
call_other(cylon, "set_al", -430);
call_other(cylon, "set_short", "Cylon");
call_other(cylon, "set_long", "A cylon warrior\n");
call_other(cylon, "set_alias", "cylon");
call_other(cylon, "set_race", "warrior");
call_other(cylon, "set_aggressive", 0);
call_other(cylon, "set_level", 9);
 
move_object(cylon, this_object() );
armor = clone_object("obj/armor");
call_other(armor, "set_name", "Metal gloves");
call_other(armor, "set_alias", "gloves");
call_other(armor, "set_short", "Metal gloves");
call_other(armor, "set_long", "Bright, shiny gloves made of a strange metal.\n");
call_other(armor, "set_type", "misc");
call_other(armor, "set_value", 100);
call_other(armor, "set_weight", 1);
call_other(armor, "set_ac", 1);
transfer(armor,cylon);
}
}

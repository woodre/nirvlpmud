#include "std.h"
#include "living.h"
object suess;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

ONE_EXIT("players/mistress/child/play.c","south",
    "Dr. Suess",
    "\n" +
    "Jumbles of words upon words and rhymes upon rhymes suffocate the air..\n" +
    "Words that aren`t words and rhymes that rhyme with nothing... \n" +
    "AHHHHHHHHHHHHHHH!!!!!!!!!!!!! Can drive you nuts!.\n",1)

extra_reset()
{
if (!suess || !living(suess) )
{

   object weapon;
suess = clone_object("obj/monster");
call_other(suess, "set_name", "Dr. Suess");
call_other(suess, "set_ac", 8);
call_other(suess, "set_wc", 13);
call_other(suess, "set_al", -1000);
call_other(suess, "set_short", "Dr. Suess");
call_other(suess, "set_alias", "suess");
call_other(suess, "set_long", "Dr. Suess seems to be muttering nonsence to himself.\n");
call_other(suess, "set_race", "dr");
call_other(suess, "set_alt_name", "suess");
call_other(suess, "set_aggressive", 0);
call_other(suess, "add_money", 400);
call_other(suess, "set_level", 10);

move_object(suess, this_object() );
weapon = clone_object("obj/weapon");
call_other(weapon, "set_name", "THE CAT IN THE HAT book");
call_other(weapon, "set_alias", "book");
call_other(weapon, "set_short", "The Cat in The Hat book ");
call_other(weapon, "set_long", "The book is The Cat In The Hat written by none other... .\n");
call_other(weapon, "set_class", 10);
call_other(weapon, "set_value", 40);
call_other(weapon, "set_weight", 1);
call_other(weapon, "set_read", "THE CAT IN THE HAT by Dr. Suess");
transfer(weapon,suess);
call_other(suess, "init_command", "wield book");
}
}

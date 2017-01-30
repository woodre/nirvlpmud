#include "std.h"
#include "living.h"
object bambi;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

ONE_EXIT("players/mistress/child/bambi/thumper.c","east",
    "Bambi",
    "\n" +
    "You find yourself standing in a small forest glade.  The sun filters\n" +
    "down in a gentle wave.\n",1)

extra_reset()
{
if (!bambi || !living(bambi) )
{

   object armor;
bambi = clone_object("obj/monster");
call_other(bambi, "set_name", "Bambi");
call_other(bambi, "set_ac", 4);
call_other(bambi, "set_wc", 8);
call_other(bambi, "set_al", 687);
call_other(bambi, "set_short", "Bambi");
call_other(bambi, "set_long", "A gentle and cuddley fawn.\n");
call_other(bambi, "set_alias", "bambi");
call_other(bambi, "set_race", "deer");
call_other(bambi, "set_alt_name", "Bambi");
call_other(bambi, "set_aggressive", 0);
call_other(bambi, "add_money", 99);
call_other(bambi, "set_level", 4);

move_object(bambi, this_object() );
armor = clone_object("obj/armor");
call_other(armor, "set_name", "A large Leaf");
call_other(armor, "set_alias", "leaf");
call_other(armor, "set_short", "A large leaf");
call_other(armor, "set_long", "This leaf looks large enough to hide under.\n");
call_other(armor, "set_type", "helmet");
call_other(armor, "set_value", 75);
call_other(armor, "set_weight", 1);
call_other(armor, "set_read", "Worn on the head, it makes for good camoflauge");
call_other(armor, "set_ac", 1);
transfer(armor,bambi);
call_other(bambi, "init_command", "wear leaf");
}
}

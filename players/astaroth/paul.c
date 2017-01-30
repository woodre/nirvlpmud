#include        "std.h"
#undef EXTRA_RESET
#define EXTRA_RESET more_reset();
ONE_EXIT("players/astaroth/bluedream", "north",
           "Paul McCartney",
           "Yes, this is Paul McCartney's room.\n" +
           "If you don't know who he is, you need to get out more.\n",
           1)
 
 
object monster, weapon, armor, money;
 
more_reset(){
if (!monster || !living(monster)) {
monster = clone_object ("obj/monster");
call_other (monster, "set_name", "paul");
call_other (monster, "set_alias", "mccartney");
call_other (monster, "set_level",13);
call_other (monster, "set_hp",200 + random(40));
call_other (monster, "set_al",300);
call_other (monster, "set_race","human");
call_other (monster, "set_short","Paul McCartney");
call_other (monster, "set_long", "Yes, he's the former Beatle.\n");
call_other (monster, "set_ac",9);
call_other (monster, "set_wc",12);
call_other (monster, "set_aggressive",0);
call_other (monster, "set_chance", 20);
call_other (monster, "set_spell_mess2", "A blue meanie appears, bites you, then disappears!");
call_other (monster, "set_spell_mess1","Don't mess with Sgt. Pepper!\n");
call_other (monster, "set_spell_dam", 10);
 
{
  weapon = clone_object("obj/weapon");
call_other (weapon,"set_name", "accent");
call_other (weapon,"set_alias", "british accent");
call_other (weapon,"set_short","British accent.");
call_other(weapon, "set_long", "Bloody Americans never use it right.\n");
call_other (weapon,"set_class",14);
call_other (weapon,"set_weight",5);
call_other (weapon,"set_value", 700);
transfer (weapon, monster);
}
transfer (monster, this_object());
}
}

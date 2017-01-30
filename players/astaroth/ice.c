#include        "std.h"
#undef EXTRA_RESET
#define EXTRA_RESET more_reset();
ONE_EXIT("players/astaroth/ev3", "east",
           "The Ice lair",
           "You find yourself in a lair of Ice-ing.  (quit groaning!)\n" +
           "Yes, it's Vanilla Ice.  Not an original idea, but then neither\n" +
           "are his songs.\n",
           1)
 
 
object monster, weapon, armor, money;
 
more_reset(){
if (!present("ice")) {
monster = clone_object ("obj/monster");
call_other (monster, "set_name", "ice");
call_other (monster, "set_alias", "vanilla ice");
call_other (monster, "set_level",14);
call_other (monster, "set_hp",200 + random(30));
call_other (monster, "set_al",-500);
call_other (monster, "set_race","human");
call_other (monster, "set_short","Vanilla Ice");
call_other (monster, "set_long", "Ice is some rich kid who bought a career because he was bored.\n");
call_other (monster, "set_ac",5);
call_other (monster, "set_wc",10);
call_other (monster, "set_aggressive",0);
call_other (monster, "set_chance", 30);
call_other (monster, "set_spell_mess2", "Yo baby, Yo ba- er.. Go ninja go!");
call_other (monster, "set_spell_mess1","Watch that funky ninja go!\n");
call_other (monster, "set_spell_dam", 15);
 
{
  weapon = clone_object("obj/weapon");
call_other (weapon,"set_name", "hammer");
call_other (weapon,"set_alias", "mchammer");
call_other (weapon,"set_short","MC Hammer");
call_other(weapon, "set_long", "There's a Pepsi emblem on it.\n");
call_other (weapon,"set_class",12);
call_other (weapon,"set_weight",5);
call_other (weapon,"set_value", 500);
transfer (weapon, monster);
transfer (monster, this_object());
}
}
}

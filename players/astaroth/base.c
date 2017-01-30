#include        "std.h"
#undef EXTRA_RESET
#define EXTRA_RESET more_reset();
ONE_EXIT("players/astaroth/ev3", "west",
           "180 feet down the base path",
           "Rappers have stolen their music plenty of times so far\n" +
           "and this group is no exception.\n",
           1)
 
 
object monster, weapon, armor, money;
 
more_reset(){
if (!monster || !living(monster)) {
monster = clone_object ("obj/monster");
call_other (monster, "set_name", "third base");
call_other (monster, "set_alias", "base");
call_other (monster, "set_level",17);
call_other (monster, "set_hp",300 + random(300));
call_other (monster, "set_al",-700);
call_other (monster, "set_race","human");
call_other (monster, "set_short","Third Base");
call_other (monster, "set_long", "Looks like idea theft is a way of life.\n");
call_other (monster, "set_ac",40);
call_other (monster, "set_wc",13);
call_other (monster, "set_aggressive",0);
call_other (monster, "set_chance", 30);
call_other (monster, "set_spell_mess2", "Pop pop goes the weasel!\n");
call_other (monster, "set_spell_mess1","Pop goes the weasel, the weasel!\n");
call_other (monster, "set_spell_dam", 20);
 
{
  weapon = clone_object("obj/treasure");
call_other (weapon,"set_id", "song");
call_other (weapon,"set_alias", "record");
call_other (weapon,"set_short","a song");
call_other(weapon, "set_long", "It has been stolen and butchered.\n");
call_other (weapon,"set_weight",3);
call_other (weapon,"set_value", 750);
transfer (weapon, monster);
transfer (monster, this_object());
}
}
}

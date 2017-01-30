/*  Level 2 Creation Spell: Alarm - Creates an object that will warn
    the creator of someone entering. Works once.  Cost: 5 mp */

#include "/players/chip/venom2/sdefine.h"


main(string str, object gob, object player)
{
	object ob;
	int bonus;
	
	if(USER->query_ghost()) return 0;
	if(CRE < 2) return 0;
	
	if(GOB->query_mp() < 5){
		tell_object(USER,
		"You do not have enough "+HIK+"Dark Matter"+NORM+" for that.\n");
		return 1;
	}
	ob = clone_object("/players/chip/venom2/OBJ/alarm.c");
      ob->set_owner(USER->query_real_name());
      move_object(ob, environment(USER));
	GOB->add_mp(-5);
	tell_object(USER,
	"You place your palm on the ground...\n"+
 "A "+HIK+"Dark Matter"+BOLD+" Sliver"+NORM+" breaks away and implants itself in the ground.\n");
	return 1;
}


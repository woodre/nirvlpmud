#include <ansi.h>
#include "../defs.h"

status main(string str, object PO, object User)
{
	object att, *ob, prevent;
	int h, s;
	
	if(User->query_ghost()){
		return 1;
	}
	
	if(User->query_extra_level() < 3){
		write("You are too low of a level!\n");
		return 1;
	}
	
	if(present("shinshi_stop_vanish", User)){
		write("That ability is still on cooldown!\n");
		return 1;
	}
	
	if(User->query_sp() < 50){
		write("You don't have the energy to do that.\n");
		return 1;
	}
	
	prevent = clone_object(OBJPATH+"novanish.c");
	move_object(prevent, User);
	prevent->start_it();
	
    s = sizeof(ob = all_inventory(environment(User)));
      
    while(h < s)
    {
	    if(att = (object)ob[h]->query_attack())
	    {
	    	ob[h]->stop_fight();
	    	att->stop_fight();
	    	ob[h]->stop_fight();
	    	att->stop_fight();
	    }
	    h++;
    }
    write("You wrap the "+HIBLK+"shadows"+NORM+" back around you, leaving the room peacefully.\n");
    say(User->query_name()+" disappears into the "+HIBLK+"shadows"+NORM+".\n");
    User->add_spell_point(-50);
    User->set_invis_sp();
    PO->set_stealthed(1);
    return 1;
}
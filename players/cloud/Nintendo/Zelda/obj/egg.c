/*
 *  Golden Egg
 *  /Nintendo/Zelda/obj/egg.c
 *  Cloud 2015
 */
 
#include "/obj/ansi.h";
inherit "obj/treasure";

reset(arg)  
{
	if(arg) return;

   	set_name("Golden_Egg");
   	set_alias("egg");
   	set_short(""+HIY+"Golden Egg"+NORM+"");
   	set_long("A "+HIY+"Golden Egg"+NORM+" perhaps you could 'crack' it to see what's inside?\n");
   	set_weight(1);
   	set_value(1);
}

init()
	{
		::init();
		add_action("crackit","crack");
	}

crackit(string str)
{
	int I;
	if(str == "egg")
	{				
  		tell_object(this_player(),
	  		"\nYou crack open the "+HIY+"Golden Egg"+NORM+".\n\n");
		tell_room(environment(this_player()),
			"\n"+this_player()->query_name()+" cracks open a "+HIY+"Golden Egg"+NORM+".\n", ({ this_player() }));		
		tell_object(this_player(),
	  		"\nSuddenly you are transported somewhere else. You hear a deep 'CLUCK' from behind you.\n\n");
		tell_room(environment(this_player()),
			"\n"+this_player()->query_name()+" is suddenly sucked upward into a portal.\n", ({ this_player() }));			
		move_object(this_player(), "/players/cloud/Nintendo/Zelda/rooms/dun1.c");
        command("look", this_player());
        destruct(this_object());
		return 1;
	}	
	else
	{
		write("What?\n");
		return 1;
	}
}
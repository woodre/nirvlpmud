/*  Nintendo Hub (Castle)
 *  cloud/Nintendo/hub.c
 *  Cloud 2012
 *	Main hub into my classic NES based areas.
 */

#define DEST "/players/cloud/workroom"
#include "/obj/ansi.h"

id(str) { return str == "hub"; }

short() 
{
    return ""+HIR+"Nintendo "+HIK+"Hub"+NORM+"";
}

long() 
{
    write("A well constructed, metal warehouse with a large, blinking\n");
    write(""+BLINK+""+HIR+"Nintendo "+NORM+"sign that stretches the entire length of the building.\n");
    write("A a set of dark-tinted, glass double doors lead into the hub.\n");
    write("Multi-colored lights flicker and flash from within the building.\n");
    write("A mixture of electronic music, beeps and hums float in the air\n");
    write("around it. 'enter hub' to check out whats going on inside!\n");
}

init() 
{
  add_action("enter", "enter");
}

enter(str) 
{
	
    if(str == "hub")
    {
		tell_object(this_player(),
	  		"You enter the "+HIR+"Nintendo "+HIK+"Hub"+NORM+".\n");
		tell_room(environment(this_player()),
			""+this_player()->query_name()+" enters the "+HIR+"Nintendo "+HIK+"Hub"+NORM+".\n", ({ this_player() }));
    	move_object(this_player(), "/players/cloud/Nintendo/rooms/inhub.c");
    	command("look", this_player());
    	return 1;
	}
    else
    {
    	write("You can only enter the "+HIK+"hub"+NORM+".\n");
	}
    	  
}

reset(arg) 
{
    if (arg)
	return;
    move_object(this_object(), DEST);
}

/*is_castle(){return 1;}*/


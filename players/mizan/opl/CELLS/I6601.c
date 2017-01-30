inherit "/room/room.c";
#include "/obj/ansi.h"

object reward;
/*This is a cell inside a stone block */


reset(int arg)
{
	if(arg) return;

	add_property("fight_area");
	set_light(0);
	short_desc = "Inside a stone block";
	long_desc = "    You are inside a massive stone block. It is dank and musty in here.\n"+
	"  Being on top of the block, despite its drawbacks is definitely a lot\n"+
	"  more comfortable than being inside this nasty, moldy pit.\n";
	if(!reward)
	{
		reward = clone_object("/players/mizan/opl/beasties/hard/ogress.c");
		move_object(reward, this_object());
	}


	set_no_clean(1);
}

realm() { return "NT"; }


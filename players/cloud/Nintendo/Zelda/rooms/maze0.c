/*  Zelda maze0
 *  /Nintendo/Zelda/rooms/maze0.c
 *  Cloud 2010
 */
 
#include "/obj/ansi.h"
inherit "room/room";

int spawn;
int selector;

reset(arg) 
{	
	::reset(arg);
	if(!arg)
 	{
		set_light(1);

		short_desc = ""+HIG+"A Maze of Hedges"+NORM+"" ;
		
		long_desc =
     	""+HIG+"***********"+NORM+"\n"+
     	""+HIG+"*"+HIK+"........."+HIG+"*"+NORM+"\n"+
     	""+HIG+"*"+HIK+"........."+HIG+"*"+NORM+"\n"+
     	""+HIG+"*"+HIK+"........."+HIG+"*"+NORM+"\n"+
     	""+HIG+"*"+HIK+"........."+HIG+"*"+NORM+"\n"+
     	""+HIG+"*****"+HIR+"@"+HIG+"*****"+NORM+"\n";
     	
		items = 
		({
			"hedge",
				"its green",
		});

		
		dest_dir = 
		({
			"players/cloud/Nintendo/Zelda/rooms/maze5.c","north",
  			"players/cloud/Nintendo/rooms/inhub.c","out",
		});
	}
}
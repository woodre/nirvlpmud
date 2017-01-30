/*  Zelda maze3
 *  /Nintendo/Zelda/rooms/maze3.c
 *  Cloud 2010
 */
 
#include "/obj/ansi.h"
inherit "room/room";

int spawn;
int selector;
int selectora;
int selectorb;

reset(arg) 
{	
	::reset(arg);
	if(!present("octorok")) 
	{	
		if(!present("tektite")) 
		{	
			if(!present("moblin")) 
			{	
				spawn = random(3);
				selector = random(6);
				selectora = random(6);
				selectorb = random(6);
				if (spawn == 0) 
				{
					move_object(clone_object("/players/cloud/Nintendo/Zelda/mobs/mob"+selector+".c"),this_object());
				}
				if (spawn == 1)
				{
					move_object(clone_object("/players/cloud/Nintendo/Zelda/mobs/mob"+selector+".c"),this_object());
					move_object(clone_object("/players/cloud/Nintendo/Zelda/mobs/mob"+selectora+".c"),this_object());
				}	
				if (spawn == 2)
				{
					move_object(clone_object("/players/cloud/Nintendo/Zelda/mobs/mob"+selector+".c"),this_object());	
					move_object(clone_object("/players/cloud/Nintendo/Zelda/mobs/mob"+selectora+".c"),this_object());
					move_object(clone_object("/players/cloud/Nintendo/Zelda/mobs/mob"+selectorb+".c"),this_object());
				}					
			}
		}
	}
	
	if(!arg)
 	{
		set_light(1);

		short_desc = ""+HIG+"A Maze of Hedges"+NORM+"" ;
		
		long_desc =
     	""+HIG+"***********"+NORM+"\n"+
     	""+HIG+"*"+HIK+"........."+HIG+"*"+NORM+"\n"+
     	""+HIG+"*"+HIK+"........."+HIG+"*"+NORM+"\n"+
     	""+HIG+"*"+HIK+"........."+HIG+"*"+NORM+"\n"+
     	""+HIG+"*"+HIK+".."+HIR+"@"+HIK+"......"+HIG+"*"+NORM+"\n"+
     	""+HIG+"***** *****"+NORM+"\n";
     	
		items = 
		({
			"hedge",
				"its green",
		});

		
		dest_dir = 
		({
			"players/cloud/Nintendo/Zelda/rooms/maze4.c","east",
			"players/cloud/Nintendo/Zelda/rooms/maze2.c","west",
			"players/cloud/Nintendo/Zelda/rooms/maze16.c","north",
		});
	}
}
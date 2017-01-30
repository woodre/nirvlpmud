/*  Zelda maze32
 *  /Nintendo/Zelda/rooms/maze32.c
 *  Cloud 2010
 */
 
#include "/obj/ansi.h"
inherit "room/room";

reset(arg) 
{	
	::reset(arg);
	if(!arg)
 	{
		set_light(1);

		short_desc = ""+HIG+"A Maze of Hedges"+NORM+"" ;
		
		long_desc =
     	""+HIG+"***********"+NORM+"\n"+
     	""+HIG+"*"+HIK+"...."+HIR+"@"+HIK+"...."+HIG+"*"+NORM+"\n"+
     	""+HIG+"*"+HIK+"........."+HIG+"*"+NORM+"\n"+
     	""+HIG+"*"+HIK+"........."+HIG+"*"+NORM+"\n"+
     	""+HIG+"*"+HIK+"........."+HIG+"*"+NORM+"\n"+
     	""+HIG+"***** *****"+NORM+"\n"+
     	"A massive tower is erected here atop a tall rock\n"+
     	"formation. Cruel, jagged rocks spear out in all\n"+
     	"directions under the tower shielding it mostly from\n"+
     	"view. A large, dark doorway leads into the base of\n"+
     	"the mysterious formation.\n";
     	
     	
		items = 
		({
			"hedge",
				"its green",
			"tower",
				"From what can be seen from this vantage point, it looks to be\n" +
				"a dark, grey, pyramid. It sits upon the formation soundly",
			"formation",
				"Jagged tiers of dark brown rocks pour from around it",
			"rocks",
				"Spear-like rocks shoot out from the formation blocking a good\n" +
				"view of the tower",
			"doorway",
				"A large opening at the base of the formation. It looks to be\n" +
				"about thirty feet tall and twenty feet wide", 
			"base",
				"The base of the formation sits strong on the ground here",
		});

		
		dest_dir = 
		({
			"players/cloud/Nintendo/Zelda/rooms/maze31.c","east",
			"players/cloud/Nintendo/Zelda/rooms/maze23.c","south",
			"players/cloud/Nintendo/Zelda/rooms/maze33.c","west",
			"players/cloud/Nintendo/Zelda/rooms/dun1.c","enter",
		});
	}
}
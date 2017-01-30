/*  Nintendo Hub Interior
 *  /Nintendo/inhub.c
 *  Cloud 2012
 */
 
#include "/obj/ansi.h"
inherit "room/room";

reset(arg) 
{	
	::reset(arg);
	
	if(!present("machine")) 
	{	
		move_object(clone_object("/players/cloud/Nintendo/obj/dewmachine.c"),this_object());		
	}	
	
	
	
	if(!arg)
 	{
		set_light(1);

		short_desc = ""+HIG+"The Nintendo Hub"+NORM+"" ;
		
		long_desc =
		"\t"+HIR+"NNN   NN NN       NN                  NN    (R)"+NORM+"\n"+ 
		"\t"+HIR+"NNNN  NN         NNNN  NNNN           NN       "+NORM+"\n"+
		"\t"+HIR+"NN NN NN NN NNNN  NN  NN..NN NNNN   NNNN  NNNN "+NORM+"\n"+ 
		"\t"+HIR+"NN  NNNN NN NN NN NN  NN     NN NN NN NN NN  NN"+NORM+"\n"+ 
		"\t"+HIR+"NN   NNN NN NN NN NN   NNNN  NN NN  NNNN  NNNN "+NORM+"\n\n"+ 
     	""+HIW+"Giant television screens surround the walls of this room. Several"+NORM+"\n"+
     	""+HIW+"gaming systems litter the numerous shelving affixed upon the floor."+NORM+"\n"+
     	""+HIW+"In the center of the room sits several chairs set in a circle pointing"+NORM+"\n"+
     	""+HIW+"outward towards the giant screens. Here is a list of games you can play: "+NORM+"\n\n"+
     	""+HIG+"Zelda"+NORM+"\n"+
     	"\t\tUse 'play <game>' to start.\n\n";
     	
     	
     	
		items = 
		({
			"screens",
				"Sixty inch flat-screen LCD screens",
			"walls",
				"They are made of block and are painted black",
			"systems",
				"Every console Nintendo has ever made line the shelving.",
			"shelving",
				"Wire shelving bolted to the floor",
			"floor",
				"Red carpet covers the floor",
			"carpet",
				"Fuzzy and red, the carpet is very squishy",
			"chairs",
				"Large, black, leather chairs. Each chair has built-in speakers\n"+
				"recessed into the head rests",
			"speakers",
				"They are built into the head-rests of the chairs here",
			
		});

		
		dest_dir = 
		({
			"players/cloud/workroom.c","out",
		});
	}
}

init()
	{
		::init();
		add_action("play","play");
	}

	play(string str)
	{		
		if(str == "zelda")
  		{	
	  		tell_object(this_player(),
	  			"\nYou sit down in a chair and start playing "+HIG+"The Legend of Zelda"+NORM+"\n\n");
			tell_room(environment(this_player()),
				"\n"+this_player()->query_name()+" sits down in a chair and starts playing "+HIG+"The Legend of Zelda."+NORM+"\n", ({ this_player() }));
			move_object(this_player(), "/players/cloud/Nintendo/Zelda/rooms/maze0.c");
            command("look", this_player());
			return 1;
 		}
 		 
  		else
  		{
	  		write("That game isnt available. Please choose one from the list.\n");
	  		return 1;
  		}
	}
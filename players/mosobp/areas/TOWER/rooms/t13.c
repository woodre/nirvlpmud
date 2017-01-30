/*                                       
 *  File:   /players/mosobp/areas/TOWER/rooms/t13.c    
 *  Function:  room                      
 *  Author(s):  Mosobp@Nirvana           
 *  Copyright: copyright (c) 2008 Mosobp 
 *             all rights reserved            
 *                                       
 *                                       
 *  Source:  7/17/08                     
 *  Notes:                               
 *                                       
 *                                       
 *  Change History:                      
 */
#include "/sys/lib.h"

#include "/obj/ansi.h"

inherit "room/room";

int picked;

reset(arg)
{
  ::reset(arg);
  if( !present("garlic jr.", this_object()) )
  move_object(clone_object("/players/mosobp/areas/TOWER/NPC/garlicjr.c"), this_object());      
  if(arg) return;
  
  if(!present("shinshi_bush")){
	  move_object(clone_object("/players/shinshi/closed/rogue/objects/bush.c"), this_object());
  }
  
  picked = 0;
  
  set_light(1);
  short_desc = BLU+"Kame's Lookout"+NORM;
  long_desc = 
  "  "+HIK+"This is the edge of Kame's Lookout. From here\n"+
  "Kame keeps a watch on the whole earth looking around there\n"+
  "are bushes all around. There is a house to the south."+NORM+"\n";
 
  items=
  ({
    "platform",
    "You are standing on the lookout",
    "bushes",
    "The bushes are scattered all about the edge of the lookout",
    "edge",
    "Looking over the edge you can barely make out the ground far far below",
    "house",
    "Kame's house can be seen to the south",
   });
  
  dest_dir =
  ({
    "/players/mosobp/areas/TOWER/rooms/t14.c",  "east",
    "/players/mosobp/areas/TOWER/rooms/t12.c",  "west",
    "/players/mosobp/areas/TOWER/rooms/t10.c",  "south",
  });
  return 1;
}
init()
{
  ::init();
  
  if(present("shinshi_rogue_seal", this_player()))
  {
	  add_action("cmd_pick", "pick");
  }
}

cmd_pick(str)
{
	int berries;
	
	berries = random(4);
	if(!str)
	{
		write("You can only pick the berries!\n");
		return 1;
	}
	
	if(str != "berries")
	{
		write("You can only pick the berries!\n");
		return 1;
	}
	
	if(picked)
	{
		write("The berries have already been picked!\n");
		return 1;
	}
	
	if(berries == 0)
	{
		move_object(clone_object("/players/shinshi/closed/rogue/objects/berry1.c"), this_player());
		picked = 1;
		write("You pick some berries off the bush.\n");
		say(this_player()->query_name()+" picks some berries off of a bush.\n");
		destruct(present("shinshi_bush", this_object()));
		return 1;
	}
	
	if(berries == 1)
	{
		move_object(clone_object("/players/shinshi/closed/rogue/objects/berry2.c"), this_player());
		picked = 1;
		write("You pick some berries off the bush.\n");
		say(this_player()->query_name()+" picks some berries off of a bush.\n");
		destruct(present("shinshi_bush", this_object()));
		return 1;
	}
	
	if(berries == 2)
	{
		move_object(clone_object("/players/shinshi/closed/rogue/objects/berry3.c"), this_player());
		picked = 1;
		write("You pick some berries off the bush.\n");
		say(this_player()->query_name()+" picks some berries off of a bush.\n");
		destruct(present("shinshi_bush", this_object()));
		return 1;
	}
	
	if(berries == 3)
	{
		move_object(clone_object("/players/shinshi/closed/rogue/objects/berry4.c"), this_player());
		picked = 1;
		write("You pick some berries off the bush.\n");
		say(this_player()->query_name()+" picks some berries off of a bush.\n");
		destruct(present("shinshi_bush", this_object()));
		return 1;
	}
	return 1;
}
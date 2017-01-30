/*                                      
 *  File:   /players/mosobp/areas/BATTLE/rooms/b11.c    
 *  Function:  room                      
 *  Author(s):  Mosobp@Nirvana           
 *  Copyright: copyright (c) 2008 Mosobp 
 *             all rights reserved            
 *                                       
 *                                       
 *  Source:  6/17/08                     
 *  Notes:                               
 *                                       
 *                                       
 *  Change History:                      
 */

#include "/sys/lib.h"

#include "ansi.h"

inherit "room/room";

int x;

int picked;

reset(arg)
{
  ::reset(arg);
  if( !present("saibaman2", this_object()) )
    call_out("get_saibaman2", 1);
  if( !present("android", this_object()) )
    move_object(clone_object("/players/mosobp/areas/BATTLE/NPC/android.c"), this_object());
  if(arg) return ;
  
   
  if(!present("shinshi_bush")){
	  move_object(clone_object("/players/shinshi/closed/rogue/objects/bush.c"), this_object());
  }
  
  picked = 0;
  
  set_light(1);
  short_desc = GRN+"An open field"+NORM;
  long_desc =
  "  An open area of land with plush green grass\n"+
  "all around. Far off to the east a cliff rises into\n"+
  "the sky. The sky seems to darken as it nears the cliff.\n"+
  "A little hole waits for someone to trip in it.\n";

  items=
  ({
    "grass",
    "Plush green grass with flowers occasionally growing in it",
    "cliff",
    "The cliff is off to the east",
    "sky",
    "The sky above is clear and normal, as it reaches the cliff it darkens",
    "hole",
    "A little gopher hole waiting here to trip someone.",
  });

  dest_dir =
  ({
    "players/mosobp/areas/BATTLE/rooms/b6.c",   "northwest",
    "players/mosobp/areas/BATTLE/rooms/b7.c",   "north",
    "players/mosobp/areas/BATTLE/rooms/b16.c",  "south",
    "players/mosobp/areas/BATTLE/rooms/b15.c",  "southwest",
    "players/mosobp/areas/BATTLE/rooms/b12.c",  "east",
    "players/mosobp/areas/BATTLE/rooms/b10.c",  "west",
  });
}

void get_saibaman2(){
  for(x=0; x<1; x++)
    {
  move_object(clone_object("/players/mosobp/areas/BATTLE/NPC/saibaman2.c"), this_object());
    }
  tell_room(this_object(), "\n");
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
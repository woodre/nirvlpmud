#include "/obj/ansi.h"
inherit "players/earwax/housing/land.c";
inherit "room/room";
int picked;
reset (arg) {
 if(arg) return;
 
 if(!present("shinshi_bush")){
	  move_object(clone_object("/players/shinshi/closed/rogue/objects/bush.c"), this_object());
  }
  
  picked = 0;

short_desc = BLU + "Namekian Suburbs" +NORM;
long_desc = 
"Mountains are close in view to the east, and distant in the west.\n"+
"There are bushes lining the road.\n";
set_light(1);
dest_dir = ({
"players/mosobp/areas/HOUSING/rooms/h14.c","west",
"players/mosobp/areas/HOUSING/rooms/h16.c","east",
});
set_realm_name("Namekian Suburbs");
set_lot_size(3);
set_cost(28000);
setup_land();
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
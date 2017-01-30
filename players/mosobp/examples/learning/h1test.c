#include "/obj/ansi.h"
inherit "/players/earwax/housing/land.c";
inherit "room/room";
int picked;
reset(arg)  {
  if(arg) return;
  
  picked = 0;

short_desc = BLU+"Namekian Suburbs"+NORM;
long_desc = 
"Flat area of land with mountains to the north, and south.  A road heads\n"+
"west to the temple, and the flat area continues to the east and south.\n";
items = ({
"temple","The Namekian temple is to the west",
"mountains","There are mountains to the north and far to the south",
"road","The road leads to the temple",
});
set_light(1);
dest_dir = ({
"players/mosobp/areas/HOUSING/rooms/h2.c","east",
"players/mosobp/areas/HOUSING/rooms/h5.c","south",
"players/mosobp/areas/TEMPLE/rooms/temple10.c","enter",
});
set_realm_name("Namekian Suburbs");
set_lot_size(3);
set_cost(30000);
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
		return 1;
	}
	
	if(berries == 1)
	{
		move_object(clone_object("/players/shinshi/closed/rogue/objects/berry2.c"), this_player());
		picked = 1;
		write("You pick some berries off the bush.\n");
		say(this_player()->query_name()+" picks some berries off of a bush.\n");
		return 1;
	}
	
	if(berries == 2)
	{
		move_object(clone_object("/players/shinshi/closed/rogue/objects/berry3.c"), this_player());
		picked = 1;
		write("You pick some berries off the bush.\n");
		say(this_player()->query_name()+" picks some berries off of a bush.\n");
		return 1;
	}
	
	if(berries == 3)
	{
		move_object(clone_object("/players/shinshi/closed/rogue/objects/berry4.c"), this_player());
		picked = 1;
		write("You pick some berries off the bush.\n");
		say(this_player()->query_name()+" picks some berries off of a bush.\n");
		return 1;
	}
	return 1;
}
#include <ansi.h>
inherit "room/room";
int picked;
reset(arg) {
  if(arg) return;
  
  if(!present("shinshi_bush")){
	  move_object(clone_object("/players/shinshi/closed/rogue/objects/bush.c"), this_object());
  }
  
  picked = 0;

short_desc = "Entrance to the Temple";
long_desc = 
"This is the path to the entrance of the temple. The spaceship\n"+
"which brought you is behind, and the temple looming in front.\n"+
"There are shrubs on the ground around, and trees giving\n"+
"shade overhead.\n"+
"You can type 'ship' to head back to the "+HIK+"Spaceship"+NORM+".\n";
  items = ({
"path","A footpath from the ship to the temple",
"entrance","The entrance to the temple",
"spaceship","The ship you arrived on",
"ship","The ship you arrived on",
"temple","The Namekian temple of worship",
"shrubs","Green leafy shrubs planted beside the entrance to the temple",
"trees","Trees planted to give shade over the path to the temple",
});
set_light(1);
dest_dir = ({
"players/mosobp/areas/TEMPLE/rooms/temple3.c","temple",
"players/mosobp/areas/HOUSING/rooms/h9.c","east",
});
}

init(){
  ::init();
  add_action("cmd_ship", "ship");
  if(present("shinshi_rogue_seal", this_player()))
  {
	  add_action("cmd_pick", "pick");
  }
}


cmd_ship(str) {
  object ship;
  if(str) return 0;
  write("\n\n\tYou head back to the ship.\n\n");
  ship = clone_object("/players/mosobp/areas/TEMPLE/rooms/ship_fran");
  ship->set_location("/players/mosobp/areas/TEMPLE/rooms/temple0");
  move_object(this_player(), ship);
  command("look", this_player());
  return 1;
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
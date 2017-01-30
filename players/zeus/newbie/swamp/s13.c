#include <ansi.h>
inherit "room/room";

reset(arg){
 if(!arg){
	 if(!present("bandit guard", this_object()))
		 move_object(clone_object(
		 "/players/zeus/newbie/NPC/area_guard.c"));

  short_desc="A muggy forest";
  long_desc=
"You stand in the center of a slight clearing in a forest.  The towering\n"+
"trees climb high into the sky.  Directly to the east is a gigantic blue\n"+
"portal which is shimmering fluidly.  You are surrounded in all directions\n"+
"by trees, except for a small path which leads to the west.  The weather\n"+
"is very humid, making you very uncomfortable.\n";
  set_light(1);
  items=({
 "trees",
"These trees, a mix of cypress and mangrove trees, fill your view in every\n"+
"direction.  Many roots are visible protruding from the ground around the\n"+
"bases of the mangrove trees",
 "roots",
"A characteristic of the mangrove trees, many of their roots are visible\n"+
"above the ground",
 "portal",
"This gigantic blue portal seems to be a gateway into another realm.  It\n"+
"is massive in size, and oval shaped.  Looking through it you are unable\n"+
"to see anything",
 "path",
"A clear dirt path leads into the forest to the west.  It is the only way\n"+
"to leave this part of the forest, other than through the portal",
  });
  dest_dir=({
	  "/players/zeus/newbie/swamp/s12.c", "west",
	  "/players/zeus/realm/main.c", "portal",
  });
} }

void init(){
	::init();
 add_action("west_dir", "west");
 add_action("portal_dir", "portal");
}

west_dir(){
	if(this_player()->query_level() > 6 && 
		this_player()->query_level() < 21 
		&& present("bandit guard", this_object())){
		write(
"The bandit says: You may NOT pass, you are too experienced.\n");
		return 1;
	}
}

portal_dir(){
  write("You step through the "+BLU+" shimmering blue portal...\n"+NORM+
	  "\n\n\t\tYou fly through time and space...\n\n\n");
}

#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
object guard1;
object guard2;

reset(arg) {
	if(!present("cont_lizardguard")){
	guard1 = clone_object("/players/maledicta/cont/ltown/mobs/lguard.c");
	move_object(guard1, this_object());
	guard2 = clone_object("/players/maledicta/cont/ltown/mobs/lguard.c");
	move_object(guard2, this_object());
	}
  if(arg) return;
set_light(1);

short_desc = "a swampy area";
long_desc =
"  You stand before a small, walled village.  A thin mist\n"+
"floats along the ground, but you can tell that the land\n"+
"here is more solid.  Beyond the wall you can make out \n"+
"thatched roofs.  A gate stands before you, the swamp behind\n"+
"you.\n";  

items = ({
  "village",
  "A small walled village that you can 'enter'",
  "mist",
  "A thin mist that coats the ground",
  "ground",
  "The ground here is mushy, but solid",
  "wall",
  "A large wooden wall with the top shaped into spikes",
  "land",
  "The land here is more solid than the rest of the swamp",
  "roofs",
  "Thatched roofs that you can barely make out from here",
  "gate",
  "A large wooden gate that leads into the village. You\n"+
  "can 'enter' it",
  "swamp",
  "The swamp you just trudged through",
  });

dest_dir = ({
  "/players/maledicta/path/rooms/r11.c","south",
});

}

init(){
	::init();
	add_action("enter", "enter");
}

enter(str){
	if(!str){
		write("Enter what?\n");
		return 1;
	}
	if(str == "gate" || str == "village"){
		this_player()->move_player("into village#players/maledicta/cont/ltown/rooms/l1.c");
	}
	else{
		write("enter what?\n");
		return 1;
	}
	return 1;
}

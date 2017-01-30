#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
#include "/players/maledicta/ansi.h"
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

short_desc = "The village of "+HIG+"Terk'ula"+NORM+"";
long_desc =
"  You are in the small village of Terk'ula. It is mostly\n"+
"populated by lizardmen, with a few wanderers who have set\n"+
"up shop here. This is the main street of the small village.\n"+
"To the east is a small decrepit bar, and to the north the\n"+
"road continues. The gates stand behind you to the south. The\n"+
"village is surrounded by a high wooden wall.\n";

items = ({
  "street",
  "A dirt road that leads through the center of town",
  "bar",
  "A small building made of rock and sealed with mud. It has a\n"+
  "sign on the door that reads, 'The Lizards Bite'",
  "road",
  "A dirt road that leads through the center of town",
  "gates",
  "A large wooden gate that is spiked at the top",
  "wall",
  "A tall wooden wall that defends the village from attacks",
});

dest_dir = ({
  "/players/maledicta/cont/ltown/rooms/l2.c","north",
  "/players/maledicta/cont/ltown/rooms/lbar.c", "east",
  "/players/maledicta/cont/rooms/880", "leave"
});

}


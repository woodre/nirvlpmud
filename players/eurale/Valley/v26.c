/*  The Park Valley  */

#include "defs.h"
inherit "room/room";
int SK;

reset(arg) {

if(!present("antromedus")) {
SK=1;
  move_object(clone_object("players/eurale/Park/NPC/antro"),TO); }

  if(arg) return;
set_light(1);

short_desc = "Hidden valley";
long_desc =
	"  The vegetation is getting much denser here.  There are lots \n"+
	"of ferns and tall trees covering the floor again.  The moss \n"+
	"that grows in abundance here provides a cushion for the valley \n"+
	"floor.  There is a huge boulder to the east that you might be \n"+
	"be able to climb.\n";

items = ({
	"ferns","Large, leafy plants",
	"trees","Tall, green trees with thich foliage",
	"moss","Dark green and velvety looking",
});

dest_dir = ({
	"players/eurale/Valley/v25.c","west",
	"players/eurale/Valley/v27.c","east",
	"players/eurale/Valley/v12.c","northeast",
	"players/eurale/Valley/v11.c","north",
	"players/eurale/Valley/v10.c","northwest",
});

}
realm() { return "NT"; }

init() {
  ::init();
  add_action("strip","strip");
}

strip(str) {
if(present("antro")) {
  write("The antrodemus snarls and steps back out of reach...\n");
  return 1; }
if(!str) { write("Strip what?\n"); return 1; }
if(str == "skin" || str == "antrodemus" &&
  present("corpse",environment(this_player()))->query_name()
  == "antrodemus") {

  if(SK == 1) {
    write("You grab the skin after cutting through it completely\n"+
	  "around the neck and strip it off the corpse leaving\n"+
	  "behind a bloody mass of meat...\n");
    move_object(clone_object("players/eurale/Park/OBJ/antro_skin"),TP);
    SK = 0;
    return 1; }
  else {
    write("You look the bloody mass over and find no more skin left.\n");
    return 1; }
return 1; }
}

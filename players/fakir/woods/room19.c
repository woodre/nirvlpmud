#define TP this_player()
#define TPN this_player()->query_name()
#include "/players/fakir/color.h"
#define TPP this_player()->query_possessive()
inherit "room/room";
int found;

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Clearcut";
long_desc =
"Many trees have been cut down, and all that remains are the foot tall\n"+
"stumps of what once was a beautiful woodland forest.  Most of the bushes\n"+
"have been trampled under horses shod hooves, and wagon tracks lead south\n"+
"and west.  It will be some time before this area grows back to its natural\n"+
"beauty.\n";

items = ({
"trees",   "There are no trees here anymore",
"stumps",  "What is left of once tall oak and spruce trees",
"bushes",  "Mostly crushed by horse's hooves and wagon wheels",
"tracks",  "The ruts left in the ground by the wheels of flatbed wagons used to haul logs"
});
if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/strolloc.c"),this_object());
if(!present("fox",this_object()))
 move_object(clone_object("/players/fakir/woods/NPC/fox.c"),this_object());

dest_dir = ({
   "/players/fakir/woods/room20.c", "west",
   "/players/fakir/woods/room26.c", "north",
   "/players/fakir/woods/room17.c", "south",
   "/players/fakir/woods/room13.c", "northeast",
});
}



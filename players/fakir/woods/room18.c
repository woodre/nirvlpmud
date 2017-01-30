#define TP this_player()
#define TPN this_player()->query_name()
#include "/players/fakir/color.h"
#define TPP this_player()->query_possessive()
inherit "room/room";
int found;

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Logged Area";
long_desc =
"Several large trees have been cut down, and lie on the ground with limbs\n"+
"broken and twisted.  Some trees still stand but are marked with a red X in\n"+
"the center of the trunk.  What once was a beautiful woodland forest is now\n"+
"a boneyard of broken trees.  Some of the bushes have been trampled under the\n"+
"horses' shod hooves, and wagon tracks lead north and east.  It will be some time\n"+
"before this area grows back to its natural beauty.\n";
items = ({
"trees",   "Cut down oak and spruce.  Some alder and maple still stand",
"ground",  "It is covered in broken limbs and leaves and torn up dirt from wagon wheels",
"limbs",   "The broken limbs from the cut trees",
"trunk",   "The portion of the tree which loggers harvest.  Some have a red X on them",
"stumps",  "What is left of once tall oak and spruce trees",
"bushes",  "Mostly crushed by horse's hooves and wagon wheels",
"tracks",  "The ruts left in the ground by the wheels of flatbed wagons used to haul logs"
});
if(!present("bole",this_object()))
 move_object(clone_object("/players/fakir/woods/NPC/bole.c"),this_object());
if(!present("naz",this_object()))
 move_object(clone_object("/players/fakir/woods/NPC/naz.c"),this_object());

dest_dir = ({
   "/players/fakir/woods/room17.c", "east",
   "/players/fakir/woods/room20.c", "north",

});
}



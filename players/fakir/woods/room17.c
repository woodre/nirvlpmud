#define TP this_player()
#define TPN this_player()->query_name()
#include "/players/fakir/color.h"
#define TPP this_player()->query_possessive()
inherit "room/room";
int found;

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Whispering Woods";
long_desc =
"Several large trees have been cut down, and lie on the ground with limbs\n"+
"broken and twisted.  Some trees still stand but are marked with a red X\n"+
"in the center of the trunk.  What once was a beautiful woodland forest is\n"+
"now a boneyard of broken trees.  A team of draw horses are hitched to a\n"+
"flatbed wagon and stand waiting to haul the logs from the forest.  Some\n"+
"of the bushes have been trampled under the horses' shod hooves, and wagon\n"+
"tracks lead north and west.  It will be some time before this area grows\n"+
"back to its natural beauty.\n";
items = ({
"trees",   "Cut down oak and spruce.  Some alder and maple still stand",
"ground",  "It is covered in broken limbs and leaves and torn up dirt from wagon wheels",
"limbs",   "The broken limbs from the cut trees",
"trunk",   "The portion of the tree which loggers harvest.  Some have a red X on them",
"horses",  "Large bodied work horses.  They are branded with the Two Rivers marking",
"wagon",   "A flat bed with a single seat in the front.  Oversized wheels and an extra\n"+
           "heavy tounge and harness show this to be a logging wagon from the Two Rivers",

"stumps",  "What is left of once tall oak and spruce trees",
"bushes",  "Mostly crushed by horse's hooves and wagon wheels",
"tracks",  "The ruts left in the ground by the wheels of flatbed wagons used to haul logs"
});
if(!present("jinx",this_object()))
 move_object(clone_object("/players/fakir/woods/NPC/jinx.c"),this_object());

dest_dir = ({
   "/players/fakir/woods/room18.c", "west",
   "/players/fakir/woods/room19.c", "north",

});
}



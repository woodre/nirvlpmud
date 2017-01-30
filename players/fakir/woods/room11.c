#define TP this_player()
#define TPN this_player()->query_name()
#include "/players/fakir/color.h"
#define TPP this_player()->query_possessive()
inherit "room/room";
int found;

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Cliff Lake";
long_desc =
"Crystal-clear water falls from the top of a rock cliff thirty feet\n"+
"in height to the north.  It catches on outcrops of rock as it falls,\n"+
"breaking up into countless droplets before it once again becomes one\n"+
"in the small lake at the base of the cliff.  A small brook breaks off\n"+
"from the lake and travels west, dividing the trees and bushes with its\n"+
"passing.  You can follow the brook west if you stay close to its banks.\n"+
"The lake wraps around to the east, and across the lake trees grow tall\n"+
"and green and vibrant in the warm sun.  A small clearing opens to the\n"+
"south.\n";

items = ({
"shore",   "Small barkless tree trunks and deadfall limbs line the shore\n"+
           "of the lake, as well as a few small bushes",
"sun",     "Bright and set in a near cloudless sky",
"clearing","Mostly grass and scattered wild flowers, it is surrounded by the\n"+
           "woods on all sides, except here where it meets the lakeshore",
"bushes",  "Gooseberry, rhododendrons in full bloom, wild grape and a few vine maple",  
"lake",    "Created by the small stream that falls from the cliff top, it stretches\n"+
           "north from where you stand to the base of the cliff, and curves around to\n"+
           "the east, ending in a tree line of evergreens and oak",
"droplets","Bouncing off the rock face of the cliff, they fall toward the lake below",
"outcrops","Small projections of rock the falling water has not yet worn smooth",
"cliff",   "It borders the far shore of the lake to the north, and drops to the level\n"+
           "of the lake on the horizon east, to the point where the trees begin again",
"brook",   "It begins at the edge of the lake and disapears to the west through the\n"+
           "close growing trees and bushes",
"water",   "Crystal clear and very cold",
"trees",   "To the west they look like maple, alder, and ash mixed together.  Those across\n"+
           "the lake appear to be evergreens of some kind, perhaps spruce and pine, mixed\n"+
           "with a smattering of oak and tamarack",
"maple",   "The maple trees are rather pear shaped with symetrical three fingered leaves",
"alder",   "The alder trees look very much like the maple, but not as broad at the top",
"ash",     "The ash trees are oval in shape, and have small delicate leaves of silver and green",
"bushes",  "Gooseberry, rhododendrons in full bloom, wild grape and a few vine maple",
"banks",   "Mostly damp forest earth, with a few partially exposed round, grey rocks",


});

dest_dir = ({
   "/players/fakir/woods/room10.c", "west",
   "/players/fakir/woods/room12.c", "south",
  
});
}



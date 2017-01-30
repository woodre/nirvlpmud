#define TP this_player()
#define TPN this_player()->query_name()
#include "/players/fakir/color.h"
#define TPP this_player()->query_possessive()
inherit "room/room";
int found;

reset(arg) {
  if(arg) return;
found = 1+random(4);
set_light(1);

short_desc = "Clearing in Whispering Woods";
long_desc =
"Short grass and a few bushes blend into the treeline south, east, and\n"+
"west.  The shore of a lake is to the north, and a narrow waterfall is\n"+
"visible on the cliff face behind the lake.  Small mounds of brown earth,\n"+
"some very freshly dug, spot the clearing.  The clearing extends a bit\n"+
"farther south, but the tree line is very close to the west.  Lodgepole\n"+
"pine grow so close together east as to make passage that way impossible.\n";

items = ({
"pine",    "Thin trunked and tall, they grow so close together passage\n"+
           "through them is impossible but for the smallest of creatures",
"mounds",  "The dirt pushed up from below by small creatures called\n"+
           "'Brown Diggers', or just 'Diggers' for short.  Maybe you\n"+
           "could 'dig' up a few diggers if you tried",
"shore",   "A few small bushes and drifting logs define the shoreline",
"grass",   "Broadleaf meadow grass, very course and rather rough",
"clearing","Mostly grass and scattered wild flowers, it is surrounded by the\n"+
           "woods on all sides, except here where it meets the lakeshore",
"bushes",  "Gooseberry, rhododendrons in full bloom, wild grape and a few vine maple",  
"lake",    "Created by the small stream that falls from the cliff top, it stretches\n"+
           "north from the shoreline to the base of the cliff, and perhaps eastward,\n"+
           "though you cannot tell very well from this vantage point",
"waterfall","A drop of perhaps thirty feet from the top of a rock cliff to the lake below",
"cliff",   "It boarders the far shore of the lake to the north, and drops to the level\n"+
           "of the lake on the horizon to the northeast",

"treeline","To the west they look like maple, alder, and ash mixed together.  Those\n"+
           "to the east are lodgepole pine.  South are spoty groups of spuce and pine",


"bushes",  "Gooseberry, rhododendrons in full bloom, wild grape and a few vine maple",


});

if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/trolloc2.c"),this_object());
dest_dir = ({
   "/players/fakir/woods/room11.c", "north",
   "/players/fakir/woods/room28.c", "south",
   "/players/fakir/woods/room27.c", "west",
});
}
init()  {
  ::init();
    add_action("dig_digger","dig");
}
dig_digger(arg)  {
if(!arg || arg != "digger") {
notify_fail("You might be digging for the wrong animal.\n");
return 0; 
}
if(found==0) { write("All the diggers are hiding too deep in the ground now.\n"); 
return 1; }
if(present("digger",this_object())) {
write("You must kill this one before you dig another.\n");
return 1;
}
write("You dig deep into the brown mound of dirt and come up with a Digger!\n");
move_object(clone_object("/players/fakir/woods/NPC/digger.c"),this_object());
found=found-1;
return 1; 
}

#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Swamp";
long_desc =
	"   The trees and vines are sparse here, but strangely it isn't any\n"+
      "brighter.  It seems like the sunlight is dimmed.  The ground is solid\n"+
      "and free of the ever-present mud, but is covered in the strange black \n"+
      "moss.  To the north it gets a little muddier and to the east the trees \n"+
      "and vines seem to clear out more.\n"
;
      
items = ({
  "ground","Dark rich earth covered almost completely in a black moss",
  "mud","The mud you have seen in the rest of the swamp is missing here",
  "trees","Twisted and gnarled trees that look like twisted skeletal hands",
  "swamp","The dark and dismal area you are in",
  "moss","A soft black substance that covers the ground",
  "vines","Strange thick black vines", 
  "sunlight","The sunlight seems weak and dimmed",
});

dest_dir = ({
  "/players/dusan/area1/rooms/swamp13.c","north",
  "/players/dusan/area1/rooms/swamp16.c","east",
});

}

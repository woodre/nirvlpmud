#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Swamp";
long_desc =
	"   The trees create a natural barrier to the east, and there is a large  \n"+
      "lake to the south.  The ground here is ankle deep black mud.  Something \n"+
      "seems to have moved through here recently leaving a trail.  To the north \n"+
      "you see a small island, and to the east what looks like a small burrow. \n"
          ;
      
items = ({
  "trees","A tangle of trees and branches that look like skeletal hands",
  "vines","These vines grow in abundance here choking out the rest of the vegetation",
  "ground","The ground here is mostly a dark mud",
  "mud","A dark ankle deep mud there seems to be some tracks in it",
  "branches","A black tangled mass of branches",
  "barrier","A tangled mass of vines and branches block your way east",
  "tracks","Various unrecognizable tracks in the mud",
  "trail","A trail in the mud it seems to run into the burrow to the east",
  "burrow","A small dirt burrow to the east",
  "lake","A rather large and deep lake of a brackish water blocks your way to the south",
});

dest_dir = ({
  "/players/dusan/area1/rooms/swamp11.c","west",
  "/players/dusan/area1/rooms/swamp9.c","north",
});

}

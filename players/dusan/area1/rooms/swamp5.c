#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Swamp";
long_desc =
	"   A small stream trickles down the through the roots of a nearby tree \n"+
      "spilling into a large brackish pool that dominates that area.  The  \n"+
      "ground has turned completely into mud, and something seems to stir under \n"+
      "the water of the pool. To the north the ground grows firmer.  To the east \n"+
      "the ground seems to grow muddier, and to the south the pool spreads out.\n"     
;
      
items = ({
  "tree","The bare tree that looks like a skeletal finger sticking out of the ground",
  "vines","These vines grow in abundance here choking out the rest of the vegetation",
  "pool","A large brackish pool",
  "ground","The ground here is mostly a dark mud",
  "mud","A dark mud mixed bits of rotting vegetable matter",
  "stream","An amazingly clear stream trickling through the roots of a tree",
  "roots","A black tangled mass of roots",
  "water","A dark pool of water with ripples in it",
  "ripples","Small ripples in a pool of water something beneath the surface seems to be causing them",
});

dest_dir = ({
  "/players/dusan/area1/rooms/swamp8.c","south",
  "/players/dusan/area1/rooms/swamp6.c","east",
  "/players/dusan/area1/rooms/swamp3.c","north",
});

}

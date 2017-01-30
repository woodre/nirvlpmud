#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Swamp";
long_desc =
	"   Here is a small island dominated by a crooked, knobby, black tree.  Something \n"+
      "white is entangled in the tree.  It is surrounded by chest deep brackish water \n"+
      "that seems to constantly swirl and eddy.  To the north the water seems to \n"+
      "become a little more shallow, and to the south you see more land. \n" 
;
      
items = ({
  "ground","The earth below the water",
  "mud","A dark mud mixed bits of rotting vegetable matter",
  "water","Chest deep stagnant water that seems to be constantly swirling",
  "wood","Chunks of black wood that has floated up from the bottom of the swamp",
  "swamp","The stagnant mud and water you are standing in",
  "something","The bleached bones of some unlucky person",
  "tree","A crooked tree that looks as is it is grasping the bones entangled in its branches",
  "bones","These bones have been picked clean bye some scavenger the bleached white",
  "island","A small spot of mud protruding from the water",
  "branches","Thin twisted branches they almost look like they have joints in them",
  "land","You think you can see more stable land to the south of here", 
});

dest_dir = ({
  "/players/dusan/area1/rooms/swamp7.c","north",
  "/players/dusan/area1/rooms/swamp10.c","south",
});

}

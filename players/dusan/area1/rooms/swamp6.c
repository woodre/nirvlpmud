#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(!present("hatchling")){ 
     move_object(clone_object("/players/dusan/area1/mobs/vhatch.c"), this_object());}
if(!present("hatchling 2")){ 
     move_object(clone_object("/players/dusan/area1/mobs/vhatch.c"), this_object());}
if(!present("hatchling 3")){ 
     move_object(clone_object("/players/dusan/area1/mobs/vhatch.c"), this_object());}
 if(arg) return;
set_light(1);

short_desc = "Swamp.";
long_desc =
	"   The trees create a natural barrier to the east and a large pond  \n"+
      "to the south.  The ground here is ankle deep black mud.  Something \n"+
      "seems to have moved through here recently leaving a trail. To the \n"+
      "north the swamp opens up, and to the east you see a small pool. \n"
          ;
      
items = ({
  "trees","A tangle of trees and branches they look like skeletal hands",
  "vines","These vines grow in abundance here choking out the rest of the vegetation",
  "pond","A pond blocking your way to the south",
  "ground","The ground here is mostly a dark mud",
  "mud","A dark ankle deep mud.  There seems to be some tracks in it",
  "branches","A black tangled mass of branches",
  "barrier","A tangled mass of vines and branches block your way east",
  "tracks","Various unrecognizable tracks in the mud",
  "pool","A small pool to the east",
  "trail","A trail in the mud it seems to run into the pond to the south",
});

dest_dir = ({
  "/players/dusan/area1/rooms/swamp5.c","west",
  "/players/dusan/area1/rooms/swamp2.c","north",
});

}

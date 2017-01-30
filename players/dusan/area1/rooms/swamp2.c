#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Swamp";
long_desc =
	"   The trees and vines grow sparsely here.  The ground begins to \n"+
      "soften and there is a foul rotting odor.  To the north is the \n"+
      "entrance while the swamp gets deeper and darker to the east, \n"+
      "west, and south. \n"
           ;
      
items = ({
  "trees","The bare trees look like blackened skeletal hands",
  "vines","These vines grow in abundance here choking out the rest of the vegetation",
  "swamp","A dark and dank swamp with little vegetation." ,
  "vegetation","There is little vegetation here and what is here seems brown and wilted",
  "ground","A soft black mud covered in vines",
  "mud","Dark black mud"
});

dest_dir = ({
  "/players/dusan/area1/rooms/swamp6","south",
  "/players/dusan/area1/rooms/swamp3","west",
  "/players/dusan/area1/rooms/swamp4","east",
  "/players/dusan/area1/rooms/swamp1","north"
});

}

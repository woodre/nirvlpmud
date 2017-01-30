#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(!present("vraaak")){
     move_object(clone_object("/players/dusan/area1/mobs/vraaak.c"), this_object());}
  if(arg) return;
set_light(1);

short_desc = "Swamp";
long_desc =
	"   The trees and vines grow more thickly here as the ground begins to turn \n"+
      "to mud.  The rotting odor is much stronger.  Something rustles through \n"+
      "overgrowth and everything else is silent.  The swamp gets deeper to \n"+
      "the south and seems to get a little more shallow to the east. \n"
           ;
      
items = ({
  "trees","The bare trees look like blackened skeletal hands",
  "vines","These vines grow in abundance here choking out the rest of the vegetation",
  "swamp","A dark and dank swamp with little vegetation.",
  "vegetation","There is little vegetation here and what is here seems brown and wilted",
  "overgrowth","A tangle of vines and decaying weeds",
  "weeds","Dark wilted plants struggling through the vines"
});

dest_dir = ({
  "/players/dusan/area1/rooms/swamp5.c","south",
  "/players/dusan/area1/rooms/swamp2.c","east",
});

}

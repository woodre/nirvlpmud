#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "A entrance to a swampland.";
long_desc =
	"   This is the entrance to a dark and foreboding swamp. The \n"+
      "area ahead seems to darken, even though the trees and vines\n"+
      "in the area don't seem to give enough cover to block out the \n"+
      "sunlight.  The entire area seems to give off a foul odor. \n"+              	
      "The swamp continues to the south. \n"
      ;
      
items = ({
  "trees","The bare trees look like blackened skeletal hands",
  "vines","These vines grow in abundance here choking out the rest of the vegetation",
  "swamp","A dark marshy area south of here" ,
  "vegetation","There is little vegetation here and what is here seems brown and wilted",
  "sunlight","The sunlight is weak and barely seems to reach the ground",
  "ground","The ground is soggy and seems to get muddy to the south",
});

dest_dir = ({
  "/players/dusan/area1/rooms/swamp2.c","south",
 "room/south/sforst19","leave",
});

}

#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
 if(!present("skeleton")) {  
   move_object(clone_object("/players/dusan/area1/mobs/gskeleton.c"), this_object());}
 if(arg) return;
set_light(1);

short_desc = "Swamp";
long_desc =
	"   This clearing is dominated by a large boulder covered in a thick \n"+
      "black moss.  The moss cascades down the boulder and carpets the entire \n"+
      "clearing.  On the edges of the clearing the trees grow so thick that  \n"+
      "block any possible exit with the exception of back to the west.\n"
;
      
items = ({
  "ground","Dark rich earth covered almost completely in a black moss",
  "mud","The mud you have seen in the rest of the swamp is missing here",
  "trees","Twisted and gnarled trees that look like twisted skeletal hands",
  "swamp","The dark and dismal area you are in",
  "moss","A soft black substance that covers the ground",
  "vines","Strange thick black vines", 
  "boulder","A large boulder covered in black moss",
  "clearing","A clearing in the trees and vines",
});

dest_dir = ({
  "/players/dusan/area1/rooms/swamp15.c","west",
});

}

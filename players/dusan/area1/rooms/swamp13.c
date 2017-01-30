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

short_desc = "Swamp";
long_desc =
	"   A black mossy substance covers the ground here and there is an absence \n"+
      "of mud.  The trees seem to be even more tangled and knoted than in the \n"+
      "rest of the swamp.  They block your way completely to the east, and it \n"+
      "looks like they would make traveling to the north difficult at best.  To \n"+
      "the south the swamp seems to clear out a little, and to the west you see \n"+    
      "water.\n"
;
      
items = ({
  "ground","Dark rich earth covered almost completely in a mossy substance",
  "mud","The mud you have seen in the rest of the swamp is missing here",
  "water","Dark water to the west",
  "trees","Twisted and gnarled trees that look like twisted skeletal hands",
  "swamp","The dark and dismal area you are in",
  "substance","A black spongy substance the resembles moss",
  "moss","The black substance that covers the ground here looks like moss",
});

dest_dir = ({
  "/players/dusan/area1/rooms/swamp15.c","south",
  "/players/dusan/area1/rooms/swamp7.c","west",
  "/players/dusan/area1/rooms/swamp14.c","north",
});

}

#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Swamp";
long_desc =
	"   A burnt out campfire sits in the middle of this clearing.  The \n"+
      "black moss circles the fire and this seems like a good place to rest. \n"+
      "This seems to be some kind of sanctuary in the middle of the swamp. \n"+
      "It doesn't seem to have seen any recent use.  The only exit is back to \n"+
      "the south. \n"
;
      
items = ({
  "ground","Dark rich earth covered almost completely in a mossy substance",
  "mud","The mud you have seen in the rest of the swamp is missing here",
  "water","Dark water to the west",
  "trees","Twisted and gnarled trees that look like twisted skeletal hands",
  "swamp","The dark and dismal area you are in",
  "moss","A soft black substance that covers the ground",
  "campfire","A burnt out campfire in a circle of stones",
  "stones","Cracked, blackened stones",
  "sanctuary","The trees seem to make a natural screen hiding you from the denizens of the swamp",
  "screen","The trees block the approach of enemies from any direction",
  "clearing","A clearing in the trees",
});

dest_dir = ({
  "/players/dusan/area1/rooms/swamp13.c","south",
});

}

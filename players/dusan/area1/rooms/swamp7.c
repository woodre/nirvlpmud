#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
 if(!present("vraaak")) {
  move_object(clone_object("/players/dusan/area1/mobs/vraaak2.c"), this_object());} 
if(arg) return;
set_light(1);

short_desc = "Swamp";
long_desc =
	"   The water here is waist deep, stagnant, and a foul smell rises from \n"+
      "it. Something unidentifiable swims away when its hiding place is neared. \n"+
      "Bits of rotting wood, soggy bark, and decaying vegetable matter float \n"+
      "to surface of the water as the ground below is disturbed.  To the north \n"+
      "the water gets a little more shallow, to the east and south you see land.\n"     
;
      
items = ({
  "ground","The earth below the water",
  "mud","A dark mud mixed bits of rotting vegetable matter",
  "water","Waist deep stagnant water",
  "wood","Chunks of black wood that has floated up from the bottom of the swamp",
  "swamp","The stagnant mud and water you are standing in",
  "bark","Pieces of decaying bark",
  "matter","Random pieces of rotten leaves, stems, and branches",
  "leaves","Brown wilted leaves floating in the brackish water",
  "stems","Broken stems floating in the brackish water",
  "branches","Twisted and knobby branches floating in the water",
  "land","There seems to be more land to the south of here", 
});

dest_dir = ({
  "/players/dusan/area1/rooms/swamp9.c","south",
  "/players/dusan/area1/rooms/swamp13.c","east",
  "/players/dusan/area1/rooms/swamp4.c","north",
});

}

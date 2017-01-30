#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
if(!present("skeleton")) { 
  move_object(clone_object("/players/dusan/area1/mobs/skeleton1.c"), this_object());}
 if(arg) return;
set_light(1);

short_desc = "Swamp";
long_desc =
	"   The water is waist deep, stagnant, and a foul smell rises from it. \n"+
      "Something unidentifiable swims away when its hiding place is neared. \n"+
      "Bits of rotting wood, soggy bark, and decaying vegetable matter float \n"+
      "to the surface of the water as the ground below is disturbed.  To the \n"+
      "north the water gets a little more shallow, to the east, south and west \n"+    
      "the water becomes too deep to cross. \n" ;
      
items = ({
  "ground","The earth below the water",
  "mud","A dark mud mixed bits of rotting vegetable matter",
  "water","Waist deep stagnant water",
  "wood","Chunks of black wood that has floated up from the bottom of the swamp",
  "swamp","The stagnant mud and water you are standing in",
  "bark","Pieces of decaying bark",
  "matter","Random pieces of rotten leaves, plant stems, and branches",
});

dest_dir = ({
  "/players/dusan/area1/rooms/swamp5.c","north",
});

}

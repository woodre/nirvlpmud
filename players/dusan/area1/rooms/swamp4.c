#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
 if(!present("skeleton")){
  move_object(clone_object("/players/dusan/area1/mobs/skeleton2.c"), this_object());} 
 if(arg) return;
set_light(1);

short_desc = "Swamp";
long_desc =
	"   A large tree has fallen here, and seems to have been drug to the \n"+
      "ground by the huge mass of vines.  There is about a foot of brackish \n"+ 
      "water here.  The water gets deeper to the south and seems to get a \n"+ 
      "little more shallow to the west. \n"
           ;
      
items = ({
  "tree","An ancient tree lays on the ground covered bye large vines and mushrooms",
  "vines","These vines have caused the death of an ancient tree and seem to cover everything",
  "swamp","A dark and dank swamp with little vegetation." ,
  "vegetation","There is little vegetation here and what is here seems brown and wilted",
  "mushrooms","Flat orange and white mushrooms cover the fallen tree",
  "water","Stagnant brackish water that seems to have little things swimming in it",
  "things","tiny white worm-like things swimming in the water"
});

dest_dir = ({
  "/players/dusan/area1/rooms/swamp7.c","south",
  "/players/dusan/area1/rooms/swamp2.c","west"
});

}

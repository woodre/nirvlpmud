#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
if(!present("skeleton")){
  move_object(clone_object("/players/dusan/area1/mobs/vskltn.c"), this_object());}
  if(arg) return;
set_light(1);

short_desc = "Swamp";
long_desc =
	"   The muddy earth makes a bridge of sorts from the island of mud \n"+
      "to the east to the twisted roots of an ancient tree to the west. \n"+
      "What at first seemed to be a burrow is actually a natural shelter \n"+
      "made by the roots of the enormous tree.  To the north a small pond \n"+
      "blocks your way and to the south a large lake makes a natural barrier. \n"
   ;
      
items = ({
  "tree","A huge tree it's mass of roots make a natural shelter",
  "ground","The ground here is mostly a dark mud",
  "mud","A dark ankle deep mud there seems to be some tracks in it",
  "tracks","A track that resembles a tiny pair of shoe prints",
  "trail","A trail in the mud it seems to run into the burrow to the east",
  "burrow","What looked like a burrow is actually a hollow area shaped by the roots of an ancient tree",
  "lake","A rather large and deep lake of brackish water blocks your way to the south",
  "pond","A small but deep pond that blocks your way to the north",
  "roots","Black roots as thick as a mans leg",
  "shelter","A dark shelter made by the roots of an ancient tree",
  "earth","A dark muddy soil",
  "bridge","A natural bridge of mud seperating the pond and the lake",
  "island","An island of mud to the east",
});

dest_dir = ({
  "/players/dusan/area1/rooms/swamp12.c","west",
  "/players/dusan/area1/rooms/swamp10.c","east",
});

}

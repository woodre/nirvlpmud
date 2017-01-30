#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";
int t;
reset(int arg){
  if(!present("sign"))  {
move_object(clone_object("/players/daranath/qualtor/newstuff/obj/pawn_shop.c"),this_object());  }
  if(!present("trashcan")) {
move_object(clone_object("/players/pathfinder/trashcan.c"),this_object()); }
 if(!arg){

  set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(Pawn Shop)");
long_desc=
     "The small wooden building looks bigger from the inside then it did\n"+
     "from the street. Just north of the east road, many travellers come\n"+
     "here to pawn off excess items that they don't need. Many items\n"+
     "can be found for sale here.\n";

items=({
    "building","The small wooden building is neatly kept and clean",
 });

  dest_dir=({
     "/players/daranath/qualtor/east_road1.c","south",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
}

search() {
write("You find nothing of interest other then the items for sale.\n");
say (tp +" searches the area\n");
 return 1;  }


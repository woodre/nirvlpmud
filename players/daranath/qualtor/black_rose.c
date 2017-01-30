/* Black Rose Tavern in Qual'tor along the East Road.
   If Homer is not present (someone kills him) then players 
   are not able to order drinks. See black bar for more
   details. (/players/daranath/qualtor/obj/black_bar.c)
       -Daranath
*/
#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";
int t;
reset(int arg){
  if(!present("sign"))  {
move_object(clone_object("/players/daranath/qualtor/obj/black_bar.c"),this_object());   }
  if(!present("player"))  {
move_object(clone_object("/obj/go_player.c"),this_object());   }
  if(!present("homer")) {
move_object(clone_object("/players/daranath/qualtor/mon/homer.c"),this_object());  }
 if(!arg){

   set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(Black Rose Tavern)");
   long_desc=
     "A large hearth set in the western wall warms the Black Rose Tavern\n"+
     "no matter what time of year it is. The walls of the establishment\n"+
     "are a dark red color, giving the tavern its name. The same dark\n"+
     "wood forms a long bar along the far wall, a sign post behind it\n"+
     "listing the various beverages for sale.\n";

items=({
     "hearth","A large stone hearth warms the tavern",
     "wall","The dark red walls give the tavern a rosy atmosphere",
     "walls","The walls in the tavern are made of a dark red wood",
     "bar","The bar runs along the northern side of the tavern, several\n"+
           "barstools lined up in front of it. A large sign on the wall\n"+
           "lists stuff you can order here",
 });

  dest_dir=({
      "/players/daranath/qualtor/east_road2.c","south",
           });
} }

init() {
 ::init();
  add_action("search","search");
}

search() {
  write("You find nothing of interest about the Black Rose Tavern.\n");
  say(tp +" searches the area\n");
return 1;  }


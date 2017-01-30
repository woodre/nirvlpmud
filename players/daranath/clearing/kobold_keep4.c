inherit "room/room";
#include <ansi.h>
#define tp this_player()->query_name()

reset(arg){

    if(!arg){

    set_light(1);
short_desc= (BOLD+"DarkenWood"+NORM+" (Kobold Fortress)");
    long_desc=
  "Weapons, trophies and other such spoils of war line the walls within\n"+
  "this small area. Large wooden racks with glass doors proudly display\n"+
  "the most valuable of the items, including several human skulls which\n"+
  "are centered on one shelf. The majority of the weaponry and larger items\n"+
  "are secured to the walls themselves, keeping them safe from thievery.\n";

items=({
  "woods", "The Darkenwood is a place of horrors and humanoids, both of\n"+
           "which give it its reputation for nightmares.\n",
  "path", "The small path is your basic dirt trail, between two trees\n",
  "trees", "The overgrown trees block all light from coming in.\n",
  "shadows", "The shadows move as the wind moves the trees.\n",
  "floor", "The forest floor is covered with a thick layer of leaves and\n"+
           "other such debris",
 });


dest_dir=({
 "/players/daranath/clearing/kobold_keep1.c","east",
 "/players/daranath/clearing/kobold_keep5.c","south",
           });
        }
        }

init(){
  ::init();
  add_action("search","search");
}

search() {
write("You find nothing about the kobold fortress.\n");
say (tp +" searches the area.\n");
  return 1;
}


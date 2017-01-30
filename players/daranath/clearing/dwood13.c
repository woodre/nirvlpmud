inherit "room/room";
#include <ansi.h>
#define tp this_player()->query_name()

reset(arg){

    if(!arg){

    set_light(1);
short_desc= (BOLD+"DarkenWood"+NORM+" (Deep Forest)");
    long_desc=
  "Darkness overwhelms you as you walk about the evil forest known only as\n"+
  "the DarkenWood. No light enters through the canopy of trees overhead,\n"+
  "casting deep shadows all about the forest floor. The forest seems to\n"+
  "extend in all directions about you.\n";

items=({
  "woods", "The Darkenwood is a place of horrors and humanoids, both of\n"+
           "which give it its reputation for nightmares.\n",
  "trees", "The overgrown trees block all light from coming in.\n",
  "shadows", "The shadows move as the wind moves the trees.\n",
  "floor", "The forest floor is covered with a thick layer of leaves and\n"+
           "other such debris",
 });


dest_dir=({
 "/players/daranath/clearing/kobold2.c","north",
 "/players/daranath/clearing/dwood18.c","south",
 "/players/daranath/clearing/dwood12.c","east",
           });
        }
        }

init(){
  ::init();
  add_action("search","search");
}

search() {
write("You find nothing about the DarkenWood.\n");
say (tp +" searches the area.\n");
  return 1;
}


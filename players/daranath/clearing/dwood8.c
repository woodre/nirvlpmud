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
  "extend in all directions about you.\n"+
  "A large signpost sticks from the ground here.\n";

items=({
  "signpost","The post has several directional arrows pointing in a variety of\n"+
  "directions. They include:\n\n"+
  "North --->> City of Qual'tor\n"+
  "South --->> Magus Tower\n"+
  "East --->> Forest Clearing\n"+
  "West --->> Kobold Village\n\n"+
  "A smaller sign seems to have broken off the post",
  "woods", "The Darkenwood is a place of horrors and humanoids, both of\n"+
           "which give it its reputation for nightmares.\n",
  "trees", "The overgrown trees block all light from coming in.\n",
  "shadows", "The shadows move as the wind moves the trees.\n",
  "floor", "The forest floor is covered with a thick layer of leaves and\n"+
           "other such debris",
  "sign","Try looking at the signpost",
  "post","Try looking at the signpost",
 });


dest_dir=({
 "/players/daranath/clearing/dwood9.c","north",
 "/players/daranath/clearing/dwood7.c","south",
 "/players/daranath/clearing/dwood5.c","east",
 "/players/daranath/clearing/kobold1.c","west",
           });
        }
        }

init(){
  ::init();
  add_action("search","search");
}

search() {
write("You find a small piece of the broken sign that reads:\n"+
      "\n          A warning to all who...\n\n"+
      "The rest of the sign has worn away over time.\n");
say (tp +" searches the area.\n");
  return 1;
}


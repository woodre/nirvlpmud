#include <ansi.h>
#define tp this_player()->query_name()
inherit "room/room";

reset(arg){

    if(!arg){

    set_light(-1);
    short_desc="Dark Forest Cave";
    long_desc=
  "The rear wall of the dark cavern rises to block any further travel to\n"+
  "the north, while the spirits of the forest cry out in anguish from the\n"+
  "the south. A small crack extends upward from the floor of the cave along\n"+
  "the rear wall. Nothing else of note exists within the cavern.\n";

items=({
"wall", "The wall in the rear of the cave looks broken in one place",
"cavern", "The small cavern is within the forest of spirits",
"spirits", "The spirits of the forest cry out for vengance",
"forest", "The darkened forest is an evil place, full of spirits and other\n"+
          "such tortured souls",
"crack", "The crack looks as if it was torn from the wall starting at\n"+
         "its foundation and working torwards the ceiling. The darkness\n"+
         "prevents you from seeing anything within. Perhaps you could\n"+
         " "+BOLD+"<"+NORM+"enter"+BOLD+">"+NORM+" the crack itself",
 });


dest_dir=({
 "/players/daranath/underdark/level2/forest_cave1.c","south",
           });
        }
        }
init(){
  ::init();
  add_action("enter","enter");
  add_action("search","search");
}

enter() {
write("You manage to work your way into the opening on the wall.\n");
this_player()->move_player("disappears into the darkness of the opening#/players/daranath/underdark/level2/forest_entry1.c");
  return 1;
}

search() {
write("You find nothing of interest other than the crack in the wall.\n");
say (tp +"searches the area.\n");
  return 1;
}

arate() { return "YES"; }

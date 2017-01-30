#include <ansi.h>
#define tp this_player()->query_name()
inherit "room/room";

reset(arg){

    if(!arg){

    set_light(-1);
    short_desc="Dark Tunnel";
    long_desc=
  "Descending into the darkness, a natural tunnel leads from here down\n"+
  "into the unknown. Years of dust and debris lead you to believe the\n"+
  "tunnel has not been used much since breaking into the forest cave.\n"+
  "The passage is made of the same deep grey stone as the cavern.\n";

items=({
"walls", "The dark grey colored stone enhances the sense of danger here\n",
"darkness", "The darkness presses in all about you, leaving you with an\n"+
            "isolated feeling",
"shadows", "The shadows shift and move with the swaying of the trees\n",
"stone", "The dark grey stone of the walls is natural to this area",
"dirt", "Dirt covers the flooring here, leaving you footprints all about",
 });


dest_dir=({
 "/players/daranath/underdark/level2/forest_entry2.c","down",
 "/players/daranath/underdark/level2/forest_cave2.c","exit",
           });
        }
        }
init(){
  ::init();
  add_action("search","search");
}

search() {
write("The tunnel is barren of any items of interest.\n");
say (tp +"searches the area.\n");
  return 1;
}

arate() { "YES"; }

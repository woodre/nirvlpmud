#include <ansi.h>
#define tp this_player()->query_name()
inherit "room/room";

reset(arg){

    if(!arg){

    set_light(1);
    short_desc="Tunnel within the UnderDark";
    long_desc=
  "Light tears its way through the darkness within the tunnel here, as\n"+
  "a torch burns brightly while it is mounted upon the wall. The descending\n"+
  "tunnel levels off here, and heads to the northwest. The twisting and\n"+
  "turning of the UnderDark lays before you.\n";

items=({
"walls", "The dark grey colored stone enhances the sense of danger here\n",
"darkness", "The darkness presses in all about you, leaving you with an\n"+
            "isolated feeling",
"stone", "The dark grey stone of the walls is natural to this area",
"torch", "The torch is burning brightly within an iron sconce",
"dirt", "Dirt covers the flooring here, leaving your footprints all about",
 });


dest_dir=({
 "/players/daranath/underdark/level2/forest_entry3.c","up",
 "/players/daranath/underdark/level2/p31.c","northwest",
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

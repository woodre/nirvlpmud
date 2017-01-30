#include <ansi.h>
#define tp this_player()->query_name()
inherit "room/room";

reset(arg){

    if(!arg){

    set_light(-1);
    short_desc="Bottom of the Well";
    long_desc=
 "The stone grey well opens into a small chamber, with the same grey\n"+
 "granite making up its circular walls. The sparse light from atop the\n"+
 "well illuminates the dirty chamber, although the shadows run deep.\n"+
 "Tunnels run from the chamber in several directions.\n";

items=({
 "walls", "The dark grey colored stone enhance the sense of danger here\n",
 "well", "The well is made of the same dark grey stone as the walls of\n"+
         "the cave. The top of the well is barely visible, leading up\n"+
         "back into the Darkenwood.\n"+
         "Perhaps you could "+YEL+"<"+NORM+" climb "+YEL+">"+NORM+" up it",
 "shadows", "The shadows run deep in this area, causing your eyes to play\n"+
            "tricks with your mind",
 "tunnels", "Dark tunnels lead off into the darkness",
 "granite", "The granite the walls are made of is natural to this area",
 "chamber", "The chamber is circular and made of dark grey stone walls,\n"+
            "three exits lead from this room: north, south and west",
 });


dest_dir=({
 "/players/daranath/underdark/level1/g,11.c","north",
 "/players/daranath/underdark/level1/i,11.c","south",
 "/players/daranath/underdark/level1/h,10.c","west",
           });
        }
        }
init(){
 ::init();
  add_action("search","search");
  add_action("climb","climb");
}

search() {
write("You find nothing amidst the dirt.\n");
say (tp +"searches the area\n");
  return 1; }

climb() {
write("You climb back torwards the surface world.\n");
  this_player()->move_player("back up into the well#/players/daranath/clearing/cave2.c");
  return 1;
}

arate()  { return "YES"; }

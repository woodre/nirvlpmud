#include <ansi.h>
#define tp this_player()->query_name()
inherit "room/room";

reset(arg){

    if(!arg){

    set_light(-1);
    short_desc="Dark Forest Cave";
    long_desc=
  "Darkness presses all about you as you move about the inky blackness of\n"+
  "the forest cave. Dark grey stone walls enclose the cave and keep the\n"+
  "light out, leaving only the exit to the south. A thick layer of dirt\n"+
  "covers the rough flooring here, jagged steps and pieces of rock jut\n"+
  "about the surface of the stone. The darkness continues to the north of\n"+
  "here.\n";

items=({
"walls", "The dark grey colored stone enhances the sense of danger here\n",
"darkness", "The darkness presses in all about you, leaving you with an\n"+
            "isolated feeling",
"cave", "The forest cave is naturally formed, standing here about the ages",
"shadows", "The shadows shift and move with the swaying of the trees\n",
"stone", "The dark grey stone of the walls is natural to this area",
"light", "What little light filters in from the forest dimly illuminates\n"+
         "the cave entrance",
"exit", "The cave entrance exits out into the forest of spirits",
"dirt", "Dirt covers the flooring here, leaving you footprints all about",
"steps", "Broken steps make up the uneven flooring about the area",
 });


dest_dir=({
 "/players/daranath/underdark/level2/forest_cave2.c","north",
 "/players/mythos/aroom/forest/forestc.c","out",
           });
        }
        }
init(){
  ::init();
  add_action("search","search");
}

search() {
write("You find nothing about the darkness of the forest cave.\n");
say (tp +"searches the area.\n");
  return 1;
}

arate() { return "YES"; }

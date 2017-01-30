#include <ansi.h>
#define tp this_player()->query_name()
inherit "room/room";

reset(arg){

    if(!arg){

    set_light(-1);
    short_desc="Marble Hallway into Darkness";
    long_desc=
 "The white marble stands out in strong contrast to everything else you\n"+
 "have seen here within the UnderDark. Clean white walls and ceiling are\n"+
 "all about you. The floor here is quite dirty, tracks draging filth and\n"+
 "grime all over the white flooring. An iron stairwell is to the northern\n"+
 "end of this hall, leading down from here.\n";

items=({
 "walls", "The white marble of the walls is kept neat and clean by\n"+
          "something in this area",
 "ceiling", "The marble tiles in the ceiling must weigh tons!!!",
 "stairwell", "The iron stairwell leads down from here, where it\n"+
              "goes is still unknown. The dirt seems to be tracked\n"+
              "up from down there.\n"+
         "Perhaps you could "+YEL+"<"+NORM+" climb "+YEL+">"+NORM+" down",
 });


dest_dir=({
 "/players/daranath/underdark/level1/b,11.c","south",
           });
        }
        }
init(){
 ::init();
  add_action("search","search");
  add_action("climb","climb");
}

search() {
write("You find something in the corner.\n");
move_object(clone_object("/players/daranath/items/rag.c"),this_object());
say (tp +"searches the area\n");
  return 1; }

climb() {
write("You descend the stairwell down into the unknown.\n");
  this_player()->move_player("down the stairwell#/players/daranath/underdark/crypt/entry.c");
  return 1;
}

arate() { return "YES"; }

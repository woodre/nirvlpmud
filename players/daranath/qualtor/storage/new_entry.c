#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
inherit "room/room";
#include <ansi.h>

reset(int arg){
if(!present("machine")) {
move_object(clone_object("/players/daranath/qualtor/newstuff/temp_vend.c"),this_object());
}
if(!present("board")) {
move_object(clone_object("/players/daranath/qualtor/obj/bull_board.c"),this_object());
}
/*
 if(!present("herald")) {
move_object(clone_object(ROOT+"mon/herald.c"),this_object());
}
*/

 if(!arg){

  set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(Central Plaza)");
  long_desc=
/*
"               "+BOLD+"Old Road"+NORM+" (north)\n"+
"               "+BOLD+"East Road"+NORM+" (east)\n"+
"               "+BOLD+"Tiger Lane"+NORM+" (west)\n"+
*/
    "Crumbled buildings stand within the remains of the outer wall that once\n"+
    "protected the city of Qual'tor. Several rubble strewn roads lead from\n"+
    "the area to the north, east and west. A tower to the far north still\n"+
    "stands tall amidst the ruins, while another rises to the west, its\n"+
    "upper levels have long since collapsed in upon itself.\n";

items=({
 });

  dest_dir=({
/*
   "/players/daranath/qualtor/old_road1.c","north",
*/
   "/players/daranath/qualtor/wayin2.c","south",
   "/players/daranath/qualtor/necro_path6.c","east",
/*
   "/players/daranath/qualtor/merch_way.c","west",
*/
           });
  }   }
init(){
 ::init();
add_action("search","search");
add_action("herald_ask","ask");
add_action("herald_info","info");
add_action("herald_story","story");
add_action("herald_advice","suggest");
add_action("herald_map","map");
}

search() {
write("Blackened bits of stone and crumbling pieces of marble lie all\n"+
      "about the area, none of which are worth any value\n");
say (tp +" searches the area\n");
 return 1;  }


#define tp this_player()->query_name()
inherit "room/room";
#include <ansi.h>
#include "/players/saber/closed/esc.h"
int t;
reset(int arg){
 if(!arg){
  set_light(1);
  short_desc="Swamp entry";
long_desc=
  "You stand knee deep in the thick, soupy muck that is the\n"+
        "Dark Myre.  All about you stand trees covered in vines, giving\n"+
        "them a look of helpless possession.  Foreign sounds echo throughout\n"+
        "the trees, enhancing the feel of despair rippling up and down your spine.\n"+
        "A "+HIR+"Warning Sign"+NORM+" stands here.\n";

items=({
 "sign","The sign reads:\n"+
        "Welcome to the Dark Myre.  This area is intended for\n"+
        "adventurors who think they can take care of themselves.\n"+
        "If you are below level 12, get out quickly!\n"+
        "You have been warned....   -Dar",
 "myre","Yes, you are in the Dark Myra",
 });

  dest_dir=({
 "/players/daranath/dar/rooms/swamp4.c","north",
 "/players/daranath/dar/rooms/swamp2.c","south",
 "/players/daranath/dar/rooms/swamp3.c","west",
 "/players/saber/tower/tower21.c","portal",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
}

search() {
write("You find nothing but filth.\n");
say (tp +" searches the area\n");
 return 1;  }

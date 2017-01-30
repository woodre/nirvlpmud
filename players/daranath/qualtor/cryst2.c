#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/"
#include <ansi.h>
inherit "room/room";
int a, b;

reset(int arg){
a = random(3);
b = random(3);
if(a < 2){
  if(!present("elemental")) {
move_object(clone_object(ROOT+"mon/cryst_ele.c"),this_object()); }
}
if(b < 2){
move_object(clone_object(ROOT+"mon/drifter.c"),this_object());
}
  if(!arg){

    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+WHT+"Crystalline Tower"+NORM+")");
    long_desc=
     "A curve in the stone hallway bends both east and south. The\n"+
     "eastern passage runs back torwards the entry stairwell, while\n"+
     "the southern hall heads into darkness.\n"+
    ""; /* line "A small chamber is brilliantly lit just to the north.\n"; deleted by wocket. */

    items=({
     "chamber","The chamber to the north of here is brilliantly lit\n"+
               "by a variety of colors. It clearly stands out from\n"+
               "The rest of this hallway",
     "hallway","The hall is made from a dark grey stone",
     "passage","The passage to the east runs back to the stairs",
     "darkness","Who knows what the darkness may hold???",
    });

    dest_dir=({
/* room does not exist.. removed by wocket
      "/players/daranath/qualtor/cryst3.c","north",
*/
      "/players/daranath/qualtor/cryst4.c","south",
      "/players/daranath/qualtor/cryst1.c","east",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("You find nothing of interest with the ruins of the crystal tower.\n");
    say(tp +" searches the area.\n");
     return 1;
    }



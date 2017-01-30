#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>
inherit "room/room";
int a;

reset(int arg){
a = random(2);
if(a == 0) {
  if(!present("undead")) {
move_object(clone_object(ROOT+"mon/gloom2.c"),this_object());
  }
}
  if(!arg){

    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+WHT+"Crystalline Tower"+NORM+")");
    long_desc=
     "The rubble filled stairwell empties out into a strikingly plain\n"+
     "stone hallway running south from here. During Qual'tor's glory, \n"+
     "anyone could stand here and see Circle members running back and\n"+
     "forth, striving to keep the city operating smoothly.\n";

    items=({
     "stairwell","The stairs are made from a dark grey stone",
     "darkness","The darkness hides many critters and rodents from view",
     "stairs","The stairs are made from a dark grey stone",
     "shards","The broken shards of crystal are all that remains of the tower above",
     "rubble","The rubble is mostly crystal from the tower's destruction",
     "hallway","The hall is almost out of place here, not what you had\n"+
               "expected from the tower at all",
    });

    dest_dir=({
      "/players/daranath/qualtor/cryst_stairs.c","up",
      "/players/daranath/qualtor/cryst1.c","south",
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



#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
/*
if(!present("boneportal")) {
move_object(clone_object("/players/daranath/guild/obj/misc/portal.c"),this_object());
}
*/
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(City Ward)");
    long_desc=
"               "+BOLD+"Old Road"+NORM+" (north, south)\n"+
"The most ancient of Qual'tors many walkways and roads, Old Road\n"+
"extends from the southern gates to the ruined crystalline tower\n"+
"at the northern end of the city. Old buildings on both sides of the \n"+
"roadway have been pulled down to make room for new structures to come.\n";

    items=({
"road","Old road is made from stone and gravel",
"tower","The crystalline tower far to the north has fallen into ruin,\n"+
     "a pile of crystal shards amidst Ghost Ward",
"building","Buildings on both sides of the road are being rebuilt",
"buildings","Buildings on both sides of the road are being rebuilt",
    });

    dest_dir=({
      "/players/daranath/qualtor/old_road2.c","north",
      "/players/daranath/qualtor/newstuff/new_entry.c","south",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
write("New construction has taken away anything worth searching for on the road.\n");
    say(tp +" searches the area.\n");
     return 1;
    }



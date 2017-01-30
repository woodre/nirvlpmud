#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
move_object(clone_object("/players/daranath/qualtor/mon/ratling.c"),this_object());
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(City Stables)");
    long_desc=
     "The North Road Stables end here, a wooden area used for storing\n"+
     "the hay and other various supplies for use about the stables.\n"+
     "The only exit from the room is to the south, back into the\n"+
     "center of the stables.\n";

    items=({
     "statue","The large statue shows a gruesome scene of a group of gaurdsmen from\n"+
              "the city fought against many orcs, goblins, and ogres\n"+
              "while defending the city. It is quite impressive",
     "walkway","The walkway is made of stone and gravel",
    });

    dest_dir=({
      "/players/daranath/qualtor/stable3.c","south",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("Hay and straw is tracked from the stables by horses that leave.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


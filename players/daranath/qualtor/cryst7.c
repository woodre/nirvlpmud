#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
move_object(clone_object("/players/daranath/qualtor/mon/ghost_ar.c"),this_object());
  if(!arg){

    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+WHT+"Crystalline Tower"+NORM+")");
    long_desc=
     "Ariel Brightshield made her private quarters here, staying underneath\n"+
     "the crystal tower as only the Avatar of each sect could. Ariel\n"+
     "herself lived extremly simply, not having much within her\n"+
     "private quarters.\n";

    items=({
     "stone","The stone is dark grey in color",
     "rock","The rock is dark grey in color",
    });

    dest_dir=({
      "/players/daranath/qualtor/cryst5.c","south",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("The Avatar that lived here did not much, and what she did have\n"+
          "has long since been stolen. Nothing is left of value.\n");
    say(tp +" searches the area.\n");
     return 1;
    }



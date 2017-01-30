#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
move_object(clone_object("/players/daranath/qualtor/mon/ghost_dr.c"),this_object());
  if(!arg){

    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+WHT+"Crystalline Tower"+NORM+")");
    long_desc=
     "Draggonar made his private quarters here, staying underneath the\n"+
     "crystal tower as only the Avatar of each sect could. Draggonar\n"+
     "himself was an evil man, enslaving victims here against despite\n"+
     "thier strongest pleas. Dragonnar and Ariel would continously argue\n"+
     "about the screams coming from this chamber, but Ariel could do\n"+
     "nothing about it, as written in the code of the Circle.\n";

    items=({
     "stone","The stone is dark grey in color",
     "rock","The rock is dark grey in color",
    });

    dest_dir=({
      "/players/daranath/qualtor/cryst6.c","south",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("The Avatar that lived here did not much, and what he did have\n"+
          "has long since been stolen. Nothing is left of value.\n");
    say(tp +" searches the area.\n");
     return 1;
    }



#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
move_object(clone_object("/players/daranath/qualtor/mon/ghost_dw.c"),this_object());
  if(!arg){

    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+WHT+"Crystalline Prison"+NORM+")");
    long_desc=
     "The darkened chamber acts as a prison cell here within the Crystalline\n"+
     "tower, although no one has used the tower for many years. Nothing\n"+
     "remains within the room, save for a small chair set against the\n"+
     "far wall. The only exit is back to the guard post.\n";

    items=({
     "chair","A small wooden chair has sat here for thirty plus years",
     "chamber","The stone walls press in upon you in the cell",
     "stone","The walls are made of a dark grey stone",
     "walls","The walls are made of a strong grey stone",
    });

    dest_dir=({
      "/players/daranath/qualtor/cryst11.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("Nothing save the chair is here within the prison cell,\n"+
          "and you do not want to take that.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


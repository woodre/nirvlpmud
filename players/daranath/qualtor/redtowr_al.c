#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
move_object(clone_object("/players/daranath/qualtor/mon/alchemist.c"),this_object());
  if(!arg){

    set_light(1);
short_desc= (BOLD+BLK+"City of Qual'tor "+NORM+"("+RED+"RedTower"+NORM+")");
    long_desc=
     "Broken glass and shattered glass are scattered all about the\n"+
     "room, reminders of better times long ago. A lab table lies on\n"+
     "its side against the far wall, broken beakers and flasks piled\n"+
     "along the floor. Maps and diagrams of the human anatomy line the\n"+
     "walls, giving an erie feel to a very disturbed room.\n";

    items=({
     "crystal","The crystal glows with a redish internal fire",
    });

    dest_dir=({
      "/players/daranath/qualtor/redtowr8.c","out",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("It is dangerous to go poking around in this room.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

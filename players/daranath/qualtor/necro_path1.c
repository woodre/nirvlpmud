#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+BLK+BOLD+"Dark Graveyard"+NORM+")");
    long_desc=
     "Just to the eastern side of the protective wall surrounding the\n"+
     "ruined keep within Qual'tor, a small area opens up to the\n"+
     "east from here, a pathway leading into darkness.\n";

    items=({
     "wall","The stone wall stands in pieces about the keep",
     "pathway","The pathway leads around the southern side of the keep",
     "darkness","OOoooo....  darkness",
     "area","The small area was part of a courtyard of sorts",
     "keep","The blackened and burnt keep is a reminder of the former\n"+
            "glory of Qual'tor",
    });

    dest_dir=({
      "/players/daranath/qualtor/necro_path2.c","east",
      "/players/daranath/qualtor/old_road3.c","leave",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("A quick search of the East Road brings nothing of value.\n");
    say(tp +" searches the area.\n");
     return 1;
    }



#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
/*
move_object(clone_object("/players/daranath/qualtor/mon/dark_st.c"),this_object());
*/
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(City Ward)");
    long_desc=
"               "+BOLD+"Coin Alley"+NORM+" (east)\n"+
     "Coin alley once got its nickname from the black market within the\n"+
     "city. The market thrived here, giving the alley a reputation for\n"+
     "being able to get you whatever it was that you needed within\n"+
     "reason, as well as depriving you of your coins. The alley's only\n"+
     "exit is to the east and back to Shield street.\n";

    items=({
     "alley","The dark alley is perfect for jumping people",
    });

    dest_dir=({
      "/players/daranath/qualtor/shield_st2.c","east",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("You find nothing of interest within Coin Alley.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


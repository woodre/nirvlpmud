#include <ansi.h>
#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
if(!present("person"))
move_object(clone_object("/players/daranath/qualtor/mon/sh_master.c"),this_object());
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(City Ward)");
    long_desc=
"               "+BOLD+"Dagger Alley"+NORM+" (east, west)\n"+
"Dagger Alley is severly run down and rubble filled, making the\n"+
"narrow alley even smaller. A pair of blackened buildings line\n"+
"the sides of the alley. The building to the north used to the\n"+
"the market within Qual'tor, while the southern building looks\n"+
"as if it has had some repairs recently.\n";

    items=({
"building","The stone building to the south looks as if it has been taken\n"+
     "care of recently",
"stone","The stone from the building has been kept clean",
"alley","The dark alley is perfect for jumping people",
"shadows","The dark shadows can hide many things from view",
    });

    dest_dir=({
  "/players/daranath/qualtor/shield_st3.c","east",
  "/players/daranath/qualtor/grif_flight3.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
write("Footprints run all over Dagger Alley.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
/*
move_object(clone_object("/players/daranath/qualtor/mon/drifter.c"),this_object());
*/
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(City Ward)");
    long_desc=
"               "+BOLD+"Shield Street"+NORM+" (north, south)\n"+
"Personal homes and small villas are being built here, along the northern\n"+
"edge of the newly dubbed 'City Ward'. The city itself looks alive once\n"+
"again as you walk along Shield Street, just along the eastern edge\n"+
"of Qual'tor itself. The roadway continues north and south.\n";

    items=({
     "villa","The personal villas are long since abandoned",
     "villas","The personal villas are long since abandoned",
     "street","Shield street is made of a dark grey gravel",
     "building","Empty buildings line the street",
     "buildings","Empty buildings line the street",
     "road","North road is just north of your location",
    });

    dest_dir=({
      "/players/daranath/qualtor/nor_road5.c","north",
      "/players/daranath/qualtor/shield_st3.c","south",
/*
      "/players/daranath/qualtor/mansion/lot4.c","east",
*/
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("A quick search of Shield street reveals nothing.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


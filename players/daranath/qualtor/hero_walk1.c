#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/"
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(City Ward)");
    long_desc=
"               "+BOLD+"Heroes Walk"+NORM+" (east, west)\n"+
"Once a symbol of everything grand about the City of Qualtor, Heroes\n"+
"Walkway was once of the first streets to get reburbished in City Ward.\n"+
"Tall poles on either side of the small walkway stand anew, ready for\n"+
"the individual banners and standards of the new heroes of the city.\n"+
"The entrance to a small garden can be seen to the east.\n";

    items=({
"poles","Tall poles are to be used to hang the standards of the city's heroes",
"banners","The banners are not yet in place",
"pole","Each pole will someday house a standard of an individual hero",
"walkway","The small walkway has been cleared of debris and rubbish",
"standard","The standards will hang along both sides of the walkway",
    });

    dest_dir=({
ROOT+"hero_walk2.c","east",
ROOT+"old_road2.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("You find a tattered piece of colorful cloth.\n");
    say(tp +" searches the area.\n");
     return 1;
    }



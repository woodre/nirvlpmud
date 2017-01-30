#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+HIR+"Historian"+NORM+")");
    long_desc=
     "You stand within the skeletal remains of the historian's dwelling\n"+
     "here in Qual'tor. The Historian kept track of the passage of time\n"+
     "before the troubles forced him to leave his work and home behind.\n"+
     "The great firestorm that ravaged Qual'tor did a considerable amount\n"+
     "of damage here, expect for a small room that sits to the south\n"+
     "from here, it seems as if the fire chose to spare it.\n";

    items=({
     "room","The small room just to the south sits as it did many\n"+
            "years ago, fire and time having no effect on it",
     "dwelling","The burnt out remains of the historian's home",
     "building","The blackened building was destroyed by fire",
    });

    dest_dir=({
      "/players/daranath/qualtor/east_road2.c","north",
      "/players/daranath/guild/room/join_up.c","south",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    add_action("dar_south","south");
    }

    search(){
    write("An extensive search brings nothing but blackened, charred books\n"+
          "and other fire damaged items of no value. The room to the south\n"+
          "is in perfect condition, as if the fire never touched it.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

    dar_south() {
    write("I'm afraid the historian is not in right now...\n"+
          "please try again later...\n");
    say(tp +" looks confused for a second.\n");
    return 1;
    }

#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
/*
if(!present("guard")){
move_object(clone_object("/players/daranath/qualtor/folk/tguard1.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/folk/chld_light.c"),this_object());
}
*/
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(City Ward)");
    long_desc=
"               "+BOLD+"Children's Pathway"+NORM+" (north)\n"+
"               "+BOLD+"Tiger Lane"+NORM+" (east)\n"+
"               "+BOLD+"Wizard's Walkway"+NORM+" (west)\n"+
"Standing in the far southwestern corner of Qual'tor, much of the destruction\n"+
"that befell the city has been repaired here. Buildings and small houses\n"+
"are under construction everywhere, as Qual'tors citizens are making\n"+
"an attempt to reclaim thier home.\n";

    items=({
"corner","You stand at the corner of Tiger Lane and Children's Pathway",
"destruction","The ruins of the city are slowly being repaired, at least\n"+
     "here within City Ward",
"city","You are within the city of Qual'tor",
"building","Several large buildings are being constructed nearby",
"buildings","Several large buildings are being constructed nearby",
"houses","Citizens are moving back into the city, so a variety of new\n"+
     "homes are being built",
"homes","Citizens are moving back into the city, so a variety of new\n"+
     "homes are being built",
"home","Many people claim Qual'tor to be thier home",
    });

    dest_dir=({
      "/players/daranath/qualtor/child_path2.c","north",
      "/players/daranath/qualtor/merch_way.c","east",
  "/players/daranath/qualtor/newstuff/mage_walk1.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
write("Nothing of interested is found within the intersection.\n");
    say(tp +" searches the area.\n");
     return 1;
    }



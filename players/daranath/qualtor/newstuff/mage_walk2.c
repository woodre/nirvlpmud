#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>

inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(City Ward)");
    long_desc=
"               "+BOLD+"Wizard's Walkway"+NORM+" (east)\n"+
"The short roadway ends here, at the construction site of a large tower that\n"+
"is being raised. A small stone wall has been built to keep out curious \n"+
"individuals, while a small sign on the wall gives more information.\n"+
"Currently, the only exit is back east torwards Qual'tor\n";

    items=({
"roadway","The short road ends here, heading back into the city",
"site","This construction site just recently started",
"tower","A large stone and wood tower is being built here, although its\n"+
     "purpose has yet to be revealed",
"individuals","You are curious, aren't you..",
"sign","The small sign reads:\n\n"+
     "Future home of something you will all be interested in,\n"+
     "I promise ...   -Dar\n\n"+
     "There was further writing, but it has been rendered illegible",
"wall","The small stone wall protects the construction site",
"stone","The small stone wall protects the construction site",
    });

    dest_dir=({
ROOT+"mage_walk1.c","east",
/* Enter will take place into Mal's good mage tower, when its ready */
ROOT+"unknown.c","enter",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
add_action("dar_enter","enter");
    }

search() {
  write("Bits of wood and lots of sawdust can be found around this area.\n");
  say(tp +" searches the area.\n");
return 1;
}

dar_enter() {
write("Coming soon...\n    -Dar\n");
return 1;
}


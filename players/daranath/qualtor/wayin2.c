#define ROOT "/players/daranath/qualtor/newstuff/"
#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!arg){
/*
if(!present("portal")){
move_object(clone_object(ROOT+"obj/exit_portal.c"),this_object());
}
*/
    
    set_light(1);
short_desc= (BOLD+BLK+"City of Qual'tor"+NORM+" (Southern Entrance)");
    long_desc=
"A short valley runs between the path leading to the mountain and\n"+
"the majestic city of Qual'tor. The city itself looks to have been\n"+
"heavily rebuilt, except for a portion in the northwestern corner.\n"+
"A newly built sign sticks from the ground here.\n";

    items=({
     "sign","    The sign reads\n\n"+
"     "+BOLD+"Welcome to the City of Qual'tor!"+NORM+"\n"+
"Our city lies just to the north of here, feel free to visit.\n"+
"City Ward holds many of the rebuilt areas, including the new\n"+
"     marketplace and various shops within\n"+
"Ghost Ward and Arena Ward are dangerous areas, STAY OUT!\n"+
"\n     -The Citizens of Qual'tor",
     "       -The Citizens of Qual'tor",
      "mountain", "Dark clouds surround the mountain peak, making you\n"+
                  "wonder if it is neccessary to traverse the rocky\n"+
                  "trails leading north",
      "clouds", "The dark clouds are very angry in nature",
      "pathway","The pathway leads east into a swampy area for newbies",
      "lightning", "Flashed of blue and bright yellow energy cross the\n"+
                   "dark clouds in an agressive manner",
      "valley","The valley extends from the path leading to the mountain\n"+
               "to a large clearing just northeast of here",
      "ruins","The ruined city looks as if a large battle destroyed\n"+
              "what it had for a wall and defenses",
    });

    dest_dir=({
"/players/daranath/qualtor/newstuff/new_entry.c","north",
      "/players/daranath/qualtor/hilltop.c","south",
      "/players/daranath/qualtor/wayin1.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
     add_action("listen","listen");
    }

    search(){
    write("Blackened bits and pieces of rubble are all about the area.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

    listen(){
    write("Sounds of construction fill the area, making conversation difficult.\n");
    say(tp +" concentrates for a moment.\n");
     return 1;
}

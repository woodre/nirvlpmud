#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!arg){
move_object(clone_object("/players/daranath/mons/beetle_fire.c"),this_object());
move_object(clone_object("/players/daranath/mons/beetle_iron.c"),this_object());
move_object(clone_object("/players/daranath/mons/beetle_iron.c"),this_object());
    
    set_light(1);
short_desc= (BOLD+BLK+"City of Qual'tor"+NORM+" (Northern Realms)");
    long_desc=
      "The trail encircling the mountain ends here at a solid wall of\n"+
      "stone. The area is rubble strewn and unkempt. The trail leads\n"+
      "back to the west, torwards the crossroads.\n";

    items=({
      "range", "High mountains and rocky slopes make up the majority of\n"+
               "the mountains",
      "clouds", "The dark clouds are very angry in nature",
      "lightning", "Flashed of blue and bright yellow energy cross the\n"+
                   "dark clouds in an agressive manner",
      "peak", "The mountain's peak is surrounded by the dark clouds",
      "rubble", "The rubble makes you think that a landslide has\n"+
                "happened recently within this area",
      "stone", "The wall of stone blocks any further passage here",
    });

    dest_dir=({
      "/players/daranath/clearing/mtrail7.c","west",
      "/players/daranath/clearing/mtrail9.c","east",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("You find nothing along the trail encircling the mountain.\n");
    say(tp +" searches the area.\n");
     return 1;
    }



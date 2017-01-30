#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>
inherit "room/room";

reset(int arg){
if(!present("rubble")) {
move_object(clone_object(ROOT+"obj/rubble.c"),this_object());
}
  if(!arg){
    
    set_light(1);
short_desc= (BOLD+BLK+"City of Qual'tor"+NORM+" (Northern Realms)");
    long_desc=
      "The trail encircling the mountain ends here at a solid wall of\n"+
      "stone. The area is rubble strewn and unkempt. The trail leads\n"+
      "back to the east, torwards the crossroads.\n";

    items=({
      "range", "High mountains and rocky slopes make up the majority of\n"+
               "the mountains",
      "clouds", "The dark clouds are very angry in nature",
      "lightning", "Flashed of blue and bright yellow energy cross the\n"+
                   "dark clouds in an agressive manner",
      "peak", "The mountain's peak is surrounded by the dark clouds",
      "stone", "The wall of stone blocks any further passage here",
    });

    dest_dir=({
      "/players/daranath/clearing/mtrail3.c","east",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search_room");
    }

    search(){
    write("You find nothing along the trail encircling the mountain.\n");
    say(tp +" searches the area.\n");
     return 1;
    }



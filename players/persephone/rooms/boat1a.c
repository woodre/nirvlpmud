inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
 object ladder;
 int t;
reset (int arg){
 if(!present("worker")){
    for(t=0;t<3;t++){
    move_object(clone_object("players/persephone/monster/worker"),TOB);
  }
 }
 if (!arg){
 set_light(0);
 short_desc="A Small Transport Ship";
  long_desc="This is the deck of a small transport ship you think\n" +
            "it strange such ships still call into port around you\n" +
            "workmen are carrying in and stacking bananas\n" +
           "\n";
  items=({"bananas","You know those bent yellow skinned fruits that\n" +
                    "some people eat",
          "deck","The deck is covered with bunches of bananas",
          "workmen","They seem to be whistling minding their own business",
          "tarantula","had you worried their didn't I it is just\n" +
                      "stuff off the bananas",
        });
  dest_dir=({"players/persephone/rooms/pier1b","disembark",
  });
 }
}
realm(){ return "NT";}

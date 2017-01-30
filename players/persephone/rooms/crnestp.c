inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
  if(!present("slash")){
    move_object(clone_object("players/persephone/monster/looko"), TOB);
  }
 if (!arg){
  set_light(1);
  short_desc="A Crows Nest";
  long_desc="As you pull yourself up onto the crows nest you gasp at the magnificent\n" +
           "view however your attention is distracted by the way the this vantage\n" +
          "point is swinging in the breeze which you could not notice lower down.\n" +
         "Maybe you should climb back down as you are starting to feel sick.\n" +
         "\n";
  items=({"view","It is wonderous and you think you can make out the town\n" +
                 "center in the distance and one of the hotels people\n" +
                 "seem to be milling about way below you",
          "town","The town looks extremely dark almost as if a black evil\n" +
                 "hangs over it",
          "hotel","It may not be a hotel but you think it might be but it is distant",
          "people","There are swarms of people milling around below you",
        });
  dest_dir=({"players/persephone/rooms/crnestl","down",
  });
 }
}
realm(){ return "NT"; }

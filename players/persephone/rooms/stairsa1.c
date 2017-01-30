inherit "/players/persephone/closed/thingys";
#include "/players/persephone/rooms.h"
int t;
reset (arg){
    for(t=0;t<3;t++){
  if(!present("pirate")){
    move_object(clone_object("players/persephone/monster/piradd"), TOB);
    }
  }

 if(!arg) {
  set_light(1);
 short_desc="Steep Stairs";
  long_desc="As you start climbing the the staircase you notice one of the figures\n" +
           "dart up the staircase and turn to the east. It now however seems that\n" +
           "you are surrounded by many dark shapes carrying bundles down the stairs\n" +
           "and you wonder if they will notice you.\n" +
           "\n";
  items=({"stairs","The stairs have bodies piled allaround you\n" +
                   "think they must be of the poor unfortunate\n" +
                   "of Stormhold",
          "shapes","You think they must be pirates",
          "walls","They seem to be spatterred with blood",
          "bundles","You cannot tell what the bundles are",
        });
  dest_dir=({"players/persephone/rooms/stairsa2.c","up",
             "players/persephone/rooms/hot1","down",
  });
 }
}
realm() { return "NT";}


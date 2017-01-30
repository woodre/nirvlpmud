inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
int i;
reset(arg){
if(!present("warg")) {
      for(i=0;i<5;i++) {
         move_object(clone_object("players/persephone/monster/warg"), TOB);
      }
   }
 if(!arg)  {
  set_light(0);
  short_desc="Cave Entrance";
  long_desc="You stand trembling at the entrance to a large and evil\n" +
            "looking cave. All around you lie the bones of many different\n" +
            "creatures. Unfortunately for you though there is also a large\n" +
            "group of wargs who noticed your entrance into their territory\n" +
            "\n";
  dest_dir=({"players/persephone/rooms/junpat6","north",
             "players/persephone/rooms/wargca","down",
           });
  }
}

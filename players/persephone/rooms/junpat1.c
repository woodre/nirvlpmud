inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
 if(arg) return;
  set_light(1);
  short_desc="Eerie Jungle Path";
  long_desc="This is the entrance to the dark and apperently unfortunate jungle\n" +
            "of Regrets. Perhaps you should not continue or you to may have some\n" +
            "regrets to.\n" +
            "\n";
  dest_dir=({"players/persephone/rooms/marsh1","west",
             "players/persephone/rooms/junpat8","east",
            });
}

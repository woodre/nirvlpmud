inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
  if(!present("redbeard")){
    move_object(clone_object("players/persephone/monster/redbeard"), TOB);
  }
 if(!arg) {
  set_light(1);
  short_desc="Royal Bedroom";
  long_desc="This is the royal bedroom and you start to wish you were royalty\n" +
             "yourself as all your suoundings are beautiful and in the middle of\n" +
             "is the biggest bed you have ever seen. To the east this section\n" +
             "of the royal suite continues while to the west you see the royal\n" +
             "ensuite.\n" +
             "\n";
  dest_dir=({"players/persephone/rooms/ro_sui","east",
           });
 }
}

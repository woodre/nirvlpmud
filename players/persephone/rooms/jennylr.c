inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
 if(!present("jeny")){
  move_object(clone_object("players/persephone/closed/jeny"),TOB);
 }
 if(!arg){
  set_light(0);
  short_desc="Storage Room";
  long_desc="You searched the interior of the wardrobe and found yourself in the\n" +
            "Hideout of the notorious Pirate Jenny unfortunately for you she is here\n" +
            "also. While this used to be a Storage Room and still looks like one\n" +
            "to some extent you can see that she has made this eerie little room\n" +
            "into an adequate office. Up against the north wall you see a large\n" +
            "large window above a big old oak desk and against the east wall you\n" +
            "see in a glass display case the model of a Pirates Ship. The only\n" +
            "exit appears to be to the west.\n" +
            "\n";
  dest_dir=({"players/persephone/rooms/jennybl","west",
  });
 }
}
realm() { return "NT"; }

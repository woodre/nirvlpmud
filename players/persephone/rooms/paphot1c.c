inherit "/players/persephone/closed/thingys";
#include "/players/persephone/rooms.h"
reset(arg){
 if(!arg){
  set_light(1);
  short_desc="Damp Corridor";
  long_desc="You are in an extremely damp corridor and liquid is seeping from all\n" +
            "around you. To the east the corridor continues and to the west you see\n" +
            "some stairs while on either side of you are hotel rooms with bodies\n" +
            "piled in front of them\n" +
            "\n";
  dest_dir=({"players/persephone/rooms/stairsa2","west",
             "players/persephone/rooms/paphot1b","east",
  });
 }
}
realm() { return "NT";}


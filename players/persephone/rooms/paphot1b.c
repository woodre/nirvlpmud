inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
 if (!arg) {;
  set_light(0);
  short_desc="Damp Corridor";
  long_desc="You are in a damp and dark corridor with bodies piled up along all\n" +
            "the sides of the corridor blocking the rooms to the north and you do\n" +
            "not know how much longer you can stand the smell. The corridor continues\n" +
            "to the west and there is a room to the east.\n" +
            "\n";
  items=({"rooms","The rooms look as if they have been ripped to shreds",
          "bodies","Most definately human bodies and definately dead",
          "floor","there is a reddish brown oozy liquid on the floor",
          "liquid","Brownish red in colour it is probably blood",
        });
  dest_dir=({"players/persephone/rooms/paphot1c","west",
             "players/persephone/rooms/paphot1a","east",
  });
 }
}
realm() { return "NT";}

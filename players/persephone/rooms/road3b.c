inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset (arg){
 if(!arg) {
  set_light(1);
  short_desc="Broadway Ave";
  long_desc="You are now travelling along the once famed Broadway. The lights that\n" +
            "however that used to shine brightly are now rather dull at least in\n" +
            "this section of broadway. Far to the north you see the port of Stormhold\n" +
            "while to the south Broadway Avenue continues and to the West is the\n" +
            "boardwalk. To your East however you can see a grand looking hotel with a \n" +
             "sign hanging down from the awning.\n";
  items=({"lights","They are Neon lights but many of them seem not to be working",
          "hotel","This is perhaps the most exclusive hotel in all the world\n" +
                  "of Nirvana and even from outside you can see the class of this\n" +
                  "fine establishment from the awning to the marble columns",
          "sign","The sign is glorious you must read it",
          "awning","A mauve and white striped canvas awning",
          "broadway","Broadway was the center of all culture on Igor until the\n" +
                     "evil came",
          "boardwalk","A street covered completely by boards what do you think the\n" +
                      "Boardwalk was there seems to be some comotion in that\n" +
                      "direction",
          "harbour","You are really to far off to see much of the harbour",
          "ground","The Bitumen road is below your feet",
          "sky","The sky is glorious oh what a sunset you see. Off to the south\n" +
                "however it looks as if a storm is brewing",
        });

  dest_dir=({"players/persephone/rooms/road3a","north",
             "players/persephone/rooms/road2b","west",
             "players/persephone/rooms/road3c","south",
             "players/persephone/rooms/lobby_ch","east",
  });
 }
}
realm() { return "NT"; }

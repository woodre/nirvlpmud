inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset (arg){
 if (!arg) {
  set_light(1);
  short_desc="Bell Hop";
  long_desc="You are at the porters or bell hop's desk however it appears as if\n" +
            "no one is on duty at the moment. Back to the West you see the main\n" +
            "lobby however other than the old man sitting in the large leather chair\n" +
            "the lobby looks completely empty.\n";
  items=({"desk","A marble topped counter with goldleaf like you would\n" +
                 "would expect in a first class hotel",
          "lobby","A very large comfortable looking lobby",
          "chair","The chairs all look very comfortable and appear to\n" +
          "be made of genuine leather",
          "floor","The floor is highly polished marble you can see your\n" +
                  "reflection in it",
          "ceiling","An extremely high and vaulted ceiling with a crystal\n" +
                    "chandelier hanging from the middle of it",
          "chandelier","The Chandelier is made out of the finest lead\n" +
                       "crystal and befits the environment",
        });
  dest_dir=({"players/persephone/rooms/lobby_ch","west",
  });
 }
}
realm(){ return "NT";}

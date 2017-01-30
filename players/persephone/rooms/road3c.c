inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset (arg){
 if (!arg) {
  set_light(1);
  short_desc="Broadway Ave";
  long_desc="This part of Broadway Avenue seems to be very clean however all of the\n" +
           "buildings seem to be abandoned and boarded up. On most of the buildings\n" +
           "which are to the West and the East you see big Neon signs. To the South\n" +
           "you see the Square of Stormhold which again looks deserted while to the\n" +
           "North, Broadway continues.\n" ;
 items=({"broadway","It does not look like the broadway district in New York\n" +
                     "then again it is not New York. However, you are of the\n" +
                     "opinion that this street must have been where the in scene\n" +
                     "hung out",
          "boards","Just strong wooden boards it looks as if someone intended\n" +
                   "to keep everyone out",
          "neon","Just a gas what do you think neon is",
          "signs","They are big and one still has someones name on it perhap\n" +
                  "you should read the sign",
          "avenue","It just looks like a road",
          "square","You cannot see enough of the square from here to describe it",
          "buildings","Despite the boards and the general filth the buildings\n" +
                      "still seem very solid. Escpecially the Opera house and\n" +
                      "main theatre",
          "house","The Opera house would have once been a grand building\n" +
                  "unfortunately you cannot find any way of entering it",
          "theatre","This appears to be the famous Tivoli theatre however it is\n" +
                    "in a very run down condition",
        });
  dest_dir=({"players/persephone/rooms/road3b","north",
             "players/persephone/rooms/square5","south",
  });
 }
}
realm() { return "NT"; }

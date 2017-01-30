inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
 if (!arg) {
  set_light(1);
  short_desc="Chelsea Corridor";
  long_desc="This is one of the most gloriously decorated hotel corridors you\n" +
            "have ever seen. The corridor continues both east and west while to the\n" +
            "the north and south are rooms\n" +
            "\n";
  items=({"walls","Talk about opulence these walls are covered in gold wallpaper\n" +
                  "and there is a number above the both the north and south rooms",
          "numbers","Amazing these numbers are in pure Obsidian and very black the number\n" +
                    "to your north is 204 and south is 203",
          "floor","This floor is covered with beautiful carpet",
          "carpet","The carpet is pure wool and it looks gold just like the walls",
          "wool","This is not just wool it looks like it is from the golden\n" +
                 "fleece",
          "wallpaper","Well it actually is not wallpaper but very fine gold leaf\n" +
                      "do you dare steal any? I would not if I were you",
          "corridor","Just a corridor in a five star hotel what do you expect?",
          "room","You wish you could afford either of the rooms to your north or south \n" +
                 "as they both look stunning. Perhaps you should just go in and look at\n",
                 "them and see how the rich live",
          "ceiling","The ceiling is gold and red and in the middle of it is a\n" +
                    "beautifully decorated ceiling rose",
          "rose","It is simply stunning with illustrations of large clipper\n" +
                  "ships all around it",
          });
  dest_dir=({"players/persephone/rooms/rm204","north",
             "players/persephone/rooms/hcorr2a","west",
             "players/persephone/rooms/rm203","south",
           });
 }
}
realm(){ return "NT"; }

inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
  if(!present("swashbuckler")){
    move_object(clone_object("players/persephone/monster/piradg"),TOB);
  }
 if (!arg) {
  set_light(1);
  short_desc="Chelsea Corridor";
  long_desc="This is one of the most gloriously decorated hotel corridors you\n" +
            "have ever seen. The corridor continues both east and west while to the\n" +
            "the north and south are rooms\n" +
            "\n";
  items=({"walls","Talk about opulence these walls are covered in gold wallpaper\n" +
                  "and there is a number on top of the entrance to the room south",
          "floor","This floor is covered with beautiful carpet",
          "carpet","The carpet is pure wool and it looks gold just like the walls",
          "wool","This is not just wool it looks like it is from the golden\n" +
                 "fleece",
          "wallpaper","Well it actually is not wallpaper but very fine gold leaf\n" +
                      "do you dare steal any? I would not if I were you",
          "corridor","Just a corridor in a five star hotel what do you expect?",
          "room","You wish you could afford either of the rooms to your north or south \n" +
                 "as they both look stunning unfortunately they are rooms 207 and 208\n",
                 "and your key definately does not have either room numbers not that\n" +
                 "these rooms are closed why don't you go in and see what awaits you",
          "ceiling","The ceiling is gold and red and in the middle of it is a\n" +
                    "beautifully decorated ceiling rose",
          "rose","It is simply stunning with illustrations of large clipper\n" +
                  "ships all around it",
          });
  dest_dir=({"players/persephone/rooms/rm206","north",
             "players/persephone/rooms/rm207","south",
             "players/persephone/rooms/hcorr2a","east",
           });
 }
}
realm(){ return "NT"; }

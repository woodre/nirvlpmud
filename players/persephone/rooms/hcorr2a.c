inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
  if(!present("pirate")){
    move_object(clone_object("players/persephone/monster/piradf"),TOB);
    move_object(clone_object("players/persephone/monster/piradf"),TOB);
  }
 if (!arg) {
  set_light(1);
  short_desc="Chelsea Corridor";
  long_desc="This is one of the most gloriously decorated hotel corridors you\n" +
            "have ever seen. The corridor continues both east and west while to the\n" +
            "the north is the staircase and a room is south\n" +
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
          "room","Your view is slightly obscured but this room looks to be \n" +
                 "to be one of the best hotel rooms you have seen\n",
          "number","The number appears to be 205 so you guess the room must\n" +
                   "be number 205",
          "ceiling","The ceiling is gold and red and in the middle of it is a\n" +
                    "beautifully decorated ceiling rose",
          "rose","It is simply stunning with illustrations of large clipper\n" +
                  "ships all around it",
          });
  dest_dir=({"players/persephone/rooms/hotsta","north",
             "players/persephone/rooms/hcorr2b","west",
             "players/persephone/rooms/rm205","south",
             "players/persephone/rooms/hcorr2c","east",
           });
 }
}
realm(){ return "NT"; }

inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
 if(!present("longbeard")){
  move_object(clone_object("players/persephone/monster/longb"),TOB);
 }
 if (!arg) {
  set_light(1);
  short_desc="Secret Room";
  long_desc="From the barren appearence of this room you would tend to\n" +
            "think that this is a secret observation room.  As you\n" +
            "look around you see tables and different pieces of\n" +
            "electronic equipment bolted down\n\n";
  items=({"walls","The walls are plain white with a little spy hole",
          "floor","The floor is covered with sound absorbing felt",
          "wallpaper","you do not see any wallpaper here",
          "tables","covered in the remnants of stale food yuk!",
          "equipment","Looks like surveilence equipment of some sort\n" +
                      "but none of it is operational",
          });
  dest_dir=({"players/persephone/rooms/rm205","east",
           });
 }
}
realm(){ return "NT";}


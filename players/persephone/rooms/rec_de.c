inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset (arg){
 if (!arg) {
  set_light(1);
  short_desc="Hotel Reception";
  long_desc="You are standing in the reception area to one of the Grandest hotels\n" +
            "in the land, the Chelsea. It is everything that you have heard of and\n" +
            "deserves all the praise it has received. In front of you is the\n" +
            "reception desk however it appears as if it is unattended at the moment\n" +
            "Perhaps, if you ring the bell someone might serve you. Near the desk\n" +
             "there appears to be a set of stairs which you think might go up to\n" +
            "the rooms while to the South is the main lobby of the hotel.\n";
  dest_dir=({"players/persephone/rooms/lobby_ch","south",
             "players/persephone/rooms/hotst1","up",
  });
 }
}
realm() { return "NT"; }

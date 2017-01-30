/* Apartment Room */
#define tp this_player()->query_name()
#define mp this_player()->move_player
#include "/players/cosmo/closed/ansi.h" 
inherit "players/cosmo/dc/dcroom";

reset(arg) {
  if(arg) return;
  set_light(1);
  set_room_type("street");
  short_desc=GRN+"Upper East Side"+NORM;
  long_desc=
"  You walk gallantly along the sidewalk and can't help but\n"+
"think about what a wonderful day it is outside.  You begin to\n"+
"ponder the meaning of life.  Hmm... wouldn't it be nice to\n"+
"actually design a city like this?  You glance around at\n"+
"all the large buildings surrounding you and start comtemplating\n"+
"building architecture as you walk.  The street just goes on and on.\n",

  items= ({
    "buildings","Old dirty buildings. Who knows what you might find in them",
    "shops","All of the typical city shops may be found along this street",
  });

  dest_dir= ({
    "players/cosmo/apt/rooms/rstreet", "east",
    "players/cosmo/apt/rooms/rs4", "west",
  });
}

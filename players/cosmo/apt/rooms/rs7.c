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
"  The street abruptly comes to a halt here.  It appears that\n"+
"you have reached a dead-end.\n",

  items= ({
    "buildings","Old dirty buildings. Who knows what you might find in them",
    "shops","All of the typical city shops may be found along this street",
  });

  dest_dir= ({
    "players/cosmo/apt/rooms/rs5new", "west",
  });
}

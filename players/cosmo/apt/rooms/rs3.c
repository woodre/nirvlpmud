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
"  Despite your sudden apprehensiveness about this city, and\n"+
"your overwhelming sense of claustrophobia from these large\n"+
"buildings all around you, you press onward.  What a trooper\n"+
"you are.  As you are walking you notice a small shop on the\n"+
"north side of the street.  Perhaps you should take a closer\n"+
"look at it.\n",

  items= ({
    "buildings","Old dirty buildings. Who knows what you might find in them",
    "shops","All of the typical city shops may be found along this street",
    "shop","You peer in the window and see a quaint little cafe. Perhaps\n"+
           "you can enter the cafe",
  });

  dest_dir= ({
    "players/cosmo/apt/rooms/rs5new", "east",
    "players/cosmo/apt/rooms/rs1", "west",
    "players/cosmo/apt/rooms/rcafe", "cafe",
  });
}

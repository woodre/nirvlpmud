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
"  You stand on the side of a street running east-west on the\n"+
"upper east side of town.  Traffic is light here, but the cars\n"+
"that drive by, drive very fast.  Shops and apartment buildings\n"+
"line the sides of the streets.  You can't help but notice a small\n"+
"shop on the side of the street.\n",

  items= ({
    "buildings","Old dirty buildings. Who knows what you might find in them",
    "shops","All of the typical city shops may be found along this street",
    "shop","You peer in the window and see a man selling soup. Perhaps\n"+
           "you can enter the shop",
  });

  dest_dir= ({
    "players/cosmo/apt/rooms/rs2", "east",
    "players/cosmo/apt/rooms/rs6", "west",
    "players/cosmo/apt/rooms/rnazi", "shop",
  });
}


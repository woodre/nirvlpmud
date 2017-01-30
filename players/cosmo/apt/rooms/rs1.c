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
"  You decide to take your chances walking down the street.  What's\n"+
"the worst that could happen anyway? You could get mugged? Yeah,\n"+
"right, like that could possibly happen to someone as tough\n"+
"as you.  Traffic continues to flow steadily and you remain on the\n"+
"sidewalk amidst all of the large buildings.\n",

  items= ({
    "buildings","Old dirty buildings. Who knows what you might find in them",
    "shops","All of the typical city shops may be found along this street",
  });

  dest_dir= ({
    "players/cosmo/apt/rooms/rs3", "east",
    "players/cosmo/apt/rooms/rstreet", "west",
  });
}

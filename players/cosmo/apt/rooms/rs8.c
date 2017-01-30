/* Apartment Room */
#define tp this_player()->query_name()
#define mp this_player()->move_player
#include "/players/cosmo/closed/ansi.h" 
inherit "players/cosmo/dc/dcroom";

reset(arg) {
  if(arg) return;
  set_light(1);
  set_room_type("street");
  set_smell("You smell a nasty combination of blood and burned rubber.");
  set_sound("Some people are screaming out for help; others are shouting orders.");
  short_desc=GRN+"Upper East Side"+NORM;
  long_desc=
"  A large accident has occurred here, blocking not only the\n"+
"street, but the sidewalks as well.  It was quite a horrible\n"+
"accident; paramedics are running everywhere, and people are\n"+
"screaming in fright.  Your best bet probably would be to turn\n"+
"around and go back east.  There doesn't seem to be any way\n"+
"around it.\n",

  items= ({
    "buildings","Old dirty buildings. Who knows what you might find in them",
    "accident","It looks like a large dump truck slammed into 4 or 5 cars.\n"+
      "It's quite a gruesome sight",
    "truck","The dump truck is turned on its side and sand is pouring out everywhere",
    "sand","The sand covers the street, the cars, and the sidewalks creating\n"+
      "a real mess.  Good thing it's not raining",
    "paramedics","The emergency medical personnel are treating the injuries of\n"+
      "those in the accident",
    "cars","Car parts and shattered glass are strewn across the street",
  });

  dest_dir= ({
     "players/cosmo/apt/rooms/rs6", "east",
  });
}

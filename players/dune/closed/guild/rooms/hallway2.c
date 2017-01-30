inherit "/players/dune/closed/guild/rooms/room";
#include "../DEFS.h"


reset(arg)
{
  if(!present("board"))
  {
    move_object(clone_object(BOARDDIR + "/ideaboard.c"),
    this_object());
  }

  if(!arg){
  set_light(1);
  short_desc="Streets of Netropolis";
  long_desc=
"     The electronic streets of Netropolis glow with\n"+
"the streaming lights of optical wires and heated lines\n"+
"of central processing units.  Yet you can see a strong\n"+
"influence of warrior pride.  Arches of gigantic blades\n"+
"and columns stand decorated with ancient suits of armor.\n";

  items=({
"streets", "The streets are made of dark-colored metal",
"wires","Thick colorful wires lace along the roadside",
"lines","CPU lines glow red with all the info passing through them",
"arches","Several gigantic arches tower over the streets",
"blades","The blades are symbols of ninja strength",
"columns","Several columns hold up the dark ceiling above",
"armor","These suits of armor serve as fitting decorations",
"suits","These suits of armor serve as fitting decorations",
  });

  dest_dir=({
    ROOMDIR + "/shop.c", "north",
ROOMDIR + "/hallway3.c", "west",
    ALTLOGIN,"east",
    ROOMDIR + "/convert.c", "down",
  });
  }
}

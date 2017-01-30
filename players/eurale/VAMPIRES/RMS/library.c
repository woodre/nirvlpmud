#include "/players/eurale/closed/ansi.h"
#define TO this_object()
#define TP this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("librarian")) {
  move_object(clone_object("/players/eurale/VAMPIRES/NPC/librarian.c"),TO); }
set_light(0);

short_desc = "Vampire Library";
long_desc =
  "Books of every size and shape fill nearly every space in this cool\n"+
  "dark room.  Wooden shelves support the thicker and heavier ones and\n"+
  "have even begun to sag with their weight.  A small desk sits in the\n"+
  "farthest corner and it, too, is covered with them.\n";

items = ({
  "books","Most of them are so covered with dust that it is nearly\n"+
          "impossible to make out their titles.  They look to be\n"+
          "leather bound and worn from people thumbing through their\n"+
          "pages.  A couple on the shelf can be read, however.  They\n"+
          "say 'Vampire History Volume 6' and 'Vampire History Volume 8'",
  "shelves","Long wooden planks held to the stone wall with long,\n"+
            "pointed nails driven deep",
  "desk","A makeshift desk to provide relief to anyone given the job\n"+
         "of straightening up the books. A small sign sits atop it",
  "sign","The sign reads, 'If you need help, just [ask]'",
});

dest_dir = ({
  "players/eurale/VAMPIRES/RMS/wing_room","west",
});

}

realm() { return "NT"; }

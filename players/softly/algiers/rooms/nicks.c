#include "/players/softly/closed/define.h"
#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/room";

reset(arg){
  if(!present("nick")){ 
    move_object(clone_object("players/softly/algiers/mobs/nick.c"),this_object());
  }

  if(arg) return;
  set_light(1);
  short_desc = "Nick's Detective Agency";
  long_desc ="\n"+
    "  The shabby room is lit with a few lamps and the thin light\n\
that threads its way through the large window.  An aged wooden\n\
desk is covered with piles of dusty papers, the phone partly\n\
hidden.  A wooden swivel chair is behind the desk.  A coat rack\n\
in the corner holds a fedora and several neckties.  The formica\n\
covered walls are the shade of a worn riverbank.  A single filing\n\
cabinet has two drawers that are not fully closed.  A lone chair\n\
of ancient leather awaits any stray visitor.\n";

  items = ({
    "lamps", 
    "A brass lamp sits on the desk.  And aged floor\n\
is near the coat rack",
    "drawers",
    "The filing cabinet has 5 drawers.  Two are not fully closed",
    "rack",
    "A bentwood coat rack is laden with neckties and\n\
a single grey brimmed hat",
    "room",
    "The dim room has seen better days            ",
    "lamp",
    "The floor lamp is turned off.  A table lamp, oddly out\n\
of place on the desk, is switched on",
    "light",
    "The light is rather dim",
    "window",
    "On the back of the window is the reverse side of the sign\n\
that reads 'Nicholas Earl Boudreaux, Detective Agency",
    "desk",
    "The large oak desk looks as if it might have been well worn\n\
when it was new",
    "papers",
    "Scribbled notes, letters, and invoices are randomly stacked\n\
in piles on the desk",
    "chair",
    "A wooden swivel chair is behind the desk.  A cracked leather\n\
chair is in front of the desk for visitors",
    "fedora",
    "A black hat with a wide brim",
    "neckties",
    "Gaudy neckties, one with a naked lady painted on it",
    "walls",
    "The walls are covered in formica paneling made to look like\n\
wood.  The effect is not convincing",
    "cabinet",
    "A grey filing cabinet has seen better days.  Several drawers\n\
have been left open",

  });

  dest_dir = ({
    "/players/softly/algiers/rooms/road15.c","east",
  });
}

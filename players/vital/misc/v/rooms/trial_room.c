#include "/players/eurale/defs.h"
inherit "room/room";
object note;

reset(arg) {
  if(arg) return;
set_light(-1);

short_desc = BOLD+"Trials Arena"+NORM;
long_desc =
  "Solid rock walls entrap you. The curved walls meet back at the black\n"+
  "opening, the only way out.  The rock floor is has large dark stains\n"+
  "covering it and the odor is the sickly sweet smell of dried blood.\n"+
  "Burning torches in metal holders adorn the walls and provide just\n"+
  "enough light to see.  All in all, a terrifying place.\n";

items = ({
  "walls","Curved, almost in a circle and about 12 feet apart at the\n"+
          "widest point",
  "opening","A solid black opening, shimmering as if it was a magic\n"+
            "spell of some kind",
  "floor","Solid rock and covered with black stains that make your\n"+
          "feet stick",
  "stains","The blood of those who entered here ill-prepared and met\n"+
           "their demise",
  "torches","Wooden handles with burning material soaked in oil on the\n"+
            "end. The smoke from them blackens the close ceiling",
  "holders","Metal holders, attached to the walls, that support the\n"+
            "burning torches",
});

dest_dir = ({
  "players/eurale/VAMPIRES/RMS/foyer.c","out",
});

}

realm() { return "NT"; }

exit() {
if(TP)
if(!TP->query_ghost()) {
  ("players/eurale/VAMPIRES/RMS/foyer.c")->set_ONE(0);
  TP->set_al_title("lord of evil");
  return 1; }
}


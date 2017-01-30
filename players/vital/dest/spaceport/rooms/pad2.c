/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   12/27/00          */
/*    Realm:      Spaceport         */
/************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/dest/include/spaceport.h"     /*area header */

inherit "room/room";

object crew;

reset(arg) {
  if(!present("crew",this_object())) {
     crew = CO(SPNPC+"padcrew.c");
     MO(crew, TO);
   }
  if(!arg) {

set_light(1);

short_desc = "Launch Pad";
long_desc =
  "  The Northwest Launch Pad\n\
This is the northwest launch pad where incoming shuttles land and takeoff. \n\
Thousands of shuttle land on this pad every day, causing wear and tear to \n\
the surface of the pad, creating the need for constant repair. Crews roam \n\
the pad looking for scar marks and pits that could develop into problems if \n\
left unattended.\n";

items = ({
  "pad",
  "Solid "+BOLD+BLK+"black"+NORM+" tarmac that stretches nearly 4 acres. There\ are scars and pits \nfrom the repeated landing of the "+BLU+"rho"+NORM+"\
-field shuttles",
  "shuttles",
  "These are craft of every imaginable size. They use the inertia-less\n\
"+BLU+"rho"+NORM+"-field to quickly accelerate to very high speeds",
  "wear",
  "There are scars and pits from the repeated landing of the "+BLU+"rho"+NORM+"\
-field shuttles",
  "tear",
  "There are scars and pits from the repeated landing of the "+BLU+"rho"+NORM+"\
-field shuttles",
  "surface",
  "Solid "+BOLD+BLK+"black"+NORM+" tarmac that is designed to withstand great \
pressures and \nstresses",
  "crews",
  "The pad needs constant repair and maintenance in the face of stress from \n\
the shuttles",
  "marks",
  "There are scars and pits from the repeated landing of the "+BLU+"rho"+NORM+"\
-field shuttles",
  "pits",
  "There are scars and pits from the repeated landing of the "+BLU+"rho"+NORM+"\
-field shuttles",
  "problems",
  "The large cracks and destroyed areas in the pad that will develope from\n\
inattention to the surface"
});

dest_dir = ({
    SPROOM+"pad1.c","south",
    SPROOM+"transitway","northeast",
    SPROOM+"pad3.c","east",
    SPROOM+"pad4.c","southeast"
  });
  }
}

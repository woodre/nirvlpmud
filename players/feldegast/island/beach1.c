#include "/players/feldegast/defines.h"
inherit ROOM;
reset(arg) {
  if(!present("portal")) {
    object gate;
    gate=clone_object("/players/feldegast/obj/azure_portal");
    gate->set_destination("/players/feldegast/shrine");
    move_object(gate,this_object());
  }
  if (arg) return;
  set_light(1);
  short_desc="A sandy beach";
  long_desc=
"     You are on a sandy beach.  The cool blue water laps up\n"+
"against the shore.  A swirling blue portal stands here in the\n"+
"sand.  To the southwest, you see a ship in the water.\n";
  items=({
    "portal","It shimmers through several shades of blue",
    "ship","A sleak, fast vessel bristling with cannons.  Perfect for piracy",
    "beach","A broad stretch of sand along the shore of this island",
    "water","Cool blue water with bits of seaweed and plankton in it",
    "shore","The shore stretches north and south from here"
  });
  dest_dir=({
    "/players/feldegast/island/beach4","north",
    "/players/feldegast/island/beach3","south"

  });
}   

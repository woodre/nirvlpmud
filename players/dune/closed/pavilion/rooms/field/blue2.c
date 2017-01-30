#include "roomgod.c"
inherit "room/room";

string zone;
string zone() { return zone; }
init() { add_action("goplace", "hangar"); ::init(); }

reset(arg) {
   if(!arg) {
   set_light(1);
   short_desc=("Blue Zone");
   zone = "Blue Zone";
   long_desc=
"     A large X-shaped battlefield stretches out before you.\n"+
"Tall metal and rock walls form the borders of the field.\n"+
"Situated upon these walls stand several blue flags.\n";

   dest_dir=({
   "/players/dune/closed/pavilion/rooms/field/blue3.c",  "sw",
   "/players/dune/closed/pavilion/rooms/field/blue4.c",  "s",
   "/players/dune/closed/pavilion/rooms/field/blue1.c",  "w",
   "/players/dune/closed/pavilion/rooms/field/bluea.c",  "nw",
   "/players/dune/closed/pavilion/rooms/field/blueb.c",  "w",
   "/players/dune/closed/pavilion/rooms/field/white1.c", "se",
   "/players/dune/closed/pavilion/rooms/roboshop.c", "hangar",
        });

   items=({
   "flags","These flags signify the color of zone your are in",
   "walls","The walls are very sturdy",
   "battlefield","The battlefield is X-shaped.\n"+
                 "You are in only one of the five zones",
        });
   }   }

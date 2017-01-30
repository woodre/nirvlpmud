/*
 *
 */
#include "../paths.h"
#include "/players/languilen/langdefs.h"
#include "/players/languilen/closed/ansi.h"
inherit "room/room";

reset(arg) {
     if(arg) return;
     set_light(1);

     short_desc = "Guards Quarters";
     long_desc =
"    This room contains several bunks and lockers, all look exacly\n\
alike.  Green woolen blankets are streached tight across the beds.\n\
The clothing in the lockers, arrainged exactly the same.\n";

     items = ({
     "bunks","These are simple metal racks containing thin matreses",
     "lockers","They are open faced green metal lockers containing green clothes",
     "blankets","You could bounce a pebble on them",
     "beds","Bunk type beds, one upon another, with metal frames",
     "clothing","Mostly green shirts and pants packed neatly",
     });

     dest_dir = ({
     ROOM + "hall1.c","east",
});

}

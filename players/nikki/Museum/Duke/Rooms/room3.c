#include "/players/nikki/ansi.h"
inherit "room/room";

reset(arg) {
   if(!arg) {
set_light(1);
short_desc = HIY+"She Wore A Yellow Ribbon"+NORM;
long_desc = HIW+
 "\t\t  ~~ She Wore A Yellow Ribbon ~~\n"+HIY+
 "   In 1949, The Duke stars as Captain Brittles, an iron willed veteran\n"+
 "who is called upon to do one more tough job before he retires.\n"+NORM;

dest_dir = ( {
    "players/nikki/Museum/Duke/Rooms/room1", "left",
});
} }

realm() { return "NT"; }


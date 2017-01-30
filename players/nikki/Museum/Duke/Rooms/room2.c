#include "/players/nikki/ansi.h"
inherit "room/room";

reset(arg) {
   if(!arg) {
set_light(1);
short_desc = HIB+"Ride Him, Cowboy"+NORM;
long_desc = HIW+
 "\t\t\t~~ Ride Him, Cowboy ~~\n"+HIB+
 "   Gallop along with John Wayne and his wonder horse 'Duke' in the 1932\n"+
 "film that made the young ex-prop man a major cowboy star.\n"+NORM;

dest_dir = ( {
    "players/nikki/Museum/Duke/Rooms/room1", "right",
});
} }

realm() { return "NT"; }


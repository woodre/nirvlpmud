#include "/players/nikki/ansi.h"
inherit "room/room";

reset(arg) {
   if(!arg) {
set_light(1);
short_desc = HIR+"Stagecoach"+NORM;
long_desc = HIW+
 "\t\t\t   ~~ STAGECOACH ~~\n"+HIR+
 "   A small western town is terrorized by a gang of nasty outlaws.  John\n"+
 "organizes a group of men to save the town from The Shadow and his felonious\n"+
 "horde.\n"+NORM;

dest_dir = ( {
    "players/nikki/Museum/Duke/Rooms/room1", "backward",
});
} }

realm() { return "NT"; }


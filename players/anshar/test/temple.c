#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc = MAG+"Kadath"+NORM;
   long_desc =
"     The cavern opens up into a high ceiling temple room.  The walls\n"+
"are made of brimstone and fireshadows.  There are pews in a row on each\n"+
"side of a long aisle, which leads up to a high altar.  There is a bearded\n"+
"priest standing by a podium on the altar.  The only exit seem to be the\n"+
"entrance from behind.\n";
   
   items = ({
"ceiling","The high ceilings are made of various types of stone",
"pews","Benches with high backs made of stone",
"altar","The platform from which sacrifices are made to the gods.\n"+
"Torches are lit on each side.\n",
"fireshadows","Shadows of fire blazing across the walls",
"podium","A small platform, in the middle of the altar",
});
   dest_dir = ({
"/players/brittany/kadath/room5.c","west",
});
if(!present("priest")) {
move_object(clone_object("/players/brittany/kadath/nasht.c"),this_object());
}
}

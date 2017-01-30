#define tpn this_player()->query_name()
#include "/players/eurale/closed/ansi.h"
inherit "room/room";

reset(arg) {
if(!present("chest")) {
move_object(clone_object("players/eurale/Druid/chest.c"),this_object()); }
if(!present("board")) {
move_object(clone_object("players/eurale/Druid/board.c"),this_object()); }
  if(arg) return;
set_light(1);

short_desc = BOLD+GRN+"Druid Room"+NORM;
long_desc =
	"  This is the relaxation room of the Druid Guild.  There are\n"+
	"a number of comfortable chairs and two long couches.  This is\n"+
	"where friends come to sit and chat or just relax in peace and\n"+
	"quiet.\n";

items = ({
	"chairs","Stuffed reclining chairs",
	"couches","Stuffed and extra long for comfortable naps",
});

dest_dir = ({
	"players/eurale/Druid/df10.c","west",
});

}

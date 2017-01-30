#define tpn this_player()->query_name()
#include "/players/eurale/closed/ansi.h"
inherit "room/room";

reset(arg) {
if(!present("healer")) {
move_object(clone_object("players/eurale/Druid/heal_mess.c"),
	this_object()); }
  if(arg) return;
set_light(1);

short_desc = BOLD+GRN+"Druid Repose"+NORM;
long_desc =
	"You have stepped though the back door of the Druid Guild Hall\n"+
	"and find yourself in a very secluded and serene spot.  The \n"+
	"huge trees have grown so tightly together here that they make\n"+
	"an impenatrable area, safe from intrusion.  Through the tree\n"+
	"canopy shines the sun, a bright ray seemingly focused on this\n"+
	"particular area.  It's warmth feels good and gives you the\n"+
	"energy to go on..\n";

items = ({
	"trees","Large hardwoods with thick trunks",
});

dest_dir = ({
	"players/eurale/Druid/df10.c","in",
	"players/saber/ryllian/portal.c","portal",
});

}

heal_druid() {
  write("You close your eyes and let the sun shine on your face...\n");
  call_other(environment(this_object()),"heal_self",3);
  return 1;
call_out("heal_druid",1);
}

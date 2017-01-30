inherit "room/room";  /* path2.c  */
#include "/players/zeus/closed/fl_demon.h"
#include "/players/zeus/closed/all.h"
int teleport;

reset(arg){
 if(!arg){

  teleport = 0;  if(random(TFL_TLP)) teleport = 1;
  short_desc="The Fallen Lands";
  set_light(1);
  long_desc=
"You now stand at the edge of darkness.  To the west, the forest seems to\n"+
"be consumed by a shadow.  The towering evergreen trees seem to change\n"+
"into twisted, dying relics.  There is a worn wooden sign posted in front\n"+
"of some dying bushes.  To the east the forest gets much lighter.\n";
  items =({
	"trees",
"The trees distinctly change to the west.  Right around you they are\n"+
"growing healthily, showing how strong the forest truly is.  But to the\n"+
"west they become dark and twisted, as though the forest itself has\n"+
"become deformed",
	"shadow",
"It seems like the forest to the west is consumed by a shadow.  It is\n"+
"extremely dark and forboding",
    "darkness",
"The forest to the west is wrapped in a blanket of darkness",
	"sign",
"The worn sign looks like it has been here for ages.  The writing which\n"+
"has been carved into it is barely 'read'able",
	"bushes",
"The dying bushes are green and brown, and looks like they have seen\n"+
"better days.  A wodden sign rests just in front of them",
  });
  dest_dir=({
"/players/zeus/realm/x/path1.c", "east",
"/players/zeus/realm/x/r/8.c", "west",
  });
 }
}

void init(){
	::init();
        add_action("e_dir", "east");
       add_action("w_dir", "west");
	add_action("read_cmd", "read");
}

exit(){    if(TP) TP->clear_fight_area();     }
realm() { if(teleport) return "NT"; }

read_cmd(str){
	if(str != "sign") return 0;
	write("\t\t - WARNING -\n"+
		"\tThink twice before going west.\n"+
		"\tThe forest isn't very forgiving.\n");
	say(TP->QN+" glances at the sign.\n");
	return 1;
}

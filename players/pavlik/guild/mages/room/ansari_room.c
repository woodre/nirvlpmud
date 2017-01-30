#include "/players/pavlik/guild/mages/defs.h"
inherit "/players/pavlik/guild/mages/inherit/room";
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc=HIY+"Ansari's"+NORM+YEL+" Chambers"+NORM;
  long_desc=
	"The Chamber's of Ansari are noticably more spartan than those of the other Masters.\n"+
	"This simple round chamber is barren except for a straw "+HIB+"tutami mat"+NORM+" which covers\n"+
	"the entire floor and a "+MAG+"small bowl"+NORM+" that has been placed in the center of the room.\n"+
	"Even the walls of this modest chamber are devoid of any decoration.  A door to the south\n"+
	"leads to Ansari's private chambers.\n";

  items=({
    "mat",
	"A plain tutami mat covers the floor.  The mat is made of tightly\n"+
	"woven straw.  The bristles of straw crunch quietly when you walk\n"+
	"on the mat",
    "bowl",
	"The bowl appears to be a simple piece of pottery.  There are no\n"+
	"markings or inscriptions upon it.  Looking closely you see a very\n"+
	"fine, almost invisisble, vapor rising slowly from the bowl",
    "vapor",
	"The vapor is so hard to see you are not even positive at is there",
  });

  dest_dir=({
	ROOM_DIR+"spell_masters",	"east",
	"null",				"south",
  });

  if(!present("ansari", this_object()))
	move_object(clone_object(NPC_DIR+"ansari"), this_object());

}

query_mguild(){ return "Ansari's Chambers"; }

init(){
  ::init();
  if(!mage_check()) return;
  add_action("guild_move","gm");
  add_action("no_way","south");
}

no_way()
{
  write("You ponder entering the door to the south and decide against it.\n");
  return 1;
}


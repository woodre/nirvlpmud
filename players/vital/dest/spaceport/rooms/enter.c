/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/15/00          */
/*    Modified:   1/4/01            */
/*    Realm:      Spaceport         */
/************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/dest/include/spaceport.h"

inherit "room/room";
object notes;
reset(arg){
  if(!present("notes",TO)) {
    notes=CO(SPOBJ+"notes.c");
    MO(notes, TO);
  }
  if(!arg) {

set_light(1);

short_desc = HIW+"Spaceport"+NORM+" Entrance";
long_desc =
  "  Welcome to the Nirvana Spaceport.\n\
You have arrived at the entrance to the Nirvana Universal \n\
Transport Spaceport (N.U.T.S).  Bright glass and metal shine \n\
everywhere you look. Ahead of you lies the security gates and \n\
the rest of the N.U.T.S. terminal. The universe is as close as \n\
your pocketbook will allow. To go back to Nirvana proper, you \n\
will need to go [out].\n ";

items = ({
  "entrance",
  "This is where everyone comes to enter or leave the spaceport",
  "spaceport",
  "This is Nirvana Universal Transport Spaceport (N.U.T.S)",
  "terminal",
  "This is Nirvana Universal Transport Spaceport (N.U.T.S)",
  "pocketbook",
  "Inter-stellar travel isn't cheap",
  "glass",
  "Actually a clear metal alloy, the \'glass\' is fused with\n\
the walls around it. This creates the strongest \
possible structure",
  "metal",
  "This appears to be a bright, shiny alloy. It was designed to\n\
provide the greatest level of strength and support",
  "gates",
  "A large imposing structure, designed to scan you and \
your \nloved ones. To enter N.U.T.S. proper, you must go through \
the \'gates\'",
  "universe",
  "You stare into the heavens because Softly said you should be able\nto see it all from here"
});

dest_dir = ({
  "/players/vital/dest/spaceport/rooms/gate.c","gates",
  });

  }
}

init() {
  ::init();
  add_action("move_out","exit");
  add_action("move_out","out");
  add_action("move_color","color");
  add_action("brae_button","brae");
}

brae_button(string str)
{
  if (!str && !present("brae",environment(this_player())))
    move_object(clone_object("/players/vital/misc/brae.c"), this_object());
  else
    move_object(clone_object("/players/vital/misc/brae02.c"), this_object());
  return 1;
}

move_out() {
  write("You find a way out....\n \n");
  TP->move_player("out the exit#/room/mount_top.c");
  return 1;
}

move_color() {
  write("You find a way out....\n \n");
  TP->move_player("out the exit#/players/vital/color/room/enter.c");
  return 1;
}

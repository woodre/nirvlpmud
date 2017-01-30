#include "/players/softly/misc/ansi.h"

inherit "/room/room";

reset(arg) {
  if(!present("ermine")) {
  move_object(clone_object("players/softly/winter/ermine"),this_object());
  }

  if(arg) return;
set_light(1);

short_desc = "Difficult Path";
long_desc ="  The path twists through the undergrowth.  Dead branches\n"+
           "and downed trees cover the faint trail.  Evergreens block\n"+
           "any distant view.  The trail appears to continue west and\n"+
           "northeast.\n";

items = ({
  "evergreens","Pines and firs dominate, with an occasional juniper",
  "path",  "The path is difficult to locate amidst the undergrowth",
  "trail", "Traces of a trail seem to lead west and northeast",
  "trees", "Although evergreens remain, the leafless dying branches\n"+
           "of once healthy trees cover the path",
  "undergrowth","Snarls of vines combine with dead tree branches",
  "branches","Broken branches and brambles cover what was once a trail",
  });

dest_dir = ({
  "/players/softly/winter/rooms/pond13.c","northeast",
  "/players/softly/winter/rooms/pond11.c","west",
  });
}

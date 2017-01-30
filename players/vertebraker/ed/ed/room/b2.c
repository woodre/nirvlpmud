#include "/players/vertebraker/define.h"
#include "/players/vertebraker/ed/paths.h"
inherit ROOM;
reset(arg) {
  if(arg) return;
  set_light(0);
  short_desc = "An earthen tunnel";
  long_desc =
"     Shadows dance against the wall as you proceed through the tunnel.\n"+
"The roughly-hewn stone walls are lightly covered with a filmy substance.\n"+
"A dim light has been lit to the northeast.  The piping and plumbing for\n"+
"the cabin hangs above your head.  A small movie projector has been\n"+
"discarded on the ground.\n";
  dest_dir = ({
ED1ROOM+"b3","northeast",
ED1ROOM+"b1","southeast",
});
  items = ({
"shadows","Dark shadows dance from the dim light as you walk through the terrain",
"walls","The stone walls have been dug out with some kind of sharp tool",
"substance","A filmy mildew covers the slightly moist walls",
"light","A dim light shines from the northeast",
"piping","The connection of pipes meet at a common point, which has been bound with a rag",
"rag","The rag is soaked with blood",
"projector","A medium-sized old-timey movie projector lies on the floor",
"mildew","The mildew can't be scraped off the wall",
});
  }

init() {
  ::init();
  add_action("search","search");
}

search(arg) {
    if(!arg) { write("Your general search of the area turns up nothing.\n"); return 1; }
    if(arg) { write("You search "+arg+", but you turn up nothing.\n"); return 1; }
    return 1; }

realm() { return "NT"; }

okay_follow() { return 1; }

#include "/players/vertebraker/define.h"
#include "/players/vertebraker/ed/paths.h"
inherit ROOM;
reset(arg) {
  if(arg) return;
  set_light(0);
  short_desc = "A fruit cellar";
  long_desc =
"     You stand in what appears to be a small fruit cellar- except that\n"+
"there are no preservables here.  In fact, the entire room reeks of mold,\n"+
"mildew, and moss. A little further down the tunnel, you can see a light.\n"+
"A set of stairs lead to an open trapdoor above.\n";
  dest_dir = ({
ED1ROOM+"c4","stairs",
ED1ROOM+"b2","northwest",
});
  items = ({
"light","A dim light can be seen to the northwest",
"stairs","Creaky wooden stairs lead up to the open trapdoor and the cabin",
"trapdoor","The thick wooden trapdoor lies open",
"tunnel","The earthen tunnel around you wraps and bends to the northwest",
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

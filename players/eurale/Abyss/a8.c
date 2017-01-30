#define tpn this_player()->query_name()
#define tp this_player()
#include "/players/eurale/closed/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = "The Abyss";
long_desc =
  "  You emerge from the darkness to find yourself in a luminescent\n"+
 RED+"red"+NORM+" space.  The entire atmosphere has taken on the color of blood\n"+
  "and there is a peculiar tenseness in the air.  You can feel your\n"+
  "heart pound in your chest and hear it like a drum in your ears.\n";

items = ({
});

dest_dir = ({
});

}

init() {
  ::init();
  add_action("east","east");
}

east() {
  tp->move_player("disappears#players/eurale/Abyss/a3.c");
  return 1; }

realm() { return "NT"; }

#define tp this_player()
#define tpn this_player()->query_name()
#include "/players/eurale/closed/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(-1);

short_desc = "A dark cellar";
long_desc =
  "This is a pitch black dirt cellar for hiding.\n";

items = ({
});

dest_dir = ({
});

}
init() {
  ::init();
  add_action("up","up");
}

up() {
tp->move_player("up#players/eurale/Fiend/pub.c"); return 1; }

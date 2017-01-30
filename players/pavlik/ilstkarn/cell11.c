#include <ansi.h>
inherit "room/room";

reset(arg) {
if(arg) {
  create_monster(this_object());
  return;
}
set_light(0);
short_desc="a cold dark Cell";
long_desc=
"You step into one of the dark prison cells of Arcydia's dungeon.  The\n"+
"cold, damp walls crowd you and you have to supress a feeling of\n"+
"clausterphobia.  The lingering stench of the cell's past victims\n"+
"attacks your senses.  You gaze through the iron bars of the cell's\n"+
"gate and see the relative safety of the dim corridor.\n";

dest_dir=({
 "/players/pavlik/ilstkarn/dungeon15", "east",
});

create_monster(this_object());

}

query_ilstkarn(){ return "cell11"; }
realm(){ return "NT"; }

init() {
  ::init();
  if(this_player()->is_player() && !random(4)) { 
    create_monster(this_object());
  }
}

okay_follow() { return 1; }

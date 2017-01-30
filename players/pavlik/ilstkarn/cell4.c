#include <ansi.h>
inherit "room/room";

reset(arg) {
if(arg) {
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
 "/players/pavlik/ilstkarn/dungeon9", "north",
});

if(!present("mad martin", this_object())) {
  move_object(clone_object("players/pavlik/monsters/ilstkarn/mad_martin"),
  this_object());
}

}

query_ilstkarn(){ return "cell4"; }
realm(){ return "NT"; }

init() {
  ::init();
  add_action("out","out");
}

out() {
  write("You leave the Dungeons of Ilstkarn.\n");
  this_player()->move_player("out#players/pavlik/ilstkarn/path6");
  return 1;
}

okay_follow() { return 1; }

#include <ansi.h>
inherit "room/room";
#define ME capitalize(this_player()->query_name())

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
"attacks your senses.  You notice alot of scuffled footprints on the\n"+
"dusty floor of this cell.\n";

dest_dir=({
 "/players/pavlik/ilstkarn/dungeon5", "east",
});

items=({
"footprints",
"An unusual amount of footprints are tracked across the dusty floor\n"+
"of the cell",
"floor",
"An unusual amount of footprints are tracked across the dusty floor\n"+
"of the cell",
});

create_monster(this_object());

}

query_ilstkarn(){ return "cell2"; }
realm(){ return "NT"; }

init() {
  ::init();
  if(this_player()->is_player() && !random(4)) { 
    create_monster(this_object());
  }
  add_action("search","search");
  add_action("crawl","crawl");
}

search() {
  int x;

  x = call_other(this_player(), "query_attrib", "luc");

  if(random(35) > x) {
    write("You don't find anything special.\n");
    say(ME+" searches the cell.\n");
    return 1;
  }
  else {
    write("You notice a small fizzure in the back wall of the cell.\n");
    write("The footsteps lead in and out of the tiny hole.\n");
    write("You might be able to crawl through the tiny space yourself.\n");
    say(ME+" searches the cell.\n");
    return 1;
  }
}

crawl() {
  if(present("ilstkarn_monster", this_object())) {
    write("This room is a little too crowded to be crawling around, dont ya think?\n");
    return 1;
  }
  write("You crawl through the tiny fizzure.\n");
  this_player()->move_player("out#players/pavlik/ilstkarn/dungeon_bar");
  return 1;
}

okay_follow() { return 1; }

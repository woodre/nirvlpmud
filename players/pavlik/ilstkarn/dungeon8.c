inherit "room/room";
#define POR "/players/pavlik/ilstkarn/ilstkarn_portal.c"
#define REALMSIZE 14

reset(arg) {
if(arg) {
  return;
}
set_light(0);
short_desc="In the Dungeons of Arcydia";
long_desc=
"You walk the narrow corridors of Arcydia's dungeons.  The cold dark\n"+
"prison cells of the fortress wait silently behind rusted bars.  The\n"+
"dark corridor continues east-west and there are prison cells to the\n"+
"north and south.\n";

dest_dir=({
 "/players/pavlik/ilstkarn/dungeon9", "east",
 "/players/pavlik/ilstkarn/dungeon7", "west",
 "/players/pavlik/ilstkarn/null", "north",
 "/players/pavlik/ilstkarn/null", "south",
 "/players/pavlik/ilstkarn/null", "out",
});

}

query_ilstkarn(){ return "dungeon8"; }
realm(){ return "NT"; }

init() {
  ::init();
  add_action("nope","south");
  add_action("nope","north");
  add_action("warp","west");
  add_action("out","out");
}

nope() {
  write("The cell is locked.\n");
  return 1;
}

warp() {
  if(!random(2)) {
    write("You feel disoriented for a moment...\n");
    this_player()->move_player("west#players/pavlik/ilstkarn/dungeon"+
    random(REALMSIZE));
  }
  else {
    this_player()->move_player("west#players/pavlik/ilstkarn/dungeon7");
  }
  return 1;
}

out() {
  write("You leave the Dungeons of Ilstkarn.\n");
  this_player()->move_player("out#players/pavlik/ilstkarn/path6");
  return 1;
}


okay_follow() { return 1; }

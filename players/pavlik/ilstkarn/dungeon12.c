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
"dark corridor continues north-south and there are prison cells to the\n"+
"east and west.\n";

dest_dir=({
 "/players/pavlik/ilstkarn/cell5", "east",
 "/players/pavlik/ilstkarn/cell6", "west",
 "/players/pavlik/ilstkarn/dungeon11", "north",
 "/players/pavlik/ilstkarn/dungeon13", "south",
 "/players/pavlik/ilstkarn/null", "out",
});

}

query_ilstkarn(){ return "dungeon12"; }
realm(){ return "NT"; }

init() {
  ::init();
  add_action("warp","south");
  add_action("out","out");
}

warp() {
  if(random(3)==1) {
    this_player()->move_player("south#players/pavlik/ilstkarn/dungeon13");
  }
  else {
    write("You feel disoriented for a moment...\n");
    this_player()->move_player("south#players/pavlik/ilstkarn/dungeon"+
    random(REALMSIZE));
  }
  return 1;
}

out() {
  write("You leave the Dungeons of Ilstkarn.\n");
  this_player()->move_player("out#players/pavlik/ilstkarn/path6");
  return 1;
}

nope() {
  write("The cell is locked.\n");
  return 1;
}


okay_follow() { return 1; }

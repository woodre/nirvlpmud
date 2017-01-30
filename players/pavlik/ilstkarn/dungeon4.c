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
"dark corridor continues east-north and there are prison cells to the\n"+
"west and south.\n";

dest_dir=({
 "/players/pavlik/ilstkarn/dungeon3", "east",
 "/players/pavlik/ilstkarn/null", "west",
 "/players/pavlik/ilstkarn/dungeon5", "north",
 "/players/pavlik/ilstkarn/null", "south",
});

}

query_ilstkarn(){ return "dungeon4"; }
realm(){ return "NT"; }

init() {
  ::init();
  add_action("nope","west");
  add_action("nope","south");
  add_action("warp","east");
}

nope() {
  write("The cell is locked.\n");
  return 1;
}

warp() {
  if(!random(2)) {
    write("You feel disoriented for a moment...\n");
    this_player()->move_player("east#players/pavlik/ilstkarn/dungeon"+
    random(REALMSIZE));
  }
  else {
    this_player()->move_player("east#players/pavlik/ilstkarn/dungeon3");
  }
  return 1;
}


okay_follow() { return 1; }

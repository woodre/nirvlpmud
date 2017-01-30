inherit "room/room";
#define SKEL "/players/pavlik/monsters/ilstkarn/skeleton"
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
 "/players/pavlik/ilstkarn/cell7", "east",
 "/players/pavlik/ilstkarn/null", "west",
 "/players/pavlik/ilstkarn/dungeon12", "north",
 "/players/pavlik/ilstkarn/dungeon0", "south",
});

}

query_ilstkarn(){ return "dungeon13"; }
realm(){ return "NT"; }

init() {
  ::init();
  add_action("nope","west");
  add_action("warp","north");

  if(!present("undead", this_object()) && !random(3)) {
    move_object(clone_object(SKEL), this_object());
  }
}

nope() {
  write("The cell is locked.\n");
  return 1;
}

warp() {
  if(random(4)==1) {
    this_player()->move_player("south#players/pavlik/ilstkarn/dungeon12");
  }
  else {
    write("You feel disoriented for a moment...\n");
    this_player()->move_player("south#players/pavlik/ilstkarn/dungeon"+
    random(REALMSIZE));
  }
  return 1;
}


okay_follow() { return 1; }

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
 "/players/pavlik/ilstkarn/dungeon1", "east",
 "/players/pavlik/ilstkarn/dungeon3", "west",
 "/players/pavlik/ilstkarn/null", "north",
 "/players/pavlik/ilstkarn/null", "south",
});

}

query_ilstkarn(){ return "dungeon2"; }
realm(){ return "NT"; }

init() {
  ::init();
  add_action("nope","north");
  add_action("nope","south");
}

nope() {
  write("The cell is locked.\n");
  return 1;
}


okay_follow() { return 1; }

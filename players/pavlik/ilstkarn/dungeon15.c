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
"prison cells of the fortress wait silently behind rusted bars.  A small\n"+
"point of light is visible further north.  The dark corridor continues\n"+
"north-south and there are prison cells to the east and west\n";

dest_dir=({
 "/players/pavlik/ilstkarn/null", "east",
 "/players/pavlik/ilstkarn/cell11", "west",
 "/players/pavlik/ilstkarn/dungeon16", "north",
 "/players/pavlik/ilstkarn/dungeon9", "south",
});

}

query_ilstkarn(){ return "dungeon15"; }
realm(){ return "NT"; }

init() {
  ::init();
  add_action("nope","east");
}

nope() {
  write("The cell is locked.\n");
  return 1;
}


okay_follow() { return 1; }

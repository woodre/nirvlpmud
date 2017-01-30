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
"dark corridor continues west-north and there are prison cells to the\n"+
"east and south.\n";

dest_dir=({
 "/players/pavlik/ilstkarn/null", "east",
 "/players/pavlik/ilstkarn/dungeon1", "west",
 "/players/pavlik/ilstkarn/dungeon13", "north",
 "/players/pavlik/ilstkarn/null", "south",
});

}

query_ilstkarn(){ return "dungeon0"; }
realm(){ return "NT"; }

init() {
  ::init();
  add_action("nope","east");
  add_action("nope","south");
}

nope() {
  write("The cell is locked.\n");
  return 1;
}


okay_follow() { return 1; }

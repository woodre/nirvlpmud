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
 "/players/pavlik/ilstkarn/dungeon0", "east",
 "/players/pavlik/ilstkarn/dungeon2", "west",
 "/players/pavlik/ilstkarn/null", "north",
 "/players/pavlik/ilstkarn/null", "south",
});

if(!find_living("dungeon_banshee")) {
  move_object(clone_object("players/pavlik/monsters/ilstkarn/banshee"),
  "players/pavlik/ilstkarn/dungeon"+random(14));
}

}

query_ilstkarn(){ return "dungeon1"; }
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

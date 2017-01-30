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
"prison cells of the fortress wait silently behind rusted bars.  A shaft\n"+
"of light beams in from the north.  The dark corridor continues north-\n"+
"south and there are prison cells to the east and west.  There is a\n"+
"tarnished SIGN on the eastern cell door.\n";

dest_dir=({
 "/players/pavlik/ilstkarn/null", "east",
 "/players/pavlik/ilstkarn/null", "west",
 "/players/pavlik/ilstkarn/dungeon17", "north",
 "/players/pavlik/ilstkarn/dungeon15", "south",
});

items=({
"sign",
"\n"+
"The sign reads:\n"+
"\n"+
"         Only one may Enter\n"+
"\n",
});

}

query_ilstkarn(){ return "dungeon16"; }
realm(){ return "NT"; }

init() {
  ::init();
  add_action("nope","west");
  add_action("go_cell12", "east");
}

nope() {
  write("The cell is locked.\n");
  return 1;
}

go_cell12() {
  if(("players/pavlik/ilstkarn/cell12")->query_owner()) {
    write("The door is locked, and will not open.\n");
    return 1;
  }
  else {
    this_player()->move_player("east#players/pavlik/ilstkarn/cell12");
    return 1;
  }
}


okay_follow() { return 1; }

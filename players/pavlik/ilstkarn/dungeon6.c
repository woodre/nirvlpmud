inherit "room/room";
#define SKEL "players/pavlik/monsters/ilstkarn/skeleton"
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
 "/players/pavlik/ilstkarn/dungeon14", "east",
 "/players/pavlik/ilstkarn/null", "west",
 "/players/pavlik/ilstkarn/dungeon7", "north",
 "/players/pavlik/ilstkarn/dungeon5", "south",
 "/players/pavlik/ilstkarn/null", "leave",
});

}

query_ilstkarn(){ return "dungeon6"; }
realm(){ return "NT"; }

init() {
  ::init();
  add_action("nope","west");
  add_action("leave","leave");

  if(!present("undead", this_object()) && !random(2)) {
    move_object(clone_object(SKEL), this_object());
  }
}

nope() {
  write("The cell is locked.\n");
  return 1;
}

leave() {
  tell_room(this_object(),
  capitalize(this_player()->query_real_name())+" leaves the realm.\n");
  move_object(this_player(), environment("players/pavlik/ilstkarn/ilstkarn_portal"));
  command("look", this_player());
  return 1;
}


okay_follow() { return 1; }

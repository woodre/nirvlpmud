inherit "room/room";
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
 "/players/pavlik/ilstkarn/dungeon11", "east",
 "/players/pavlik/ilstkarn/dungeon9", "west",
 "/players/pavlik/ilstkarn/null", "north",
 "/players/pavlik/ilstkarn/null", "south",
 "/players/pavlik/ilstkarn/null", "leave",
});

}

query_ilstkarn(){ return "dungeon10"; }
realm(){ return "NT"; }

init() {
  ::init();
  add_action("nope","north");
  add_action("nope","south");
  add_action("leave","leave");

  call_out("create_banshee", 3);
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

create_banshee() {
  if(find_living("bescinnalae")) {
    return 1;
  }
  else {
    tell_room(this_object(),
    "A ghostly apparition glides silently through the collidor walls.\n"+
    "Her beautiful incandescent form shimmers mysteriously.\n"+
    "The Banshee stares at you with sorrowful eyes.\n");
    move_object(clone_object("players/pavlik/monsters/ilstkarn/banshee"),
    this_object());
  }
  return 1;
}


okay_follow() { return 1; }

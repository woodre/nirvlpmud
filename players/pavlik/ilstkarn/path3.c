inherit "room/room";
#define POR "/players/pavlik/ilstkarn/ilstkarn_portal.c"
#define REALMSIZE 10 

reset(arg) {
  if(arg) {
	POR->create_monster(this_object());
  return;
  }
  set_light(1);
  short_desc="Somewhere in the Mountains of Ilstkarn";
  long_desc=
  "You have wandered deep into the Ilskarken Mountains.  Narrow trails\n"+
  "that brink the infinite plunge into darkness twist and coil through\n"+
  "the mysterious mountain range.  You know you must step carefully here,\n"+
  "because one false step could spell your demise.\n";

  dest_dir=({
	"/players/pavlik/ilstkarn/path0", "north",
	"/players/pavlik/ilstkarn/path2", "south",
	"/players/pavlik/ilstkarn/null", "leave",
  });
  POR->create_monster(this_object());
}

query_ilstkarn(){ return "path3"; }
realm(){ return "NT"; }

init(){
  ::init();
  add_action("leave","leave");
  if(this_player()->is_player() && !random(4)) { 
	POR->create_monster(this_object());
  }
}

leave() {
  write("You wisely decide to flee this evil realm.\n");
  say(capitalize(this_player()->query_real_name())+" scurries into the "+
  "magic portal.\n");
  move_object(this_player(), environment("players/pavlik/ilstkarn/ilstkarn_portal"));
  command("look", this_player());
  return 1;
}


okay_follow() { return 1; }

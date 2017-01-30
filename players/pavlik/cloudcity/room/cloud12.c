inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="The Cloud City";
  long_desc=
    "[Stratus St. & Horizon St.]\n"+
    "You are at the very heart of the Cloud City.  Tall gracefully buildings\n"+
    "reach into the sky all around you.  There streets are decorated with\n"+
    "artistic sculptures and paintings that have been all but destroyed by\n"+
    "the invading Orcs.  The sounds of battle rage around from all directions.\n"+
    "The town square, at the very center of the city, has been deserted.\n";

  dest_dir=({
	"players/pavlik/cloudcity/room/cloud17", "north",
	"players/pavlik/cloudcity/room/cloud13", "east",
	"players/pavlik/cloudcity/room/cloud7", "south",
	"players/pavlik/cloudcity/room/cloud11", "west",
  });

  call_out("monster_spawn", 15);
}

init() {
  ::init();
  if(this_player()->query_npc() && !this_player()->query_cloud_npc()) {
        tell_room(this_object(), capitalize(this_player()->query_name())+" falls through "+
                "the clouds and disappears.\n");
        move_object(this_player(), "room/void");
        destruct(this_player());
        return;
  }
}

monster_spawn() {
  if(present("orc_engineer", this_object())) {
	call_out("monster_spawn", 350);
	return 1;
  }
  move_object(clone_object("players/pavlik/cloudcity/mon/orc_engineer"), this_object());
  move_object(clone_object("players/pavlik/cloudcity/mon/orc_raider"), this_object());
  tell_room(this_object(), "An Orc emerges from a nearby building.\n");
  call_out("monster_spawn", 400 + random(400));
  return 1;
}

query_cloud_room() { return 1; }


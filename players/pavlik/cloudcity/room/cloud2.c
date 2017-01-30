inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="The Cloud City";
  long_desc=
    "[Mirro St. & Summer Ave.]\n"+
    "You are at the intersection on Mirro Street and Summer Avenue.  This\n"+
    "used to be a pleasant residential area of the Cloud City, but now the\n"+
    "buildings burn with the fires of war.  Your feet crunch across the\n"+
    "broken glass of once beautiful stained glass windows.\n";

  dest_dir=({
	"players/pavlik/cloudcity/room/cloud6", "north",
	"players/pavlik/cloudcity/room/cloud3", "east",
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
  tell_room(this_object(), "An Orc emerges from a nearby building.\n");
  call_out("monster_spawn", 400 + random(400));
  return 1;
}

query_cloud_room() { return 1; }


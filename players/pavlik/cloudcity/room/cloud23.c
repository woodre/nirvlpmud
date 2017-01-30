inherit "room/room";

reset(arg) {
  set_light(1);
  short_desc="The Cloud City";
  long_desc=
    "[Stratus St.]\n"+
    "You are at the north end of Stratus St.  The tall spires of the Ariel's\n"+
    "elegant buildings reach out to touch the sky in the south.  Looking any\n"+
    "other direction you discover the boundry of the Cloud City and see the\n"+
    "earth's surfance thoussands of feet below you.\n";

  items=({
    "clouds", "White puffy clouds make up the ground that you walk on",
  });

  dest_dir=({
    "/players/pavlik/cloudcity/room/cloud21", "south",
  });

  if(!present("fighter", this_object())) {
	int i;
	i = 2 + random(3);
	while(i > 0) {
		move_object(clone_object("players/pavlik/cloudcity/mon/orc_fighter"), this_object());
		i--;
	}
  }
  if(!present("ariel", this_object())) {
	move_object(clone_object("players/pavlik/cloudcity/mon/ariel_guard"), this_object());
	move_object(clone_object("obj/corpse"), this_object());
	present("corpse", this_object())->set_name("Ariel Guard");
  }

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

query_cloud_room() { return 1; }
clean_up() { return 1; }


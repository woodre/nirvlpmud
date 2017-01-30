inherit "room/room";

reset(arg) {
  set_light(1);
  short_desc="The Cloud City";
  long_desc=
    "[Aerle Ln. & Luminary Way]\n"+
    "You across the deserted intersection of Aerle and Luminary.  The clashing\n"+
    "sound of sword against sword can be heard all around you.  The houses\n"+
    "and buildings here have been barricaded and locked tight against the\n"+
    "invading enemy.\n";

  dest_dir=({
    "/players/pavlik/cloudcity/room/cloud14", "south",
    "/players/pavlik/cloudcity/room/cloud18", "west",
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


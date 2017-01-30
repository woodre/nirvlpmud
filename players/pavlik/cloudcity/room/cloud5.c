inherit "room/room";

reset(arg) {
  set_light(1);
  short_desc="The Cloud City";
  long_desc=
    "[Mirro St. & Luminary Way]\n"+
    "This part of the city has been deserted except for the invading Orcs and\n"+
    "the brave Ariel Guards that fight desperately to save their city.  The\n"+
    "small homes that line these streets are abandoned and dark.\n";

  dest_dir=({
    "/players/pavlik/cloudcity/room/cloud16", "east",
    "/players/pavlik/cloudcity/room/cloud10", "south",
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


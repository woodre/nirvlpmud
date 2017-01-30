inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="The Cloud City";
  long_desc=
    "[Mirro St. & Horizon St.]\n"+
    "Mirro and Horizon is one of the prosperous business districts of the\n"+
    "Cloud City.  The tall elegant buildings have now been stripped of their\n"+
    "delicate decorations.  You hear the sounds of a desperate battle coming\n"+
    "from inside a building on the north side of the street.\n";

  items = ({
    "building",
	"A tall building on the north side of the street looks dark and deserted,\n"+
	"however you hear the clash of sword against sword coming from within",
  });

  dest_dir=({
	"players/pavlik/cloudcity/room/cloud15", "north",
	"players/pavlik/cloudcity/room/cloud11", "east",
	"players/pavlik/cloudcity/room/cloud5", "south",
  });

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
  add_action("enter_building","enter");
}

enter_building(str) {
  if(str == "building") {
	write("You catiously enter the darkened building ... \n");
	this_player()->move_player("into the building#players/pavlik/cloudcity/room/building1");
	return 1;
  }
}

query_cloud_room() { return 1; }


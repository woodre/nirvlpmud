inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="The Cloud City";
  long_desc=
    "[Artisans St. & Jade St.]\n"+
    "Artisans Street was once home to the Ariel's open air market and\n"+
    "street festivals.  Now the street is littered with the remnants\n"+
    "of festive tents and fragile pottery.  A small tent remains upright\n"+
    "despite the violence of the battles that rage around it.\n";

  items=({
	"tent",
	   "Amazing this small tent still stands.  It is to dark to see inside,\n"+
	   "you will have to enter it if you wish to find out more",
  });

  dest_dir=({
	"players/pavlik/cloudcity/room/cloud13", "north",
	"players/pavlik/cloudcity/room/cloud9", "east",
	"players/pavlik/cloudcity/room/cloud4", "south",
	"players/pavlik/cloudcity/room/cloud7", "west",
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
  add_action("enter_tent","enter");
}

enter_tent(str) {
  if(str == "tent") {
	write("You brush the flap aside and enter the tent ... \n");
	this_player()->move_player("into the tent#players/pavlik/cloudcity/room/tent1.c");
	return 1;
  }
}

query_cloud_room() { return 1; }


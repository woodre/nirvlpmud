inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="The Cloud City";
  long_desc=
    "[Artisans St. & Horizon St.]\n"+
    "Artisans Street was once home to the Ariel's open air market and\n"+
    "street festivals.  Now the street is littered with the remnants\n"+
    "of festive tents and fragile pottery.  You see a large fountain\n"+
    "to the north.\n";

  dest_dir=({
	"players/pavlik/cloudcity/room/cloud18", "north",
	"players/pavlik/cloudcity/room/cloud14", "east",
	"players/pavlik/cloudcity/room/cloud8", "south",
	"players/pavlik/cloudcity/room/cloud12", "west",
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
}

query_cloud_room() { return 1; }


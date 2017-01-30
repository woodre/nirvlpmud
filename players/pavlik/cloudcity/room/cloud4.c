inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="The Cloud City";
  long_desc=
    "[Artisans St. & Summer Ave.]\n"+
    "Artisans Street was once home to the Ariel's open air market and\n"+
    "street festivals.  Now the street is littered with the remnants\n"+
    "of festive tents and fragile pottery.\n";

  dest_dir=({
	"players/pavlik/cloudcity/room/cloud8", "north",
	"players/pavlik/cloudcity/room/cloud3", "west",
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


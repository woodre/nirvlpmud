inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="The Cloud City";
  long_desc=
    "[Aerle Ln. & Horizon St.]\n"+
    "You are at the western edge of the Cloud City, in Aerle Park.  This\n"+
    "location is a favorite of the Ariels who wake early and watch the\n"+
    "sun rise over the Cloud City's horizon.  The intersection is furnished\n"+
    "with several park benches.\n";

  dest_dir=({
	"players/pavlik/cloudcity/room/cloud19", "north",
	"players/pavlik/cloudcity/room/cloud9", "south",
	"players/pavlik/cloudcity/room/cloud13", "west",
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


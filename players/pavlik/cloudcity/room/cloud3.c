inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="The Cloud City";
  long_desc=
    "[Stratus St. & Summer Ave.]\n"+
    "You are on Stratus Street.  This quiet neighborhood has been upended\n"+
    "by the ruthless invasion of the Orcs.  The small shops that line\n"+
    "Stratus Street have been gutted and burned.\n";

  dest_dir=({
	"players/pavlik/cloudcity/room/cloud7", "north",
	"players/pavlik/cloudcity/room/cloud4", "east",
	"players/pavlik/cloudcity/room/cloud1", "south",
	"players/pavlik/cloudcity/room/cloud2", "west",
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


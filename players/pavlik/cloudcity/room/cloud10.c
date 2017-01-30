inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="The Cloud City";
  long_desc=
    "[Pascal Ln. & Horizon St.]\n"+
    "You are at the western edge of the magnificent Horizon Street.  This\n"+
    "area was previously a serene park lined with trees and colorful flowers.\n"+
    "However, the peacefulness of the park has been ruined by the invasion\n"+
    "of the Orcs.\n";

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
}

query_cloud_room() { return 1; }


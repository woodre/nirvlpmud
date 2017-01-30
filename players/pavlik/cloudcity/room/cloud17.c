inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="The Cloud City";
  long_desc=
    "[Stratus St. & Luminary Way]\n"+
    "You are at the intersection and Stratus and Luminary.  Luminary Way\n"+
    "is decorated with numberous paper lanterns, must of which have been\n"+
    "torn down or destroyed by the battle raging throughout the city.  Those\n"+
    "lanterns remaining shed a soft warm light around you.\n";

  dest_dir=({
	"players/pavlik/cloudcity/room/cloud21", "north",
	"players/pavlik/cloudcity/room/cloud18", "east",
	"players/pavlik/cloudcity/room/cloud12", "south",
	"players/pavlik/cloudcity/room/cloud16", "west",
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


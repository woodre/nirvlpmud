inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="The Cloud City";
  long_desc=
    "[Mirro St. & Luminary Way]\n"+
    "You are on Luminary Way, also known by the Ariels as 'The River of Light'.\n"+
    "Fragile paper lanterns used to fill this street with warm soft light.  Now\n"+
    "the paper lanterns litter the ground, broken and torn.\n";

  dest_dir=({
	"players/pavlik/cloudcity/room/cloud20", "north",
	"players/pavlik/cloudcity/room/cloud17", "east",
	"players/pavlik/cloudcity/room/cloud11", "south",
	"players/pavlik/cloudcity/room/cloud15", "west",
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


inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="The Cloud City";
  long_desc=
    "[Artisans St. & Luminary Way]\n"+
    "Artisans and Luminary.  A giant fountain of wonderfully scupltured\n"+
    "stone occupies the center of this square.  The sculpture depicts a\n"+
    "flowery garden with numerous birds.  Cold water bubbles from the top\n"+
    "of the fountain and runs down its sides.  The water has been tinged\n"+
    "red with the blood of the Ariels.\n";

  dest_dir=({
	"players/pavlik/cloudcity/room/cloud22", "north",
	"players/pavlik/cloudcity/room/cloud19", "east",
	"players/pavlik/cloudcity/room/cloud13", "south",
	"players/pavlik/cloudcity/room/cloud17", "west",
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


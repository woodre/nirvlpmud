inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="The Cloud City";
  long_desc=
    "[Mirro St. & Iris Ave.]\n"+
    "This once-quiet part of the city has been upended by the invading Orcs.\n"+
    "The windows and doors of the buildings have been smashed in and red flames\n"+
    "burn within.  You hear the sounds of battle all around you.\n";

  dest_dir=({
	"players/pavlik/cloudcity/room/cloud21", "east",
	"players/pavlik/cloudcity/room/cloud16", "south",
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


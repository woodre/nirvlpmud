inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="The Cloud City";
  long_desc=
    "[Stratus St. & Jade St.]\n"+
    "You are at the intersection of Stratus and Jade.  Tall graceful buildings\n"+
    "tower above you.  Their doors and windows have been barricaded to keep\n"+
    "out the invading orcs.  The City's town square is to the north.\n";

  dest_dir=({
	"players/pavlik/cloudcity/room/cloud12", "north",
	"players/pavlik/cloudcity/room/cloud8", "east",
	"players/pavlik/cloudcity/room/cloud3", "south",
	"players/pavlik/cloudcity/room/cloud6", "west",
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


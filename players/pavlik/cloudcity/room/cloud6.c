inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="The Cloud City";
  long_desc=
    "[Mirro St. & Jade St.]\n"+
    "You stand amidst the chaos of invasion and war.  Orc and Ariel corpses\n"+
    "litter the once peaceful streets.  Even the women and children Ariels\n"+
    "have taken up swords to defend their treasured city.  The buildings\n"+
    "around you burn with the fires of war.\n";

  dest_dir=({
	"players/pavlik/cloudcity/room/cloud11", "north",
	"players/pavlik/cloudcity/room/cloud7", "east",
	"players/pavlik/cloudcity/room/cloud2", "south",
	"players/pavlik/cloudcity/room/cloud5", "west",
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


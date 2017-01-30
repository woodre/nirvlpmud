inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="The Cloud City";
  long_desc=
    "[Stratus St. & Iris Ave.]\n"+
    "You are at the intersection of Stratus and Iris.  The Cloud City's guard\n"+
    "barracks and city jail are located here.  The barracks are empty, since all\n"+
    "the guards have rushed out to defend the city.  The jail is also empty, its\n"+
    "heavy door creaks open and shut on rusted hinges.\n";

  items = ({
    "jail",
	"The city jail has seen very little use over the years.  The Ariels rarely\n"+
	"have reason to incarcerate anyone.  The door is open",
  });

  dest_dir=({
	"players/pavlik/cloudcity/room/cloud23", "north",
	"players/pavlik/cloudcity/room/cloud22", "east",
	"players/pavlik/cloudcity/room/cloud17", "south",
	"players/pavlik/cloudcity/room/cloud20", "west",
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
  add_action("enter_jail","enter");
}

enter(str) {
  if(str == "jail") {
	this_player()->move_player("into the jail#players/pavlik/cloudcity/room/jail1");
	return 1;
  }
}

query_cloud_room() { return 1; }


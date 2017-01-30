inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Inside the Tent";
  long_desc=
     "You are nearly knocked unconcious upon first entering the small tent!\n"+
     "A heavy, foul smelling aroma assualts your senses.  A purple haze\n"+
     "lingers in the air.  On the floor of the tent sits a large complicated\n"+
     "contraption.  It seems to be brewing and mixing some sort of liquid.\n";

  items=({
     "contraption",
	"The contraption is a series of twisting glass tubes, dripping funnels,\n"+
	"and a series of tiny burners.  A purplish liquid flows through the maze\n"+
	"of tubes and funnels",
  });

  dest_dir=({
	"players/pavlik/cloudcity/room/cloud8", "out",
  });

  if(!present("ariel_alchemist", this_object())) {
	move_object(clone_object("players/pavlik/cloudcity/mon/ariel_alchemist"), this_object());
  }

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


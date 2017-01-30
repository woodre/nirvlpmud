inherit "room/room";
int i;
reset(arg) {
         if(!present("rider"))
          move_object(clone_object("players/rumplemintz/mon/horse/hrider"), this_object());
        if(!arg) {
                set_light(1);
         short_desc = "Horse Lords' Kingdom entrance";
        long_desc = "     This is the entrance to the Kingdom of the Horse Lords.  There\n"+
                "is a Horseback Rider guarding the gates, you need not kill him, but it\n"+
                "might prove fruitful to do so.  Then again it might not.\n";

        dest_dir = ({
		"players/rumplemintz/room/hlanding", "southeast",
                });

        }
}

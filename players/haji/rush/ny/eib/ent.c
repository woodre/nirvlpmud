inherit "room/room";
reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Entrance to the EIB building";
    long_desc = 
      "You are in the hallowed entrance to the EIB(Excellence in Broadcasting)\n " +
      "building.  This is the home of the mighty Rush Limbaugh, where he spreads\n " +
      "the word about the falsehoods that the current administration and others\n" +
      "insist on spreading.  His views are being broadcast to an ever expanding\n" +
      "audience and will soon overwhelm the opposition.\n" +
      "To the west you see the radio room where he broadcasts his radio show daily.\n" +
      "To the west you see the very studio in which Rush makes his television\n " +
      "appearance each day.  Unfortunately, to the north is the entrance\n" +
      "to the rest of New York city home of many many insane liberals.\n";
    dest_dir = ({"players/haji/rush/ny/wstreet1", "north",
		 "players/haji/rush/ny/eib/tv1", "east",
                 "players/haji/rush/ny/eib/radio", "west",
                  });
}


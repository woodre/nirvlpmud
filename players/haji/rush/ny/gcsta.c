inherit "room/room";
reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Grand central station";
    long_desc = 
        "You are in Grand central station in New York,home of the great\n" +
    "Rush Limbaugh. To leave New York go southeast, to see Rush go west,\n" +
      "and to see some interesting characters go east.\n" +
      "NOTE:  Many things in this city will not take coins to buy them.\n" +
      "       You will need to go to the welfare office located on the\n" +
      "       northeast side of town and exchange your money for some\n" +
      "       welfare checks. You can thank the federal government for turning\n" +
      "       us into a welfare state.\n";
    dest_dir = ({"room/eastroad3", "southeast",
		 "players/haji/rush/ny/estreet2", "east",
		 "players/haji/rush/ny/wstreet3", "west"});
}


inherit "room/room";
reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Entrance to a run down military base";
    long_desc = 
      "This is the entrance to an old run down military base.\n" +
      "This place is run down due to lack of funding from government.\n" +
      "The country will soon be run over by all kinds of liberal scum.\n" +
      "NOTE:  Many things in this city will not take coins to buy them.\n" +
      "       You will need to go to the welfare office located on the\n" +
      "       northeast side of town and exchange your money for some\n" +
      "       welfare checks. You can thank the federal government for turning\n" +
      "       us into a welfare state.\n";
    dest_dir = ({"room/orc_dump", "southwest",
		 "players/haji/rush/nb/per6", "south"});
}


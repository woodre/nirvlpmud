inherit "room/room";
reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc="TV broadcast room for the Rush Limbaugh show";
    long_desc = 
                "This is the tv broadcast room for the Rush Limbaugh show.\n" +
                "Just standing in this room makes you feel better.\n" +
                "In the easterly direction is the ditto heads themselves,\n" +
                "to the northeast their is the control room.\n" +
                "To the west you see the entrance to the EIB building.\n";
    dest_dir = ({"players/haji/rush/ny/eib/ent", "west",
                 "players/haji/rush/ny/eib/audi", "east",
                 "players/haji/rush/ny/eib/conroom", "northeast",
                  });
}


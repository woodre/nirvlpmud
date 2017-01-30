inherit "room/room";
reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc="Radio broadcast room for the Rush Limbaugh show";
    long_desc = 
                "This is the radio broadcast room for the Rush Limbaugh show.\n" +
                "Just standing in this room makes you feel better.\n" +
                "To the east you see the entrance to the EIB building.\n";
    dest_dir = ({"players/haji/rush/ny/eib/ent", "east",
                  });
}


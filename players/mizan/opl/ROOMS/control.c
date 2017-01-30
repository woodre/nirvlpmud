inherit "/room/room.c";

void reset(int arg)
{
    if (arg) return;
    set_light(1);

    short_desc = "Control Room of the OverPowerLord";
    long_desc =
        "    This is a large, sparsely furnished room which is impeccably clean\n"+
        "  and surprisingly well lit. On the far side are a series of equipment\n"+
        "  racks housing what appear to be servers and other electronic devices.\n"+
        "  Right near you there are some nice, comfortable lounge chairs to sit\n"+
        "  on and relax, away from the hubbub in the lounge area.\n";

    items = ( {

        "floor",
        "The floor appears to be made of some fairly high quality bathroom tile.",

    });

    dest_dir =
    ( {
        "/players/mizan/opl/ROOMS/lounge.c", "west",
    });

    set_no_clean(1);
}

init()
{
    ::init();
}


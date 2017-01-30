inherit "players/mizan/closed/RandomRoom.c";

reset(arg) 
{
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc="Plane of Etheriel";
    long_desc="\tDrifting into this area, you are almost clocked in the head\n"+
    "  by a steamroller that is caught in the ether-muck. It looks so silly\n"+
    "  though, it's engine still running, and sending any of the 'creatures'\n"+
    "  that float too close to it into a mild panic, yourself included.\n"+
    "  Suddenly, it disappears. You are left in a mild bogglement.\n";
}

extra_reset() 
{
    object_names=({
        "players/mizan/etheriel/beasties/zed.c",
        "players/mizan/etheriel/beasties/rungkaurai.c",
        "players/mizan/etheriel/beasties/beano.c",
        "players/mizan/etheriel/beasties/redneck-will.c",
        "players/mizan/etheriel/beasties/spud.c"
    });
    ::extra_reset();
}

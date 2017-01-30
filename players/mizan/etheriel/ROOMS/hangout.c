inherit "players/mizan/closed/RandomRoom.c";

reset(arg) 
{
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc="Plane of Etheriel";
    long_desc="\tYou suddenly feel a bit weighted down, as a force familiar to\n"+
    "  you begins to ensnare you and drag you to a certain point. That\n"+
    "  mysterious force is gravity, which hitherto only existed here as an\n"+
    "  inconsistently active and playful iteration.\n";
}

extra_reset() 
{
    object_names=({
        "players/mizan/etheriel/environs/poster.c",
        "players/mizan/etheriel/environs/moosh-counter.c",
        "players/mizan/etheriel/beasties/zok.c",
        "players/mizan/etheriel/beasties/blinking-oofa.c",
        "players/mizan/etheriel/environs/steamroller.c"
    });
    ::extra_reset();
    if(1==random(700)) 
    {
        move_object(clone_object("players/mizan/etheriel/heals/portable_cow.c"), this_object());
    }
}

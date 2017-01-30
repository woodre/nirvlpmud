inherit "players/mizan/closed/RandomRoom.c";

reset(arg) 
{
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "Plane of Etheriel";
    long_desc = "\tDespite the absence of the laws that govern nature as you know\n"+
                "  it, you are starting to adjust quite comfortably to the way things seem\n"+
                "  to tick around 'here'. It takes a sense of 'randomness', and a\n"+
                "  willingness on your behalf to set free all of your inhibitions...\n";
}

extra_reset() 
{
    object_names = ({
        "players/mizan/etheriel/beasties/colormonger.c",
        "players/mizan/etheriel/beasties/wub.c",
        "players/mizan/etheriel/beasties/rungkaurai.c",
        "players/mizan/etheriel/items/rotten-sausage.c",
        "players/mizan/etheriel/items/uranium-238.c",
    });
    ::extra_reset();

    if(1==random(60)) 
    {
        move_object(clone_object("players/mizan/etheriel/items/trick-brick.c"), this_object());
    }
}

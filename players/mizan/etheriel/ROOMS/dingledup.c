inherit "players/mizan/closed/RandomRoom.c";

reset(arg) 
{
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc="Plane of Etheriel";
    long_desc="\tPhysics takes on a whole new meaning here, as you already know.\n"+
    "  Somewhere in the near distance you see a sort of explosion occur, and\n"+
    "  radiating from it in a semi-elliptical sort of manner is a ring of\n"+
    "  shockwaves. When it hits you, a painfully loud organic noise slams you\n"+
    "  with enough force to push you in a direction, but leaves your eardrums\n"+
    "  intact and head ring-free. In the 'normal' world, you would have died!\n";
}

extra_reset() 
{
    object_names=({
        "players/mizan/etheriel/beasties/punk.c",
        "players/mizan/etheriel/beasties/lost-wombat.c",
        "players/mizan/etheriel/beasties/punk.c",
        "players/mizan/etheriel/beasties/beano.c",
        "players/mizan/etheriel/items/duffel-bag.c",
    });

    ::extra_reset();
    if(1==random(3)) 
    {
        move_object(clone_object("players/mizan/etheriel/items/blockbuster.c"), this_object());
    }
}

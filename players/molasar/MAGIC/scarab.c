

inherit "obj/armor";

reset(arg) {
    if(!arg)
    ::reset(arg);
    set_alias("scarab of insanity");
    set_name("scarab");
    set_short("A black scarab");
    set_long("Something just doesn't feel right about this scarab.\n");
    set_type("amulet");
    set_ac(1);
    set_weight(3);
    set_value(10);
}

wear(str) {
     call_out("move_function",5);
     return 1;
}

move_function() {
    string me;
    me = this_player()->query_name();

    say(capitalize(me)+" screams and starts jumping around in circles.\n");

    say(capitalize(me)+" shouts:  GET THEM OFF ME!!! AARRRGGGHHHH!!!!\n");
    write("You scream and act very childishly.\n");
    write("You see giant tourqoise giraffes charging towards you "+
          "yelling 'wakka wakka'.\n");
    say(capitalize(me)+" screams:  GET THE TOURQOISE GIRAFFES OFF ME!!!\n");
    say(capitalize(me)+" soils the ground.\n");
    write("You feel your bodily functions let go.\n");
    say(capitalize(me)+" heads off for parts unknown.\n");
    this_player()->run_away();
    call_out("move_function",random(10), 0);
    return 1;
}

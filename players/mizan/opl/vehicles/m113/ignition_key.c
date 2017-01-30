inherit "/players/mizan/core/object.c";

reset(arg)
{
    ::reset(arg);
    if (arg) return;

    set_get(1);
    set_value(100);
    set_weight(1);
    set_name("key");
    set_alias("m113_enginekey");
    set_short("An M113 ignition key");
    set_long("This is a small metal key with the letters 'FMC' stamped on it.\n");
}


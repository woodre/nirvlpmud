inherit "/players/mizan/core/object.c";

reset(arg)
{
    ::reset(arg);
    if (arg) return;

    set_get(1);
    set_value(100);
    set_weight(1);
    set_name("key");
    set_alias("tiger1_enginekey");
    set_short("A Tiger 1 ignition key");
    set_long("This is a small metal key with some German written on it, and a serial number.\n");
}


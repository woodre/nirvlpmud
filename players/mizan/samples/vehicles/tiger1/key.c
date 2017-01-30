inherit "/players/mizan/core/object.c";

reset(arg)
{
    ::reset(arg);
    if(arg) return;

    set_get(1);
    set_value(100);
    set_weight(1);
    set_name("key");
    set_alias("tiger1_key");
    set_short("A small metal door key");
    set_long("This a small metal key, with a serial number written on it.\n");
}


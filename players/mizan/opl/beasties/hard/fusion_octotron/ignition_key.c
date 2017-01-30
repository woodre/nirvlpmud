inherit "/players/mizan/core/object.c";

reset(arg)
{
    ::reset(arg);
    if(arg) return;

    set_get(1);
    set_value(100);
    set_weight(1);
    set_name("key");
    set_alias("fusion_octotron_enginekey");
    set_short("A solid steel ignition key");
    set_long("This is a solid steel key with the number '8' engraved on it.\n");
}


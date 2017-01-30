inherit "/players/mizan/core/object.c";

reset(arg)
{
    ::reset(arg);
    if(arg) return;

    set_get(1);
    set_value(100);
    set_weight(1);
    set_name("key");
    set_alias("fusion_octotron_key");
    set_short("A solid steel door key");
    set_long("This a well constructed key, with the number '8' prominently\n" +
             "engraved on one side of it. It is surprisingly thick and heavy.\n");
}


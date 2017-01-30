inherit "/players/mizan/core/object.c";

reset(arg)
{
    ::reset(arg);
    if(arg) return;

    set_get(1);
    set_value(5);
    set_weight(1);
    set_name("key");
    set_alias("Key");
    set_short("An ignition key");
    set_long(" This is an ignition key for a car. It's a duplicate but the car might\n"+
"be some sort of used semi-compact vehicle.\n");
}

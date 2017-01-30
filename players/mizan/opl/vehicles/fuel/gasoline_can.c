inherit "/players/mizan/core/object.c";

reset(arg)
{
    ::reset(arg);
    if (arg) return;

    set_get(1);
    set_value(100);
    set_weight(10);
    set_name("tank");
    set_alias("gasoline_fuel");
    set_short("A 5 gallon plastic tank of gasoline");
    set_long("This is a large, heavy tank filled with gasoline. It is roughly 5 gallons\n"+
             "in capacity. Presumably, vehicles can utilize this fuel somehow.\n");
}

query_fuel() {
    return 12;
}

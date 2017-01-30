inherit "/players/mizan/core/object.c";

reset(arg)
{
    ::reset(arg);
    if (arg) return;

    set_get(1);
    set_value(100);
    set_weight(10);
    set_name("can");
    set_alias("diesel_fuel");
    set_short("A large can of diesel fuel");
    set_long("This is a large, heavy can filled with diesel. It is roughly 5 gallons\n"+
             "in capacity. Presumably, vehicles can utilize this fuel somehow.\n");
}

query_fuel() {
    return 12;
}

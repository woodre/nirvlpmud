inherit "/players/mizan/core/object.c";

reset(arg)
{
    ::reset(arg);
    if (arg) return;

    set_get(1);
    set_value(100);
    set_weight(10);
    set_name("drum");
    set_alias("tiger1_fuel");
    set_short("A 55 gallon oil drum");
    set_long("This is a large, heavy tank filled with petrol, instead of oil for some reason.\n"+
             "You wonder what the hell could possibly consume all this fuel in one shot!\n");
}

query_fuel() {
    return 10;
}
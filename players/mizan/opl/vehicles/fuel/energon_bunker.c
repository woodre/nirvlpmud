inherit "/players/mizan/core/object.c";

reset(arg)
{
    ::reset(arg);
    if (arg) return;

    set_get(1);
    set_value(1000);
    set_weight(20);
    set_name("bunker");
    set_alias("energon_fuel");
    set_short("An energon bunker");
    set_long("This is a large, solid stainless steel container filled with a mysterious\n"+
             "liquid called 'energon'. A warning sticker indicates that you should not open\n"+
             "the cap for long periods, and that risk of shock from electrical current\n"+
             "within the fluid is highly likely.\n");
}

query_fuel() {
    return 50;
}

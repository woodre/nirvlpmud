inherit "obj/monster";

reset(arg)
{
    if (arg) return;
    ::reset(arg);
    set_name("meanie");
    set_level(9);
    set_aggressive(1);
    set_ac(7);
    set_wc(13);
    set_al(-100);
    set_alias("blue");
    set_short("A Blue Meanie");
    set_long("The Blue Meanie hates everything that is good.\n"+
             "He crushes flowers for kicks !\n");
}

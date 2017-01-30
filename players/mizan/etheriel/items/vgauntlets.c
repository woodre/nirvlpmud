inherit "obj/armor";

reset(arg)
{
    ::reset(arg);
    if(arg) return;
    set_name("vapor gauntlets");
    set_short("Vapor Gauntlets");
    set_long("These gloves are really funky because when you put them\n"+
    "on, and touch things, there seems to be a gap of thin air between\n"+
    "your fingers, and whatever you are touching...\n");
    set_value(800);
    set_ac(1);
    set_type("misc");
    set_alias("gauntlets");
}

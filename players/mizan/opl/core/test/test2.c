inherit "/players/mizan/opl/core/slugthrower-ammo.c";

reset(arg)
{
    if(arg) return;
    ::reset(arg);

    set_alias("clip");
    set_name("generic 9.64mm rounds");
    set_short("A clip of generic 9.64mm rounds");
    set_long("This is ammo.\n");

    set_ammo_name("generic 9.64mm rounds")
    set_simple_name("a 9.64mm round");
    set_single_short("a 9.64mm round");
    set_plural_short("9.64mm rounds");
    set_type("generic");   
 
    set_rounds(35);
    set_value(200);
    set_weight(2);
    set_power_index(0);
}

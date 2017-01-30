inherit "/players/mizan/core/vehicle-primarygun.c";

reset(arg)
{
    string temp;

    if(arg) return;
    ::reset(arg);

    set_name("Cannon");
    set_alias("cannon");
    set_short("A KwK 88mm anti-tank cannon (Model 36 L/56)");

    temp = "    This is a remarkable piece of weapon, forged from fine blued steel and built\n"+
        "  with not only the looks to kill but the ability to do so. It has a barrel\n"+
        "  diameter of 88mm and is the premier primary weapon of the Wehrmacht.\n";

    set_long(temp);

    set_breech_id("breech");

    set_ammo_id("88mm-shells");
    set_trigger_id("trigger"); 

    set_barrel_overheat_threshold(4);
    set_barrel_overheat_redline(5);
    set_barrel_overheat_chance(80);

    set_barrel_cooloff_interval(90);

    set_empty_casing_filename("/players/mizan/samples/vehicles/tiger1/shell-casing.c");

}
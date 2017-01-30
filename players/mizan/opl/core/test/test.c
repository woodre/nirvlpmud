inherit "/players/mizan/opl/core/slugthrower.c";


reset(arg) 
{
    if(arg) return;
    ::reset(arg);

    set_name("assault rifle");
    set_short("A GPSD C19 'Saint' assault rifle");
    set_alias("rifle");
    set_class(18);
    set_weight(4);
    set_value(13000);

    set_long("This is a bitchin' weapon. It is meant to bash people's heads in,\n"+
            "not sit forlornly in a fireplace or a gun rack.\n");

    set_clip_id("9.64mm");
    set_clip_name("clip");
    set_bayonet_id("bayonet_c19");
    set_bayonet_name("bayonet");
    set_damage_type("other|gunfire");
    set_no_ammo_wc(15);


    set_hit_func(this_object());
    set_round_base_damage(10);
    set_round_rand_damage(10);

    set_bayonet_usable(1);
    set_no_ammo_usable(1);

}


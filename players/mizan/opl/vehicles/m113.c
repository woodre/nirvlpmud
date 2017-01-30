inherit "/players/mizan/core/vehicle.c";

/*
 * our reset method
 *
 */
reset(arg)
{
    string tmp_ldesc;
    string tmp_long;
    object bin;
    object bin02;

    tmp_ldesc = "    You are inside the cramped confines of an M113 armored personnel\n";
    tmp_ldesc+= "  carrier. There is not enough room to stand up, and despite the best\n";
    tmp_ldesc+= "  efforts of the constantly flickering incandescent lighting, it is\n";
    tmp_ldesc+= "  frustratingly dark and claustrophobic inside this vehicle.\n";
    tmp_ldesc+= "  There is also a faint smell of vinegar coming from the hastily cleaned\n";
    tmp_ldesc+= "  surfaces inside. You wonder what that is all about.\n";


    tmp_long = "    The M113 is a reliable but ungainly tracked vehicle which is competent\n";
    tmp_long += "  at what it does- it is a giant aluminum box with tracks that serves as a\n";
    tmp_long += "  taxi for soldiers on the battlefield. Despite what some detractors may say\n";
    tmp_long += "  and its obvious lack of sexiness since it has no turret or the menacing look\n";
    tmp_long += "  of some of its Russian or Chinese peers, it's been around since the 1960's\n";
    tmp_long += "  and still soldiers on in its role as a battle taxi. This particular model\n";
    tmp_long += "  is pretty beaten up and worn, but otherwise looks to be in decent shape.\n";

    ::reset(arg);

    if (arg) return;


    set_name("M113 armored personnel carrier");
    set_race("m113");
    set_alias("carrier");
    set_short("An M113 armored personnel carrier");
    set_long(tmp_long);
    set_level(10);
    set_hp(800);
    set_al(0);
    set_wc(3);
    set_ac(30);
    set_aggressive(0);
    set_hatch_id("hatch");
    set_maximum_fuel(50);
    set_maximum_occupants(8);

    set_key_id("m113_key");
    set_engine_key_id("m113_enginekey");
    set_fuel(50);
    set_fuel_id("diesel_fuel");
    set_inside_short_desc("Inside an M113 armored personnel carrier");
    set_inside_long_desc(tmp_ldesc);
    set_exit_mess("leaves with tracks clanking, rumbling");
    set_enter_mess("arrives, its tracks clanking and squeaking loudly.");

    set_engine_startup_message("The M113's diesel engine starts up with a clunky roar!\nRumble rumbla rumble rumbla rumble...\n");
    set_engine_stop_message("The M113's diesel engine cuts out with loud sputter.\nSuddenly, there is silence...\n");

    set_fuel_idle_consumption(20);
    set_fuel_overflow_mess("The tank is full, and some extra diesel fuel gushes out.\n");

    enable_horn();
    set_horn_verb("honk");
    set_horn_mess("The M113's horn goes off! Beep! Beep!\nYou wonder why a tank has a horn, when it really doesn't need one.\n");


    enable_headlights();
    set_battery_id("m113_battery");

    set_headlight_consumption(40);
    set_maximum_battery(50);


    if (!bin) bin = move_object(clone_object("/players/mizan/opl/vehicles/m113/storage_bin.c"), this_object());


    if (bin)
    {
                move_object(clone_object("/players/mizan/etheriel/items/shit.c"), bin);
/* Added a manual... Rumplemintz */
      move_object(clone_object("/players/mizan/opl/vehicles/m113/manual.c"),
                  bin);
    }


    move_object(clone_object("/players/mizan/opl/vehicles/fuel/diesel_can.c"), this_object());

    /* an array of engine noise messages */
    arr_engine_chat_mess = ( {
        "The rumble of the M113's diesel engine is driving you nuts.",
        "Smoke billows from the exhaust port of the armored personnel carrier.",
    });

    set_idle_chat_chance(1);
    set_engine_chat_chance(2);
}
/* end function reset(); */



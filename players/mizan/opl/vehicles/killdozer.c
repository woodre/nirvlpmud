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


    tmp_ldesc = "    You are inside the legendary Panzerkampfwagen VI, the 'Tiger 1'.\n";
    tmp_ldesc += "  main battle tank of the German army during WWII. This particular\n";
    tmp_ldesc += "  vehicle is a restored copy, and despite its hulking size when outside\n";
    tmp_ldesc += "  the inside appears to be fairly cramped, only fitting five people\n";
    tmp_ldesc += "  onboard, and even then it seems barely so.\n";

    tmp_long = "    You look at the impressive Panzerkampfwagen VI, the 'Tiger 1' tank.\n\n";
    tmp_long += "  This a massive beast of a tank, 62 tons of armored steel and one of the\n";
    tmp_long += "  most feared of all main battle tanks in World War II. The Tiger, as it\n";
    tmp_long += "  was most commonly known had an awesome combat record and was an absolute\n";
    tmp_long += "  terror to deal with on any level.\n\n";
    tmp_long += "  This particular tank appears to be a completely new restored copy of the\n";
    tmp_long += "  original Tiger 1, down to its convincing 'Zimmerit' antimagnetic mine coating.\n";

    ::reset(arg);

    if (arg) return;


    set_name("Killdozer");
    set_race("killdozer");
    set_alias("bulldozer");
    set_short("A heavily modified Komatsu D355A bulldozer (Killdozer)");
    set_long(tmp_long);
    set_level(10);
    set_hp(1200);
    set_al(0);
    set_wc(3);
    set_ac(30);
    set_aggressive(0);
    set_hatch_id("hatch");
    set_maximum_fuel(200);
    set_maximum_occupants(5);

    set_key_id("killdozer_key");
    set_engine_key_id("killdozer_enginekey");
    set_fuel(40);
    set_fuel_id("diesel_fuel");
    set_inside_short_desc("Inside the Komatsu Killdozer");
    set_inside_long_desc(tmp_ldesc);
    set_exit_mess("leaves with tracks clanking, rumbling");
    set_enter_mess("arrives, its tracks clanking and squeaking loudly.");

    set_engine_startup_message("The Killdozer starts its massive diesel engine with a deafening roar!\nRumble rumbla rumble rumbla rumble...\n");
    set_engine_stop_message("The Killdozer's engine comes to a halt.\nSuddenly, there is silence...\n");

    set_fuel_idle_consumption(15);
    set_fuel_overflow_mess("The tank is full, and some extra diesel fuel gushes out.\n");

    enable_horn();
    set_horn_verb("honk");
    set_horn_mess("A blistering air horn goes off with a deafening belch! \nMarvin, you sick bastard. You added an air horn to a bulldozer!\n");


    enable_headlights();
    set_battery_id("killdozer_battery");

    set_headlight_consumption(20);
    set_maximum_battery(50);


    if (!bin) bin = move_object(clone_object("/players/mizan/samples/vehicles/tiger1/storage_bin.c"), this_object());
    if (!bin02) bin02 = move_object(clone_object("/players/mizan/samples/vehicles/tiger1/storage_bin02.c"), this_object());


    move_object(clone_object("/players/mizan/opl/vehicles/fuel/diesel_can.c"), this_object());
    move_object(clone_object("/players/mizan/opl/vehicles/fuel/diesel_can.c"), this_object());

    /* an array of just idle messages */
    arr_idle_chat_mess = ( {
        "You wince in fear, just looking at the massive armored hull of the Tiger.",
        "The Tiger 1 tank seems to be immovable, just sitting there on its own.",
        "You get the chills, noticing that this particular Tiger I tank seems to be... BRAND NEW!",
    });

    /* an array of engine noise messages */
    arr_engine_chat_mess = ( {
        "The rumble of the Tiger's Maybach petrol engine makes you quiver in fear.",
        "RUMBLA-RUMBLE-RUMBLA...\nThe Tiger's engine idles noisily.",
    });

    set_idle_chat_chance(1);
    set_engine_chat_chance(2);
}
/* end function reset(); */


delayed_reset()
{
    ::delayed_reset();
/*
    move_object(clone_object("/players/mizan/samples/vehicles/tiger1/cannon.c"), this_object());
*/
}

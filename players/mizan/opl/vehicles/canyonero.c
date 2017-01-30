inherit "/players/mizan/opl/core/vehicle.c";

/*
 * our reset method
 *
 */
reset(arg)
{
    string temp_long_desc;
    string temp_long;
    object bin;

    temp_long_desc = "    You are inside the biggest goddamn vehicle you have ever seen.\n";
    temp_long_desc += "  A barbeque, basketball game, and round of golf could probably all.\n";
    temp_long_desc += "  happen inside here AT THE SAME TIME. This is none other than the\n";
    temp_long_desc += "  legendary Canyonero! The gigantic leather seats stretch on for what\n";
    temp_long_desc += "  appears to be an eternity. You feel incredibly... small.\n";

    temp_long = "    This is the biggest damn sports utility vehicle you have ever seen.\n";
    temp_long += "  It is twelve yards long, two lanes wide, and 65 tons of American pride...\n";
    temp_long += "  The Canyonero!\n\n";
    temp_long += "  This thing has incredibly bright lights, sits several feet taller than most\n";
    temp_long += "  airplane hangars, and probably could plow through several herds of deer\n";
    temp_long += "  without too much of a problem... plus it smells oddly of steak.\n";

    ::reset(arg);

    enable_commands();
    set_heart_beat(1);

    if(arg) return;

    set_name("Canyonero");
    set_race("suv");
    set_alias("canyonero");
    set_short("The Canyonero");
    set_long(temp_long);
    set_level(10);
    set_hp(1000);
    set_al(0);
    set_wc(3);
    set_ac(30);
    set_aggressive(0);
    set_hatch_id("door");
    set_maximum_fuel(200);
    set_maximum_occupants(12);

    set_key_id("canyonero_key");
    set_engine_key_id("canyonero_enginekey");
    set_fuel(85);
    set_fuel_id("gasoline_fuel");
    set_inside_short_desc("Inside the Canyonero");
    set_inside_long_desc(temp_long_desc);
    set_exit_mess("leaves with DEAFENING rumble");
    set_enter_mess("arrives, lights blaring, horn blasting... 'Canyonero!'");

    set_engine_startup_message("The Canyonero's engine starts with a VROOOOOM sound not quite\nunlike that of a small power station firing up.\n");
    set_engine_stop_message("The Canyonero's engine stops with a grinding WHOOSH.\nA faint weeping sound can be heard from OPEC nations.\n");

    set_fuel_idle_consumption(20);
    set_fuel_overflow_mess("The tank is full, and some extra fuel gushes out.\n");

    enable_horn();
    set_horn_verb("honk");
    set_horn_mess("The Canyonero's horn goes off...\n WHOMP!! WHOMP!! WHOOOOOOOOMP!!\n");

    /* an array of just idle messages */
    arr_idle_chat_mess = ({
        "You smell ...Steak.",
        "The Canyonero's mere presence makes you feel like just an action figure.",
        "The Canyonero's shadow blocks the sun. Completely. For all of Nirvana!",
        "The Canyonero seems to be leaking copious amounts of oil.",
        "You hear a faint chorus swoon... 'Canyonero!'",
    });

    /* an array of engine noise messages */
    arr_engine_chat_mess = ({
        "The rumble of the Canyonero's 24L engine makes you quiver in fear.",
        "You cannot help but wonder how much gasoline the Canyonero consumes in... three minutes.",
        "The Canyonero's engine idles noisily.",
    });
}
/* end function reset(); */

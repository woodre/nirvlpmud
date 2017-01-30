inherit "/players/mizan/core/vehicle.c";
#include "/obj/ansi.h"

/*
 * our reset method
 *
 */
reset(arg)
{
    string tmp_ldesc;
    string tmp_long;
    object bin;


    tmp_ldesc = "    You are inside a giant steamroller (land compactor). It is big and\n";
    tmp_ldesc += "  yellow, with a sparse but functional interior. It smells oddly of\n";
    tmp_ldesc += "  of pickles inside here.\n";

    tmp_long = "    This is a gigantic steamroller that is covered with mud and Ether-muck.\n\n";
    tmp_long += "  Markings indicate it is a Caterpillar CS-573D. Despite it's absolutely filthy\n";
    tmp_long += "  condition the steamroller appears to be in otherwise decent shape.\n";

    ::reset(arg);
    if(arg) return;

    set_name("steamroller");
    set_race("steamroller");
    set_alias("steamroller");
    set_short(BLK + HBYEL + "A steamroller" + NORM + NORM);
    set_long(tmp_long);
    set_level(10);
    set_hp(400);
    set_al(0);
    set_wc(3);
    set_ac(30);
    set_aggressive(0);
    set_hatch_id("hatch");
    set_maximum_fuel(50);
    set_maximum_occupants(2);

    set_key_id("steamroller_key");
    set_engine_key_id("steamroller_ignition_key");
    set_fuel(45);
    set_fuel_id("gasoline");
    set_inside_short_desc("Inside a steamroller");
    set_inside_long_desc(tmp_ldesc);
    set_exit_mess("leaves rumbling slowly");
    set_enter_mess("arrives rumbling slowly");

    set_engine_startup_message("The steamroller's engine kicks to life!\n");
    set_engine_stop_message("The steamroller's engine shuts off.\nIt groans to utter silence.\n");

    set_fuel_idle_consumption(20);
    set_fuel_overflow_mess("The tank is full, and some extra gasoline gushes out.\n");

    enable_headlights();
    set_maximum_battery(50);
    set_battery_id("battery");
    set_headlight_consumption(40);
     
    /* an array of just idle messages */
    arr_idle_chat_mess = ({
        "The steamroller appears to be leaking some sort of fluid.",
    });

    /* an array of engine noise messages */
    arr_engine_chat_mess = ({
        "The steamroller's engine rumbles loudly at idle.",
    });

    set_idle_chat_chance(1);
    set_engine_chat_chance(2);
}
/* end function reset(); */



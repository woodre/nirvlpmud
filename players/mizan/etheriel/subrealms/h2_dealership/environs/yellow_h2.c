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


    tmp_ldesc = "    You are inside the massively boxy Hummer H2. Although concieved as\n";
    tmp_ldesc += "  the more budget version of the original H1, it is more sought after\n";
    tmp_ldesc += "  than its military-birthed sibling. It's offroading performance is\n";
    tmp_ldesc += "  also more suspect as well. However none of this matters, as it is\n";
    tmp_ldesc += "  a big, tough-looking vehicle that people will march in horedes to buy.\n";

    tmp_long = "    This is the monstrosity known as the Hummer H2. Surrounded by 6400 lbs.\n\n";
    tmp_long += "  of truck, you can't help but feel safe and secure. But are you? None of that\n";
    tmp_long += "  is particularly relevant, since you are inside the vehicle which has caused\n";
    tmp_long += "  more buzz and publicity for any Detroit-generated vehicle for some time.\n";

    ::reset(arg);
    if(arg) return;

    set_name("Hummer H2");
    set_race("hummer");
    set_alias("h2");
    set_short(BLK + HBYEL + "A bright yellow Hummer H2 SUV" + NORM + NORM);
    set_long(tmp_long);
    set_level(10);
    set_hp(1000);
    set_al(0);
    set_wc(3);
    set_ac(30);
    set_aggressive(0);
    set_hatch_id("door");
    set_maximum_fuel(100);
    set_maximum_occupants(8);

    set_key_id("h2hummer_key");
    set_engine_key_id("h2hummer_ignition_key");
    set_fuel(85);
    set_fuel_id("gasoline");
    set_inside_short_desc("Inside the Hummer H2");
    set_inside_long_desc(tmp_ldesc);
    set_exit_mess("leaves with a deafening roar");
    set_enter_mess("arrives, it's sheer bulk terrifying you");

    set_engine_startup_message("The Hummer H2's engine kicks to life with a deafening roar!\n");
    set_engine_stop_message("The Hummer H2's engine shuts off.\nSilence can be enjoyed again.\n");

    set_fuel_idle_consumption(20);
    set_fuel_overflow_mess("The tank is full, and some extra gasoline gushes out.\n");

    enable_horn();
    set_horn_verb("honk");
    set_horn_mess("The Hummer H2's horn goes off... HOOOOONK! HOOOOONK!\n");
    
    enable_headlights();
    set_maximum_battery(50);
    set_battery_id("battery");
    set_headlight_consumption(40);
     
    /* an array of just idle messages */
    arr_idle_chat_mess = ({
        "You boggle at the sheer mass and wastefulness of the Hummer H2.",
    });

    /* an array of engine noise messages */
    arr_engine_chat_mess = ({
        "The Hummer H2's engine rumbles noisily.",
    });

    set_idle_chat_chance(1);
    set_engine_chat_chance(2);
}
/* end function reset(); */



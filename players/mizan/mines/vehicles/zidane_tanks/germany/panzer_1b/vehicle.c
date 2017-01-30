/* The description of this tank was created by Zidane@Nirvana (James Emmerich).
 * 02 jul 2009
 *
 */
inherit "/players/mizan/mines/core/vehicle.c";
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
    object bin02;


    tmp_ldesc = "    You are crammed inside the nimble Panzerkampfwagen I Ausf. B,\n";
    tmp_ldesc += "  the light, quick support tank in the beginning years of the\n";
    tmp_ldesc += "  Blitzkrieg. With only a two-man crew this is an easy to handle\n";
    tmp_ldesc += "  machine. A driver and a commander who manned the twin\n";
    tmp_ldesc += "  7.92 MG 13k's. It's lightly armed and  armored made for fast\n";
    tmp_ldesc += "  action. It's sure to be a thorn in ground troop's sides.\n";


    tmp_long = "    You gaze upon the small, fast, and one of the first in a series\n";
    tmp_long += "  of successful German tanks, the Panzerkampfwagen I Ausf. B.\n";
    tmp_long += "  Debuting in combat for the German army in Poland it preformed quite\n";
    tmp_long += "  satisfactory. The lightly armed and armored little beast was a pain to\n";
    tmp_long += "  ground troops who encountered it. A weathered appearance graced the vehicle's\n";
    tmp_long += "  " + GRY + "'Dunkelgrau'" + NORM + " paint applique. Mud and tree branches are affixed all over the\n";
    tmp_long += "  tank's hull. Big white identification numbers and Balkan crosses adorned its\n";
    tmp_long += "  side like lucky charms. There's stowage onboard, rolled blankets, mess kits,\n";
    tmp_long += "  helmets, boxes of personal items, tools and more eventually added to the\n";
    tmp_long += "  effect as if the crew lived in it.\n";
    tmp_long += "  On the hull is printed the tank's name, 'Der Grau Maus'.\n";
    tmp_long += "  On closer inspection of the hull, you see a small plate mounted that reads:\n";
    tmp_long += "  " + HIY + "This restoration brought to you by Zidane Motortechnik" + NORM + "\n";

    ::reset(arg);

    if(arg) return;


    set_name("Panzer I Ausf B Tank");
    set_race("Panzer I Tank");
    set_alias("tank");
    set_short("A Panzerkampfwagen I Ausf. B Tank");
    set_long(tmp_long);
    set_level(10);
    set_hp(130);
    set_al(0);
    set_wc(3);
    set_ac(30);
    set_aggressive(0);
    set_hatch_id("hatch");
    set_maximum_fuel(146);
    set_maximum_occupants(2);

    set_key_id("PanzerIB_key");
    set_engine_key_id("PanzerIB_enginekey");
    set_fuel(146);
    set_fuel_id("PanzerIB_fuel");
    set_inside_short_desc("Inside the Panzer I B tank");
    set_inside_long_desc(tmp_ldesc);
    set_exit_mess("leaves with tracks clanking, squealing and rumbling");
    set_enter_mess("arrives, its tracks clanking and squeaking loudly.");

    set_engine_startup_message("The Panzer I B starts its engine with a satisfying turn-over!\n");
    set_engine_stop_message("The Panzer I B's engine comes to a halt.\nSuddenly, there is silence...\n");

    set_fuel_idle_consumption(5);
    set_fuel_overflow_mess("The tank is full, and some extra petrol fuel gushes out.\n");

    enable_horn();
    set_horn_verb("honk");
    set_horn_mess("The Panzer I B's horn goes off... BEEP! BEEEP! \nYou wonder why a tank has a horn, when it really doesn't need one.\n");

  
    enable_headlights();
    set_battery_id("PanzerIB_battery");

    set_headlight_consumption(30);
    set_maximum_battery(50);
    

/*

    if(!bin) bin = move_object(clone_object("/players/mizan/samples/vehicles/panzerib/storage_bin.c"), this_object());
    if(!bin02) bin02 = move_object(clone_object("/players/mizan/samples/vehicles/panzerib/storage_bin02.c"), this_object());
  
    if(bin)
    {
        move_object(clone_object("/players/mizan/samples/vehicles/panzerib/shell-explosive.c"), bin);
        move_object(clone_object("/players/mizan/samples/vehicles/panzerib/shell-explosive.c"), bin);
        move_object(clone_object("/players/mizan/samples/vehicles/panzerib/shell.c"), bin);
        move_object(clone_object("/players/mizan/samples/vehicles/panzerib/shell.c"), bin);
        move_object(clone_object("/players/mizan/samples/vehicles/panzerib/shell.c"), bin);
        move_object(clone_object("/players/mizan/samples/vehicles/panzerib/shell.c"), bin);
        move_object(clone_object("/players/mizan/samples/vehicles/panzerib/shell-paint.c"), bin);
        move_object(clone_object("/players/mizan/samples/vehicles/panzerib/shell-paint.c"), bin);
    }


    move_object(clone_object("/players/mizan/samples/vehicles/panzerib/fuel.c"), this_object());
    move_object(clone_object("/players/mizan/samples/vehicles/panzerib/fuel.c"), this_object());
*/

    /* an array of just idle messages */
    arr_idle_chat_mess = ({
        "You wonder where the turn-key goes...\nThe tank is so small it's like a wind-up toy..",
        "The Panzer is dirty... you should add more mud and tree branches to blend in more!",
    });

    /* an array of engine noise messages */
    arr_engine_chat_mess = ({
        "The puttering of the engine reminds you of an idling, overpowered sports car.",
        "-PUTTER-PUT-PUT-PUTTER-PUT-PUT...\nThe Panzer I's engine idles noisily.",
	"The Panzer I B idles eagerly, as if ready to gun it at any moment.",
    });

    set_idle_chat_chance(1);
    set_engine_chat_chance(2);
}
/* end function reset(); */


delayed_reset()
{
    ::delayed_reset();
/*
    move_object(clone_object("/players/mizan/samples/vehicles/panzerib/machineguns.c"), this_object());
*/
}

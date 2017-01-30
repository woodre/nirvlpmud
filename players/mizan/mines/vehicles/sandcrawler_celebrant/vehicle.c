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

    if(arg) return;

    move_object(this_object(), "/room/wild1");

    set_name("Sandcrawler");
    set_race("sandcrawler");
    set_alias("sandcrawler");
    set_short("A Jawa Sandcrawler");
    set_long(tmp_long);
    set_level(10);
    set_hp(10000);
    set_al(0);
    set_wc(3);
    set_ac(300);
    set_aggressive(0);
    set_hatch_id("hatch_hidden");
    disable_hatch();
    set_maximum_fuel(2000);
    set_maximum_occupants(10);

    set_key_id("sandcrawler_celebrant_key");
    set_engine_key_id("sandcrawler_celebrant_enginekey");
    set_fuel(1000);
    set_fuel_id("sandcrawler_fuel");
    set_inside_short_desc("The bridge of the Celebrant Waylander sandcrawler");
    set_inside_long_desc(tmp_ldesc);
    set_exit_mess("leaves slowly with tracks clanking, rumbling");
    set_enter_mess("arrives slowly, its tracks clanking and squeaking loudly.");

    set_engine_startup_message("The sandcrawler starts its massive drive reactors with a deafening roar!\nKatoosh... katoosh... katoosha... katoosh...\n");
    set_engine_stop_message("The sandcrawler's drive reactors spin down steadily to a halt.\nSuddenly, there is silence...\n");

    set_fuel_idle_consumption(10);
    set_fuel_overflow_mess("The sandcrawler's engine reactor vents some steam with a deafening WOOSH!\n");

    enable_horn();
    set_horn_verb("honk");
    set_horn_mess("A horn blasts loudly, from the high atop the sandcrawler.\nMOVE!\n");

    
    enable_headlights();
    set_battery_id("sandcrawler_battery");

    set_headlight_consumption(40);
    set_maximum_battery(50);
     
/*
    if(!bin) bin = move_object(clone_object("/players/mizan/samples/vehicles/tiger1/storage_bin.c"), this_object());
    if(!bin02) bin02 = move_object(clone_object("/players/mizan/samples/vehicles/tiger1/storage_bin02.c"), this_object());
    

    if(bin)
    {
        move_object(clone_object("/players/mizan/samples/vehicles/tiger1/shell.c"), bin);
        move_object(clone_object("/players/mizan/samples/vehicles/tiger1/shell-paint.c"), bin);
	move_object(clone_object("/players/mizan/samples/vehicles/tiger1/shell-paint.c"), bin);
	move_object(clone_object("/players/mizan/samples/vehicles/tiger1/shell-paint.c"), bin);
	move_object(clone_object("/players/mizan/samples/vehicles/tiger1/shell-paint.c"), bin);
	move_object(clone_object("/players/mizan/samples/vehicles/tiger1/shell-paint.c"), bin);
	move_object(clone_object("/players/mizan/samples/vehicles/tiger1/shell-paint.c"), bin);
	move_object(clone_object("/players/mizan/samples/vehicles/tiger1/shell-paint.c"), bin);
	move_object(clone_object("/players/mizan/samples/vehicles/tiger1/shell-paint.c"), bin);
	move_object(clone_object("/players/mizan/samples/vehicles/tiger1/shell-paint.c"), bin);
        move_object(clone_object("/players/mizan/samples/vehicles/tiger1/shell-paint.c"), bin);
    }


    move_object(clone_object("/players/mizan/samples/vehicles/tiger1/fuel.c"), this_object());
    move_object(clone_object("/players/mizan/samples/vehicles/tiger1/fuel.c"), this_object());
*/

    /* an array of just idle messages */
    arr_idle_chat_mess = ({
        "You notice someone in the sandcrawler peering at you through a porthole.",
        "Thick, black smoke pours out of a small exhaust gate from the sandcrawler.",
        "A clanking, hammering noise is heard from deep inside the sandcrawler.",
    });

    /* an array of engine noise messages */
    arr_engine_chat_mess = ({
        "The deep rumble of sandcrawler's reactor working unsettles your stomach.",
        "Some high-pitched whirring noises can be heard from the sandcrawler.",
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

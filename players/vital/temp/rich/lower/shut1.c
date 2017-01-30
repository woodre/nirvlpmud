/*
 * This is a shut down deamon, that will take care of shutting down
 * the game.
 * Call the function "shut" with a number of seconds as an
 * argument.
 * Don't clone this object.
 */

inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg)
	return;
    set_name("armageddon");
    set_level(19);
    set_hp(99999);
    set_wc(40);
    set_ac(200);
    set_short("Armageddon the game crasher");
    set_long("He looks like he enjoys to stop the game.\n");
    set_alias("shut");
    mmsgin = "Arrives in a puff of smoke";
    move_player("X#room/church");
}

shut(seconds)
{
    int i;

  if(this_player()) {
   log_file("SHUTDOWN", "shut called by "+call_other(this_player(), "query_real_name", 0) + ctime(time()) + "\n");
   }
    if (!intp(seconds)) {
	write("Bad argument\n");
	return;
    }
    if (seconds == 0) {
	write("No time given\n");
	return;
    }
    set_long("He is firmly concentrated on counting.\n");
    i = remove_call_out("cont_shutting");
    if (i > 0) {
	i = (i + 10) * 4;
	if (i < seconds) {
	    write("There was already a shutdown in process, " + i +
		  " seconds.\n");
	    seconds = i;
	}
    }
    call_out("cont_shutting", 0, seconds * 60);
}

int transport_offer;

cont_shutting(seconds) {
    string delay;
    int new_delay;

    if (seconds <= 0) {
	shout(cap_name + " shouts: I will reboot now.\n");
/*
	shutdown();
*/
       call_other("obj/master.c","shut_down_game",0);
	return;
    }
    if (seconds <= 240 && !transport_offer) {
	shout(cap_name +
	    " shouts: Tell me if you want a trip to the shop !\n");
	transport_offer = 1;
    }
    new_delay = seconds * 3 / 4 - 10;
    call_out("cont_shutting", seconds - new_delay, new_delay);
    delay = "";
    if (seconds > 59) {
	delay = seconds / 60 + " minutes ";
	seconds = seconds % 60;
    }
    if (seconds != 0)
	delay += seconds + " seconds ";
    shout(cap_name + " shouts: Game reboot in " + delay + ".\n");
}

catch_tell(str) {
    string who, what;
    object ob;

    if (!transport_offer)
	return;
    if (sscanf(str, "%s tells you: %s", who, what) != 2)
	return;
    this_player()->move_player("X#room/shop");
}

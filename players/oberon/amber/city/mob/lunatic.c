#include <ansi.h>
inherit "/obj/monster";

reset(arg) {
	::reset(arg);
	if(arg) return;

	set_name("lunatic");
	set_race("human");
	set_short("A Crazed Lunatic");
	set_long("Truly a loon. He isn't even worth killing.\n");
	set_gender("male");
	set_level(16);
	set_hp(100000);
	set_wc(0);
	set_ac(100);
	set_aggressive(0);
	set_al(0);

	set_chat_chance(1);
	load_chat("The lunatic stares at you with his crazy eyes.\n");
	load_chat("The lunatic hides from the guards.\n");
}

init() {
	::init();
	add_action("cmd_list", "list");
	/*add_action("cmd_buy", "buy");*/
}

heart_beat() {
	::heart_beat();
}

cmd_list() {
	int result;
	test_say("Shhhhh...");
	/*
	write("+-------------------------------------------+\n");
	write("|  Item                  Alias      Cost    |\n");
	write("|                                           |\n");
	write("+-------------------------------------------+\n");
	*/
	return 1;
}

test_say(str) {
	string me, how;
	int index;
	if(!str || str=="") return 1;
	if(str[(index=(strlen(str)-1))] == '?') how = "ask";
	else if(str[index]=='!') how = "exclaim";
	else how = "say";
	str = format(str, 60);
	me = (ghost ? short() : this_object()->query_name());
	say(me+" "+how+"s: "+str+"\n");
	/*
	if(brief) write("Ok.\n");
	else write("You "+how+": "+str+"\n");
	*/
	return 1;
}
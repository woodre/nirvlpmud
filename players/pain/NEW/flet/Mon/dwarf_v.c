/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
=-=
=-=	dwarf_v.c
=-=
=-=	A Dwarvish Visitor to the Elven Flet
=-=
=-=	** The ac is 20, rather high, because the dwarf
=-=	has info needed for the quest **
=-=
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

inherit "/obj/monster";
#include "/players/pain/color.h"

reset(arg) {
	::reset(arg);
	set_short("A "+BOLD+BLUE+"Dwarf"+END);
	set_long("This "+BOLD+BLUE+"Dwarf"+END+" is an emissary to the Elves from\n"+
		"the dwarves of the "+BOLD+BLUE+"Glittering Caves of Al'Mathir"+END+".\n"+
		"He is an old, wise dwarf, who has served his people well for\n"+
		"many years. He looks deeply troubled, as if he carries a great\n"+
		"mental burden. Perhaps if you <speak with> him you could learn\n"+
		"something which might help you to help both the Elves and Dwarves.\n");
	set_level(10);
	set_hp(140+random(100));
	set_ac(20);
	set_wc(14);
	set_race("dwarf");
	set_name("emissary");
	set_alias("dwarf");
	call_out("mumble",10);
}

init() {
	::init();
add_action("speak","speak");
}

mumble() {
int number;

number = random(3);

if(number == 0) {
	tell_room(environment(this_object()),
		"The dwarf mumbles quietly to himself, you manage to make out\n"+
		"the word \"Mortus\".\n");
}
if(number == 1) {
	tell_room(environment(this_object()), 
		"The dwarf mumbles, \"I must find the Elven King or all is lost.\"\n");
}
if(number == 2) {
	tell_room(environment(this_object()), 
		"The dwarf mumbles, \"I only hope I can find help in time.\"\n");
}
call_out("mumbles",30);
return 1;
}

speak(str) {

if(!str && str != "with dwarf" && str != "with emissary") {
	tell_object(this_player(), "Who do you wish to speak with?\n");
	return 1;
}

/*
remove_call_out("mumbles");
NEED TO CHECK THIS
*/

tell_object(this_player(), 
	"You begin to speak to the dwarf and he looks up at you hopefully.\n");
tell_room(environment(this_object()),
	this_player()->query_name()+" begins to speak to the dwarf.\n\n");
tell_room(environment(this_object()), 
	"The dwarf says: I hope you can help me.\n\n");
tell_room(environment(this_object()), 
	"The dwarf says: I have travelled a long way to meet with the grieving\n"+
	"Elven King in hopes of obtaining his help.\n\n");
tell_room(environment(this_object()), 
	"The dwarf says: The "+BOLD+BLUE+"Glittering Caves"+END+" are under attack!\n\n");
tell_room(environment(this_object()), 
	"The dwarf pauses to let this information sink in.\n\n");
call_out("next_say",20);
return 1;
}

next_say() {
tell_room(environment(this_object()), 
	"The dwarf says: Mortus has laid seige to the "+BOLD+BLUE+
	"Glittering Caves"+END+".\n"+
	"I fear if we don't receive help, my people will all die horribly.\n\n");
tell_room(environment(this_object()), 
	"The dwarf says: I understand that you too are going to see the Elven King, I\n"+
	"hope that you might be able to help us after you speak to him.\n\n");
tell_room(environment(this_object()), 
	"The dwarf says: The entrance to the caves is very close to that of the Orc Caves.\n\n");
tell_room(environment(this_object()), 
	"The dwarf says: I can tell you no more at this time, you must go see the King.\n\n");
call_out("mumbles",20);
return 1;
}


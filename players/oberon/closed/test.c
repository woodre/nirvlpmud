#include <ansi.h>
#include "/sys/lib.h"
inherit "obj/armor";

#define TPP this_player()_>query_prestige_level()
int ilvl;

reset(arg) {
	::reset(arg);
	if(arg) return;
	if(!ilvl || ilvl<1) ilvl=1;
	
	set_name("underwear");
	set_short("Magic Underwear (lvl "+ilvl+")");
	set_long("Provided by the Smith of Amber.\n");
	set_weight(1);
	set_type("underwear");
}

init() {
	::init();
	/*add_action("cmd_debug", "check");*/
	add_action("add_level", "add");
	add_action("del_level", "del");
	add_action("set_level", "set");
}

calc() {
	command("remove underwear");
	set_short("Magic Underwear (lvl "+ilvl+")");
	set_ac(ilvl);
	command("wear underwear");
	return 1;
}

add_level(arg) {
	write("The underwear flash brightly!\n");
	ilvl++;
	calc();
	return 1;
}

del_level(arg) {
	write("The underwear flash brightly!\n");
	ilvl--;
	calc();
	return 1;
}

set_level(arg) {
	write("The underwear flash brightly!\n");
	return 1;
}

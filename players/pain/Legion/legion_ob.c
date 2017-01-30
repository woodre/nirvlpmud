/*
	Filename: legion_ob.c
	Date:     07/23/98
	Update:   07/07/99
	Author:   Pain
	Purpose:  Death's Legion Guild Object

	Description:
		The guild object will contain the code to ensure
		that the guild members only use issued equipment
		and that the monetary regulations are enforced.

		There will not be many guild commands in this 
		guild as the legionnaires are not magic users.
*/

/* inherit "/obj/armor"; */
#include "/players/pain/Legion/defs.h"

/*
	Variables
*/
string muffs;
query_muffs() { return muffs; }
set_muffs(str) { muffs = str; }

int enrage;
query_enrage() { return enrage; }
set_enrage(str) { enrage = str; }

int multi_attack;
query_multi_attack() { return multi_attack; }
set_multi_attack(str) { multi_attack = str; }

int critical_hit;
query_critical_hit() { return critical_hit; }
set_critical_hit(str) { critical_hit = str; }

int extra_damage;
query_extra_damage() { return extra_damage; }
set_extra_damage(str) { extra_damage = str; }

int balance;
query_balance() { return balance; }
set_balance(str) { balance = str; }

int bury;
query_bury() { return bury; }
set_bury(str) { bury = str; }

int repair;
query_repair() { return repair; }
set_repair(str) { repair = str; }

/*
	Initialize the Guild Object
*/
id(str) { 
	return str == "l_gob" || str == "tattoo" || str == "no_spell"; 
}

drop() { return 1; }
get() { return 1; }
query_weight() { return 0; }
query_value() { return 0; }
short() { return; }
long() { 
	write("A tattoo of a skull imposed on a flaming sword.\n"+
	      "Looking at it you realize you are a member of an\n"+
	      "elite fighting force in the service of Death.\n"+
	      "To get more information type <help legion\>.\n");
}

reset(arg) {
   if(arg)
	return;
   call_out("fixd",5);
}

init_arg() {
        restoreme();
	cat("/players/pain/legion_news");
        return;
}

init() {

	add_action("balance", "balance");
	add_action("bury", "bury");
	add_action("check_wear", "wear");
	add_action("check_wield", "wield");
	add_action("consider", "consider");
	add_action("enrage", "enrage");
	add_action("heal", "heal");
	add_action("l_color", "l_color");
	add_action("l_muffle", "l_muffle");
	add_action("legion", "legion");
	add_action("legion_who", "lwho");
	add_action("man", "man");
	add_action("quit", "quit");
	add_action("recruit", "recruit");
	add_action("repair", "repair");
	add_action("report", "report");
	add_action("resign", "resign");
	add_action("restoreme", "restoreme");
	add_action("saveme", "saveme");
	add_action("skills", "skills");

}

/*
	Functions
*/

balance() { return BASE->balance(); }
bury(arg) { return BASE->bury(arg); }
check_wear(arg) { return BASE->check_wear(arg); }
check_wield(arg) { return BASE->check_wield(arg); }
consider(arg) { return BASE->consider(arg); }
enrage() { return BASE->enrage(); }
fixd() { return BASE->fixd(); }
l_color() { return BASE->l_color(); }
l_muffle() { return BASE->l_muffle(); }
legion(arg) { return BASE->legion(arg); }
legion_who() { return BASE->legion_who(); }
man(arg) { return BASE->man(arg); }
quit() { return BASE->quit(); }
recruit(arg) { return BASE->recruit(arg); }
repair(arg) { return BASE->repair(arg); }
report() { return BASE->report(); }
resign(arg) { return BASE->resign(arg); }
skills() { return BASE->skills(); }

query_auto_load() { return "players/pain/NEW/Guild/legion_ob.c:"; }

extra_look() {
write(environment(this_object())->query_name()+" has a "+RED+
      "Death's Head"+END+" tattoo.\n");
}

/*
        saveme()

        Save guild members stats and information.
*/
saveme() {
	save_object(LEGION+this_player()->query_real_name());
	write("Legion stats and information saved. . . .\n");
	return 1;
}

/*
        restoreme()

        Restore guild member stats and information.
*/
restoreme() {
	if(restore_object(LEGION+this_player()->query_real_name())) {
	write("Your Legion stats are being restored. . . .\n");
 	return 1;
}
else {
        write("Creating a Legion stat file, please hold. . . .\n");
	saveme();
	return 1;
}
}


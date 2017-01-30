#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	int amt, num;
	object whirlwind;
	
	num = (int)User->query_level();
	if(User->query_ghost()) {
		write("You lack substance.\n"); return 1; }
	if(PO->query_spell_delay()) {
		write("You cannot cast a spell again so soon.\n"); return 1; }
	if(present(WHIRLWIND,User)){
		write("You already have a whirlwind surrounding you.\n"); return 1; }
	if(num > 9 && num < 20){
		switch(num){
			case 0.. 4:    amt = 30; break;
			case 5..10:    amt = 35; break;
			case 11..14:    amt = 40; break;
			case 15..19:    amt = 50; break;
		}
		if(User->query_sp() < amt) {
			write("You do not have enough energy.\n"); return 1;}
			whirlwind = clone_object(OBJECTPATH+"/whirlwind.c");
			whirlwind->set_time(User->query_level());
			move_object(whirlwind, User);
			write(BOLD+RED+"\tYou scream and spin around summoning a giant Whirlwind of	sand around you!\n"+OFF+OFF);
			say(BOLD+RED+User->query_name()+" screams and spins around summoning a giant Whirlwind of sand around "+User->query_objective()+"\n"+OFF+OFF);  
			User->add_spell_point(-amt);
			PO->add_spell_delay(20+random(num));     
		return 1; }
		else {
			switch(num){
			case 0..2:    amt = 10; break;
			case 3..5:    amt = 15; break;
			case 6..7:    amt = 20; break;
			case 8..10:    amt = 25; break;
		}
		if(User->query_sp() < amt) {
			write("You do not have enough energy.\n"); return 1;}
			whirlwind = clone_object("/players/snow/dervish/objects/whirlwind1.c");
			whirlwind->set_time(User->query_level());
			move_object(whirlwind, User);
			write(BOLD+RED+"\tYou scream and spin around summoning a Whirlwind of sand around you!\n"+OFF+OFF);
			say(BOLD+RED+User->query_name()+" screams and spins around summoning a Whirlwind of sand around "+User->query_objective()+"\n"+OFF+OFF);  
			User->add_spell_point(-amt);
			PO->add_spell_delay(10+random(num));
		return 1; }      
}
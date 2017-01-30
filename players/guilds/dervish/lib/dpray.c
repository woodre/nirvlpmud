#include <ansi.h>
#include "../defs.h"

status main(string str, object PO, object User)
{
	object poison, next;
	string a,b;
	
	
	if(User->query_level() < 14) {
		write("You are not high enough level to use this Mystic ability yet.\n");
		return 1; }
	if(User->query_ghost()) {
		write("You lack substance.\n"); return 1; }
	if(User->query_attrib("pie") < 19) {
		write("You lack devotion.\n"); return 1; }
	if(PO->query_spell_delay()) {
		write("You cannot cast a spell again so soon.\n"); return 1; }
	if(User->query_sp() < 40) {
		write("You do not have enough energy.\n"); return 1; }
	if(User->query_attack()) {
		write("You cannot cast a spell in combat.\n"); return 1; }
		write(BOLD+RED+"\tYou writhe about, spinning in ecstacy!\n"+OFF+OFF);
		say(BOLD+RED+User->query_name()+" writhes about, spinning in ecstacy!\n"+OFF+OFF);
		poison = first_inventory(User);
	    	while (poison) {
	        	    next = next_inventory(poison);
	            	if (sscanf(file_name(poison),"%spoison%s",a,b) == 2 ||
	                	    poison->id("poison")) {
	                    	tell_object(User,
	                    	BOLD+RED+"Poison is destroyed"+OFF+BOLD+"..."+OFF+"\n");

	                    	destruct(poison);
	            }
	            poison = next;
	    }
	User->add_spell_point(-40);
	User->add_hit_point(random((int)User->query_attrib("pie"))+32);
	PO->add_spell_delay(random(60)+15);
	return 1;
}
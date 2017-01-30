#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	object wep;

	if(!str){
		write("What would you like to sharpen?\n"); return 1; }
	
	wep = present(str, this_player());
	
	if(!wep){
		write("You don't have that to sharpen!\n"); return 1; }
	if(!wep->is_weapon()){
		write("You can only sharpen weapons.\n"); return 1; }
	if(this_player()->query_level() < 9) {
		write("You are unable to use this ability yet.\n"); return 1; }
	if(this_player()->query_no_spell() || this_player()->checkNM() || this_player()->query_sp() < 30) {
	    write("You are unable to work the sands at this time.\n"); return 1; }
	if(this_player()->query_ghost()) {
		write("You cannot do that while you are dead!\n"); return 1; }
	if(wep->query_broke()) {
		write("You cannot sharpen that! It is broken.\n"); return 1; }

	write("You command the sands to glide over your "+wep->query_name()+", sharpening it.\n");
	say(this_player()->query_name()+" commands the sands to glide over their "+wep->query_name()+", sharpening it.\n");
	wep->set_misses(1);
	wep->set_hits(1);
	this_player()->add_spell_point(-30);
	return 1;
}
#include "/players/dragnar/guild/defs/def.h"
summon() {
	object dragon, ob;
	string idstr, ownstr;
	if(usp < 100){
	write("You do not have enough spell points to sacrifice.\n");
	return 1; }
	if(find_living(this_player()->query_real_name()+"dragon")){
	write("You already have a dragon.\n");
	return 1; }
	dragon=clone_object("/players/dragnar/guild/pet.c");
	idstr=this_player()->query_real_name()+"dragon";
	ownstr = this_player()->query_real_name();
	move_object(dragon, environment(this_player()));
	dragon->set_owner(ownstr);
	dragon->set_variable(idstr);
	write("You summon the spirits of past warriors and they form into a dragon.\n");
	say(capname+" forms a dragon from the spirits of past warriors.\n");
	return 1;
}
dragon() {
	if(!find_living(this_player()->query_real_name()+"dragon")){
	write("You do not have a dragon.\n");
	return 1; }
	move_object(find_living(this_player()->query_real_name()+"dragon"), environment(this_player()));
	write("Your dragon swoops down from the sky.\n");
	say(capname+"'s dragon swoops down from the sky.\n");
	return 1; }

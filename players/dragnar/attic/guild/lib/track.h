#include "/players/dragnar/guild/defs/def.h"
track(str){
	int fl;
	object tw;
	if(!str && guildobj->query_follow() == 0) {
	write("Who do you wish to begin tracking?\n");
	return 1; }
	if(!str && guildobj->query_follow() == 1) {
	write("You are no longer tracking anyone.\n");
	fl = 0;
	guildobj->set_follow(fl);
	return 1; }
	if(!present(str, environment(user))){
	write(capitalize(str)+" is not here.\n");
	return 1; }
	if(!find_living(str)) {
	write("You can't track something that is not alive.\n");
	return 1;
	}
	if(find_living(str)->query_level() > 100000){
	write("You can not track a wizard.\n");
	return 1; }
	if(usp < 40) {
	write("You do not have enough spell points to sacrifice!\n");
	return 1; }
	tw =find_living(str);
	fl = 1;
	user->add_spell_point(-40);
	guildobj->set_trackwho(tw);
	guildobj->set_follow(fl);
	write("You are now set to track "+capitalize(str)+".\n");
	return 1;
}

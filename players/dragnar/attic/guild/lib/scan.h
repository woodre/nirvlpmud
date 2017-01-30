#include "/players/dragnar/guild/defs/def.h"
scan(str) {
	object ob;
	if(!str) {
	write("Who do you want to scan?\n");
	return 1; }
	ob = present(str, environment(this_player()));
	if(!ob) {
	write(capitalize(str)+" is not here.\n");
	return 1; }
	if(!find_living(str)) {
	write("Scan is useless on things that are not alive.\n");
	return 1; }
	if(usp < 10) {
	write("You do not have enough spell points to sacrifice.\n");
	return 1; }
	write("You close your eyes and concentrate on "+capitalize(str)+":\n");
	if(umhp > ob->query_mhp()) {
	write("HP: You are the stronger warrior.\n");
	}
	if(umhp == ob->query_mhp()) {
	write("HP: You are equal warriors.\n"); }
	if(umhp < ob->query_mhp()) {
	write("HP: You are the weaker warrior.\n"); }
	if(user->query_ac() > ob->query_ac()) {
	write("AC: You are better protected.\n"); }
	if(user->query_ac() < ob->query_ac()) {
	write("AC: You are less protected.\n");
	}
	if(user->query_ac() == ob->query_ac()) {
	write("AC: You are equally protected.\n"); }
	if(user->query_wc() > ob->query_wc()) {
	write("WC: You have the advantage.\n"); }
	if(user->query_wc() < ob->query_wc()) {
	write("WC: You are at a disadvantage.\n"); }
	if(user->query_wc() == ob->query_wc()) {
	write("WC: You have equal weapons.\n"); }
	user->add_spell_point(-10);
	say(capname+" closes "+user->query_possessive()+" eyes and concentrates intently on "+capitalize(str)+".\n");
	return 1; }

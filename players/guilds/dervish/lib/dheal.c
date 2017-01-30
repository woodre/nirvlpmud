#include <ansi.h>
#include "../defs.h"

status main(string str, object PO, object User)
{
	int hp, sp, hpadd, spadd;

	if(User->query_level() < 18) {
	write("You are not high enough level to use this Mystic ability yet.\n");
	return 1; }
	if(User->query_ghost()) {
	write("You lack substance.\n"); return 1; }
	if(User->query_attrib("pie") < 20) {
	write("You lack devotion.\n"); return 1; }
	if(PO->query_spell_delay()) {
	write("You cannot cast a spell again so soon.\n"); return 1; }
	if(User->query_sp() < 1) {
	write("You do not have enough energy.\n"); return 1; }
	if(User->query_attack()) {
	write("You cannot cast a spell in combat.\n"); return 1; }
	write(BOLD+RED+"\tYou are engulfed in a hot pillar of sand...\n"+
	    "\tYour wounds are filled with fire!\n"+
	    "\tYour body shakes with pleasure.\n\n"+OFF+OFF);
	say(BOLD+RED+User->query_name()+" is engulfed in a hot pillar of sand...\n"+
	  User->query_name()+" shakes with pleasure.\n\n"+OFF+OFF);
	hp = (int)User->query_hp();
	hpadd = (int)User->query_mhp() - hp;
	sp = (int)User->query_sp();
	if(sp >= hpadd) spadd = hpadd;
	if(hpadd > sp) { hpadd = sp; spadd = sp; }
	User->add_spell_point(-spadd);
	User->add_hit_point(hpadd);
	PO->add_spell_delay(random(100)+ 50);
	return 1;
}
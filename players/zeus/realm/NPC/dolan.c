inherit "/obj/monster";

reset(arg) {
	::reset(arg);
   if (!arg) {

	set_name("dolan");
	set_short("Dolan, the hermit's son");
	set_long(
"This is the hermit's son, Dolan.  He is a brute of a creature, about\n"+
"7 feet tall and very muscular.  He has a round face, with greenish skin\n"+
"and thin brown hair.  He is just sitting in the middle of the room,\n"+
"looking around playfully.\n");
	set_race("ogre");
	set_level(20);
	set_ac(17);
	set_wc(75);
  set_heal(1,1);
	set_hp(1100);
	set_gender("male");
	set_chat_chance(4);
	load_chat("Dolan smiles at you.\n");
	load_chat("Dolan giggles to himself.\n");
	load_chat("Dolan grins happily at you.\n");
	load_chat("Dolan looks around the room happily.\n");
	load_chat("Dolan says:  hullo there.\n");
	load_chat("Dolan says:  have you seen my daddy?\n");
	load_chat("Dolan says:  who are you?\n");
	set_dead_ob(this_object());
   }  
}

monster_died(){
  write_file("/players/zeus/log/bigmon",
  ctime(time())+" - "+attacker_ob->query_name()+" [L "+
  attacker_ob->query_level()+"+"+attacker_ob->query_extra_level()+
  "] killed Dolan.\n");
}



inherit "obj/monster";
   object gold;

reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("Johnnie Cage");
   set_race("goro");
   set_alias("goro");
	set_short("Johnnie Cage");
	set_long("Cage looks ready to fight.  As he takes off his sunglasses you\n"+
"You can see in his eyes he wants to kill you.  Something about him makes you\n"+
"wonder if your going to get out of this place alive.\n");
   set_level(14);
   set_hp(1500);
   set_al(-1000);
   set_wc(17);
   set_ac(10);
    gold = clone_object("obj/money");
	gold->set_money(random(200)+600);
   move_object(gold,this_object());
}
heart_beat() {
	object att;
	object sonya;
	::heart_beat();
	att=(this_player()->query_attack());
	if(att->query_hp() < 50) {
	tell_object(att, "Johnnie Cage does a round house on you causing instant death.\n");
	att->hit_player(200);
	return 1;
	}
	if(this_object()->query_hp() < 1200) {
	say("Goro claps his hands together and transforms into Sonya!\n");
	sonya=clone_object("/players/dragnar/mons/sonya.c");
	move_object(sonya, environment(this_object()));
	destruct(this_object());
	}
}

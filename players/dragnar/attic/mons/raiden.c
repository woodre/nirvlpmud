inherit "obj/monster";
   object gold;

reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("Raiden");
   set_race("goro");
   set_alias("goro");
	set_short("Raiden");
	set_long("Raiden has electricity flowing around him.  It seems to be flowing\n"+
"from his hat.  He looks like he will use anything to defeat you.\n");
   set_level(14);
   set_hp(1500);
   set_al(-1000);
   set_wc(30);
   set_ac(10);
    gold = clone_object("obj/money");
	gold->set_money(random(200)+600);
   move_object(gold,this_object());
}
heart_beat() {
	object att;
	object fucker;
	::heart_beat();
	att=(this_player()->query_attack());
	if(att->query_hp() < 50) {
	tell_object(att, "Raiden shoots electicity from his fingers!\n"+
"You fall to the ground with the pain of defeat.\n");
	att->hit_player(200);
	return 1;
	}
	if(this_object()->query_hp() < 1000) {
	say("Goro screams in defeat as you beat him!\n");
	fucker=clone_object("/players/dragnar/mons/shangTsung.c");
	move_object(fucker, environment(this_object()));
	destruct(this_object());
	}
}

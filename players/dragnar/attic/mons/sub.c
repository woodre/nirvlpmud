inherit "obj/monster";
   object gold;

reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("Sub-Zero");
   set_race("goro");
   set_alias("goro");
	set_short("Sub-Zero");
	set_long("Sub-Zero is dressed in a blue ninja suit.  When you look into\n"+
"his eyes it seems to fit him because he seems to be very cold.\n"+
"It seems like he could blast you with cold from his eyes...\n");
   set_level(14);
   set_hp(1500);
   set_al(-1000);
   set_wc(35);
   set_ac(10);
    gold = clone_object("obj/money");
	gold->set_money(random(200)+600);
   move_object(gold,this_object());
}
heart_beat() {
	object att;
	object raiden;
	::heart_beat();
	att=(this_player()->query_attack());
	if(att->query_hp() < 50) {
	tell_object(att, "Sub-Zero blasts you with a cone of cold!\n"+
"He come over and smashes you with an uppercut!\n");
	att->hit_player(200);
	return 1;
	}
	if(this_object()->query_hp() < 1000) {
	say("Goro blasts himself with coldness.  Sub-Zero breaks into small pieces!\n"+
"The pieces reform and raiden stands before you.\n");
	raiden=clone_object("/players/dragnar/mons/raiden.c");
	move_object(raiden, environment(this_object()));
	destruct(this_object());
	}
}

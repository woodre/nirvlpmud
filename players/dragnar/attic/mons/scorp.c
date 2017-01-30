inherit "obj/monster";
   object gold;

reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("Scorpion");
   set_race("goro");
   set_alias("goro");
	set_short("Scorpion");
	set_long("Scorpion is dressed in a yellow ninja suit.  He has a mask over his\n"+
"face and for some reason you don't want him to take it off and see\n"+
"what is behind the mask.  His eyes are enough to make you shrudder.\n");
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
	object kano;
	::heart_beat();
	att=(this_player()->query_attack());
	if(att->query_hp() < 50) {
	tell_object(att, "Scorpion takes off his mask.\n"+
"His skelaton face fires a ball of fire at you causing instant death!\n");
	att->hit_player(200);
	return 1;
	}
	if(this_object()->query_hp() < 1050) {
	say("Goro cries in anger and transforms into Kano!\n");
	kano=clone_object("/players/dragnar/mons/kano.c");
	move_object(kano, environment(this_object()));
	destruct(this_object());
	}
}

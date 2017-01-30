inherit "obj/monster";
   object gold;

reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("Sonya");
   set_race("goro");
   set_alias("goro");
	set_short("Sonya");
	set_long("Sonya is one bitch you don't want to mess with.  You\n"+
"realize when you look at her that all of the warriors here\n"+
"want to be champion of Mortal Kombat and will kill you go get there.\n");
   set_level(14);
   set_hp(1500);
   set_al(-1000);
   set_wc(30);
   set_ac(12);
    gold = clone_object("obj/money");
	gold->set_money(random(200)+600);
   move_object(gold,this_object());
}
heart_beat() {
	object att;
	object scorpion;
	::heart_beat();
	att=(this_player()->query_attack());
	if(att->query_hp() < 50) {
	tell_object(att, "Sonya casts a ball of fire at you buring you into a bloody corpse!\n");
	att->hit_player(200);
	}
	if(this_object()->query_hp() < 1150) {
	say("Goro spins into a circle and changes into scorpion!\n");
	scorpion=clone_object("/players/dragnar/mons/scorp.c");
	move_object(scorpion, environment(this_object()));
	destruct(this_object());
	}
}

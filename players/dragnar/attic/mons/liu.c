inherit "obj/monster";
   object gold;

reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("Liu Kang");
   set_race("goro");
   set_alias("goro");
	set_short("Liu Kang");
	set_long("Liu Kang is a master at martial arts.  He stands just over\n"+
"five feet tall and at first you want to laugh, but taking a second\n"+
"look into his eyes you decide you had better keep your guard up.\n");
   set_level(14);
   set_hp(1500);
   set_al(-1000);
   set_wc(23);
   set_ac(10);
    gold = clone_object("obj/money");
	gold->set_money(random(200)+600);
   move_object(gold,this_object());
}
heart_beat() {
	object att;
	object sub;
	::heart_beat();
	att=(this_player()->query_attack());
	if(att->query_hp() < 50) {
	tell_object(att, "Liu Kang flys through the air and kicks you in the face!\n"+
"As you die you feel you nose being crushed into your brain.\n");
	att->hit_player(200);
	return 1;
	}
	if(this_object()->query_hp() < 1000) {
	say("Goro changes his form once again into Sub-Zero!\n");
	sub=clone_object("/players/dragnar/mons/sub.c");
	move_object(sub, environment(this_object()));
	destruct(this_object());
	}
}

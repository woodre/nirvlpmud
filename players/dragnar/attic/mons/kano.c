inherit "obj/monster";
   object gold;

reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("Kano");
   set_race("goro");
   set_alias("goro");
	set_short("Kano");
	set_long("Kano is dressed in all white.  He looks like he has something\n"+
"metallic where is face is.  You notice he is carrying a knife that has\n"+
"a blue glow surrouding it.\n");
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
	object liu;
	::heart_beat();
	att=(this_player()->query_attack());
	if(att->query_hp() < 50) {
	tell_object(att, "Kano throws a magical knife at you!\n"+
"You see the blue blur come at you and see it stick it your gut!\n"+
"You realize it's going to kill you.\n");
	att->hit_player(200);
	return 1;
	}
	if(this_object()->query_hp() < 1000) {
	say("Goro seems to get smaller.  There is a bright flash! Liu Kang stands before you.\n");
	liu=clone_object("/players/dragnar/mons/liu.c");
	move_object(liu, environment(this_object()));
	destruct(this_object());
	}
}

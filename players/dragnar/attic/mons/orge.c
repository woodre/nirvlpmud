inherit "obj/monster";
	object gold, key;

reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("Creighton");
   set_race("orge");
   set_alias("creighton");
	set_short("Creighton");
	set_long("This is a huge orge-magi that the darkside cult has summoned to do\n"+
"their bidding for them.  His eyes look empty as he looks right past you.\n");
   set_level(21);
   set_hp(1200);
   set_al(-1000);
   set_wc(42);
   set_ac(19);
	set_aggressive(1);
    gold = clone_object("obj/money");
	gold->set_money(random(500)+600);
   move_object(gold,this_object());
	key=clone_object("/players/dragnar/items/quest/mag2.c");
	move_object(key, this_object());
}
heart_beat() {
	object att;
	::heart_beat();
	att=(this_object()->query_attack());
	if(this_object()->query_attack()){
	if(random(100) > 80) {
	this_object()->heal_self(10);
	tell_object(att, "Creighton mumbles some words and seems to grow.\n");
	}
	}
}

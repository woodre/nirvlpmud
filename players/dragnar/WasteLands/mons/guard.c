inherit "obj/monster";
   object gold;

reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("Guard");
   set_race("guard");
   set_alias("guard");
	set_short("MP Police Guard");
	set_long("This guard was stationed here to stop unwanted people from\n"+
"venturing around.  He looks pissed off that your here.\n");
	set_level(14);
   set_hp(195);
   set_al(100);
   set_wc(22);
   set_ac(12);
	set_chat_chance(15);
	load_chat("Guard says: What the hell are you doing here??\n");
	load_chat("Guard says: This is a restricted area!\n");
	load_chat("Guard says: Get to the fallout shelter now!\n");
    gold = clone_object("obj/money");
	gold->set_money(random(500)+600);
   move_object(gold,this_object());
}

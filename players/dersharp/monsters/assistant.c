inherit "obj/monster";
reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("assistant");
   set_race("human");
   set_short("Assistant");
   set_long("	The teaching assistant barely notices you looking at\n"+
	    "him.  He looks up momentarily then looks back down at\n"+
	    "the pile of paper on his desk.\n");
   set_level(16);
   set_hp(400);
   set_wc(22);
   set_ac(13);
   set_al(0);
   set_chat_chance(3);
   load_chat("Assistant screams: These students are IDIOTS!!\n");
   load_chat("Assistant asks:  Have doctors looked at that nose of yours?\n");
   gold=clone_object("obj/money");
   gold->set_money(890);
   move_object(gold,this_object());
}

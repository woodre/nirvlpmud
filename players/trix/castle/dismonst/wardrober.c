inherit "obj/monster";
reset(arg){
   object gold;
   ::reset(arg);
   if(arg) return;
   set_name("wardrober");
   set_race("human");
   set_alias("wardrober");
   set_short("A wardrober");
   set_long("A busy wardrober , he runs from side to side of the wardrobe carrying coats.\n");
   set_level(16);
   set_hp(400);
   set_al(-100);
   set_wc(22);
   set_ac(13);
   set_aggressive(0);
   set_chat_chance (10);
   load_chat("The wardrober looks at you quizzically.\n");
   load_chat("The wardrober says: Would u like to leave your coat here?\n");
   set_chance(10);
   set_spell_dam(random(1)+1);
   set_spell_mess1("The growls at you.");
   set_spell_mess2("The wardrober blocks you with a scarf.");    
   gold=clone_object("obj/money");
   gold->set_money(850 + random(40));
   move_object(gold,this_object());
}

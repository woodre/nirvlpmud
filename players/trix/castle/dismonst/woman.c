inherit "obj/monster";
reset(arg){
   object gold;
   ::reset(arg);
   if(arg) return;
   set_name("woman");
   set_race("human");
   set_alias("woman");
   set_short("A young woman");
   set_long("A horny woman seems to be waiting for your company.\n");
   set_level(15);
   set_hp(225);
   set_al(-200);
   set_wc(20);
   set_ac(12);
   set_aggressive(0);
   set_chat_chance (10);
   load_chat("The woman looks horny.\n");
   load_chat("The woman spwawls on the couch with spreaded legs.\n");
   set_chance(10);
   set_spell_dam(random(1)+1);
   set_spell_mess1("The woman struggles.");
   set_spell_mess2("The woman punches your low parts.");    
   gold=clone_object("obj/money");
   gold->set_money(835 + random(40));
   move_object(gold,this_object());
}

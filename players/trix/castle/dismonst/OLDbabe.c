inherit "obj/monster";
reset(arg){
   object gold;
   ::reset(arg);
   if(arg) return;
   set_name("girl");
   set_race("human");
   set_alias("girl");
   set_short("A sexy girl");
   set_long("A sexy , inviting girl.\n");
   set_level(13);
   set_hp(195);
   set_al(10);
   set_wc(17);
   set_ac(10);
   set_aggressive(0);
   set_chat_chance (16);
   load_chat("The girl sprawls on the couch.\n");
   load_chat("The girl licks her lips.\n");
   set_chance(10);
   set_spell_dam(random(2)+1);
   set_spell_mess1("The girl kicks you.");
   set_spell_mess2("The girl scratches you.");    
   gold=clone_object("obj/money");
   gold->set_money(650 + random(50));
   move_object(gold,this_object());
}

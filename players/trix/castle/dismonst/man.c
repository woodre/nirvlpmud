inherit "obj/monster";
reset(arg){
   object gold;
   ::reset(arg);
   if(arg) return;
   set_name("man");
   set_race("human");
   set_alias("man");
   set_short("A rich old man");
   set_long("A rich old man , he seems horny and turned on.\n");
   set_level(16);
   set_hp(400);
   set_al(-100);
   set_wc(22);
   set_ac(13);
   set_aggressive(0);
   set_chat_chance (10);
   load_chat("The old man licks his lips.\n");
   load_chat("The man looks elegant but lascivous.\n");
   set_chance(10);
   set_spell_dam(random(1)+1);
   set_spell_mess1("The man spits on you.");
   set_spell_mess2("The man kicks you weakily.");    
   gold=clone_object("obj/money");
   gold->set_money(850 + random(40));
   move_object(gold,this_object());
}

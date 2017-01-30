inherit "obj/monster";
reset(arg){
   object gold;
   ::reset(arg);
   if(arg) return;
   set_name("seller");
   set_race("human");
   set_alias("seller");
   set_short("A ticket seller");
   set_long("The man who sells the tickets , he seems to be very greedy.\n");
   set_level(18);
   set_hp(450);
   set_al(100);
   set_wc(26);
   set_ac(15);
   set_aggressive(0);
   set_chat_chance (10);
   load_chat("The seller looks at you greedily.\n");
   load_chat("The seller says: hey hey hey, only 50 bucks to enter.\n");
   set_chance(10);
   set_spell_dam(random(1)+1);
   set_spell_mess1("The defends his money.");
   set_spell_mess2("The defends his money.");    
   gold=clone_object("obj/money");
   gold->set_money(1000);
   move_object(gold,this_object());
}

inherit "obj/monster";
reset(arg){
   object gold,xtc;
   ::reset(arg);
   if(arg) return;
   set_name("guy");
   set_race("human");
   set_alias("hallucinated");
   set_short("A hallucinated guy");
   set_long("A guy dancing like a possessed , he's under effect of some powerful acid.\n");
   set_level(20);
   set_hp(500);
   set_al(-10);
   set_wc(30);
   set_ac(17);
   set_aggressive(0);
   set_chat_chance (5);
   load_chat("The guy dances wildly.\n");
   set_a_chat_chance(20);
   load_a_chat("The guy punches you in the belly.\n");
   load_a_chat("The guy punches your nose.\n");
   gold=clone_object("obj/money");
   gold->set_money(4700+random(75));
   move_object(gold,this_object());
   if (random(10)<=8) {
   xtc=clone_object("/players/trix/castle/dismonst/machine/xtc");
   move_object(xtc,this_object());
   }
}

inherit "obj/monster";
reset(arg){
   object gold,axe;
   ::reset(arg);
   if(arg) return;
   set_name("black orc");
   set_race("orc");
   set_alt_name("orc");
   set_alias("trixborc");
   set_short("A huge black orc");
   set_long("A black orc that bars your was and looks at you menaceously.\n");
   set_level(16);
   set_hp(400);
   set_al(-2300);
   set_wc(24);
   set_ac(12);
   set_aggressive(1);
   set_a_chat_chance(15);
   load_a_chat("The black orc scratches your face.\n");
   load_a_chat("The black orc charges in your direction.\n");
   gold=clone_object("obj/money");
   gold->set_money(500+random(26));
   move_object(gold,this_object());
   axe=clone_object("/players/trix/castle/quest/monst/axe");
   move_object(axe,this_object());
}

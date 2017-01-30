inherit "obj/monster";
reset(arg){
   object gold,axe;
   ::reset(arg);
   if(arg) return;
   set_name("grey orc");
   set_race("orc");
   set_alt_name("orc");
   set_alias("trixgorc");
   set_short("A huge grey orc");
   set_long("A grey orc that bars your was and looks at you menaceously.\n");
   set_level(16);
   set_hp(400);
   set_al(-2300);
   set_wc(22);
   set_ac(13);
   set_aggressive(1);
   set_a_chat_chance(15);
   load_a_chat("The grey orc scratches your face.\n");
   load_a_chat("The grey orc charges in your direction.\n");
   gold=clone_object("obj/money");
   gold->set_money(400+random(26));
   move_object(gold,this_object());
   axe=clone_object("/players/trix/castle/quest/monst/axe");
   move_object(axe,this_object());
}

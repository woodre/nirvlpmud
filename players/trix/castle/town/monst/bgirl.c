inherit "obj/monster";
reset(arg){
   object gold;
   ::reset(arg);
   if(arg) return;
   set_name("baby");
   set_race("human");
   set_alias("girl");
   set_short("A little baby girl");
   set_long("A nice little baby girl in her pink dress.\n");
   set_level(1);
   set_hp(15);
   set_al(1000);
   set_wc(5);
   set_ac(3);
   set_aggressive(0);
   set_chat_chance (1);
   load_chat("The baby girl looks at you and giggles inanely.\n");
   load_chat("The baby girl says: baaa baaaa gaaaa eeeeeh.\n");
   load_chat("The baby girl drools.\n");
   load_chat("The baby girl shows you her toys.\n");
   set_a_chat_chance(15);
   load_a_chat("The baby girl screams loudly.\n");
   load_a_chat("The baby girl whines.\n");
   gold=clone_object("obj/money");
   gold->set_money(25+random(6));
   move_object(gold,this_object());
}

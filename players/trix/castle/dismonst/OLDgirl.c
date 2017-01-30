inherit "obj/monster";
reset(arg){
   object gold,skirt;
   ::reset(arg);
   if(arg) return;
   set_name("girl");
   set_race("human");
   set_alias("girl");
   set_short("A dancing girl");
   set_long("A dancing girl , she's so sexy in her short miniskirt that you gasp at every \n" +
      "movement of hers.\n");
   set_level(13);
   set_hp(195);
   set_al(100);
   set_wc(16);
   set_ac(10);
   set_aggressive(0);
   set_chat_chance (4);
   load_chat("The girl shakes her body.\n");
   load_chat("The girl winks at you suggestively.\n");
   set_a_chat_chance(35);
   load_a_chat("The girl scratches you.\n");
   load_a_chat("The girl screams: You fucking bastard!!!\n");
   load_a_chat("The girl knees you in the groin.\n");
   gold=clone_object("obj/money");
   gold->set_money(550+random(50));
   move_object(gold,this_object());
   skirt=clone_object("/players/trix/castle/dismonst/skirt.c");
   move_object(skirt,this_object());
}

inherit "obj/monster";
reset(arg){
   object gold;
   ::reset(arg);
   if(arg) return;
   set_name("gentleman");
   set_race("human");
   set_alias("man");
   set_short("A handsome gentleman");
   set_long("A distingueshed gentleman, wearing a dark suit, a white shirt and a\n"+
            "patterned neck-tie.\n");
/* Changed from level 10 stats to level 6 stats. They're people eating
  dinner in a restaurant... -Snow */
   set_level(6);
   set_hp(90);
   set_al(50);
   set_wc(10);
   set_ac(5);
   set_aggressive(0);
   set_chat_chance (10);
   load_chat("The gentleman looks at you disdainfully.\n");
   load_chat("The gentleman eats an oyster.\n");
   gold=clone_object("obj/money");
   gold->set_money(200 + random(50));
   move_object(gold,this_object());
}

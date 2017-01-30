inherit "obj/monster";
reset(arg){
   object gold;
   ::reset(arg);
   if(arg) return;
   set_name("clerk");
   set_race("human");
   set_aggressive(1);
   set_alias("clerk");
   set_short("A bank clerk");
   set_long("A man wearing glasses and a grey suit.  He looks sad and\n"+
            "unsatisfied with his job.\n");
   set_level(13);
   set_hp(195);
   set_al(300);
   set_wc(17);
   set_ac(10);
   set_aggressive(0);
   set_chat_chance (5);
   load_chat("The clerk looks at his papers and checks and sighs.\n");
   set_a_chat_chance(15);
   load_a_chat("The clerk says: Oh my God, wasn't my job enough?\n");
   load_a_chat("The clerk says: I can't take all of this!  Go away!!! \n"+
               "                Leave me alone!!!\n");
   gold=clone_object("obj/money");
   gold->set_money(650+random(51));
   move_object(gold,this_object());
}

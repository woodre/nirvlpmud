inherit "obj/monster";
reset(arg){
   object gold;
   ::reset(arg);
   if(arg) return;
   set_name("bouncer");
   set_race("human");
   set_alias("boy");
   set_short("A bouncer");
   set_long("This is a bouncer, a boy that is not enough old to get in the disco, he looks\n"+
            "around him to find a chance to enter, he will never give up.\n");
   set_level(8);
   set_hp(120);
   set_al(300);
   set_wc(12);
   set_ac(7);
   set_aggressive(0);
   set_chat_chance (5);
   load_chat("The bouncer struggles in the crowd.\n");
   load_chat("The bouncer looks around him smartly.\n");
   gold=clone_object("obj/money");
   gold->set_money(300+random(51));
   move_object(gold,this_object());
}

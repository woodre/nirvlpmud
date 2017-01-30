/* Changed level from 20 to 15, wc from 30 to 18, ac from 17 to 13
   and coins from 4750 to 800  -Snow */
inherit "obj/monster";
reset(arg){
   object gold,tin;
   ::reset(arg);
   if(arg) return;
   set_name("assistant");
   set_race("human");
   set_alias("shop assistant");
   set_short("A shop assistant");
   set_long(
"A woman wearing a green uniform.  She smiles at you and asks if you need\n"+
"anything.\n");
   set_level(15);
   set_hp(500);
   set_al(300);
   set_wc(18);
   set_ac(13);
   set_aggressive(0);
   set_chat_chance (5);
   load_chat("The assistant looks at you kindly.\n");
   set_a_chat_chance(15);
   load_a_chat("The assistant says: Hey!!! Not that kind of you!!!\n");
   load_a_chat("The assistant throws a tin of beans at you.\n");
   gold=clone_object("obj/money");
   gold->set_money(800+random(51));
   move_object(gold,this_object());
   tin=clone_object("/players/trix/castle/town/monst/beans");
   move_object(tin,this_object());
}

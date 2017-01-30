/* Changed level from 20 to 15, wc from 30 to 15, hps from 500 to 300, and
   coins from 1000 to 200 (still has bread) -Snow */
inherit "obj/monster";
reset(arg){
   object gold,bread;
   ::reset(arg);
   if(arg) return;
   set_name("baker");
   set_race("human");
   set_alias("");
   set_short("The Baker");
   set_long("A man covered with flour, dressed in white and with a soft strange hat on his\nhead.\n");
   set_level(15);
   set_hp(300);
   set_al(300);
   set_wc(15);
   set_ac(17);
   set_aggressive(0);
   set_chat_chance (5);
   load_chat("The baker dusts his clothes.\n");
   load_chat("The baker winks at you.\n");
   load_chat("The baker says: Wanna try my spicy bread?\n");
   set_a_chat_chance(15);
   load_a_chat("The baker shouts: Hey, get out of here!!!\n");
   load_a_chat("The baker throws a piece of bread on your face.\n");
   gold=clone_object("obj/money");
   gold->set_money(200+random(51));
   move_object(gold,this_object());
   bread=clone_object("/players/trix/castle/town/monst/bread");
   move_object(bread,this_object());
}

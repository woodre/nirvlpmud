/* Changed from lev.20 to 6, hp500 to 90, wc30 to 8, ac17 to 5, and coins
   4950 to 90 (A sad old newspaper seller) -Snow */
inherit "obj/monster";
reset(arg){
   object gold,news;
   ::reset(arg);
   if(arg) return;
   set_name("seller");
   set_race("human");
   set_alias("man");
   set_short("The news seller");
   set_long(
"You are looking at the news seller, a nice old man whose only purpose\n"+
"left in life is his job. How sad.\n");
   set_level(6);
   set_hp(90);
   set_al(300);
   set_wc(8);
   set_ac(5);
   set_aggressive(0);
   set_chat_chance (5);
   load_chat("The old seller looks at you with hope.\n");
   load_chat("The old seller says: Is there anything you're interested in?\n");
   load_chat("The old seller says: I've got every kind of magazine and newspaper.\n");
   set_a_chat_chance(15);
   load_a_chat("The old news seller hits you with a newspaper.\n");
   load_a_chat("The old news seller avoids your blows.\n");
   gold=clone_object("obj/money");
   gold->set_money(80+random(51));
   move_object(gold,this_object());
   news=clone_object("/obj/newspaper");
   move_object(news,this_object());
}

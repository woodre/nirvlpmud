inherit "obj/monster";
reset(arg){
   object gold,broom;
   ::reset(arg);
   if(arg) return;
   set_name("sacristan");
   set_race("human");
   set_alias("sacristan");
   set_short("The sacristan");
   set_long(
"This is the sacristan of the cathedral.  He looks over\n"+
"everything and does every little thing that has to be done\n"+
"in the management of the church.\n");
   set_level(17);
   set_hp(425);
   set_al(500);
   set_wc(24);
   set_ac(14);
   set_aggressive(0);
   set_chat_chance (10);
   load_chat("Sacristan says: What an awful job!\n");
   load_chat("Sacristan says: I wish I could be the bishop!!\n");
   load_chat("Sacristan says: If only I could rest a little bit!\n");
   load_chat("Sacristan sweeps the floor with his broom.\n");
   gold=clone_object("obj/money");
   gold->set_money(500 + random(50));
   move_object(gold,this_object());
   broom=clone_object("players/trix/castle/primonst/broom.c");
   move_object(broom,this_object());

}

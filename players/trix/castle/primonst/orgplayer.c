inherit "obj/monster";
reset(arg){
   object gold,pentagram;
   ::reset(arg);
   if(arg) return;
   set_name("sebastian");
   set_race("human");
   set_alias("player");
   set_short("Sebastian, the organ player");
   set_long(
"Sebastian, the organ player.  He's been deaf since his birth.\n");
   set_level(7);
   set_hp(105);
   set_al(100);
   set_wc(11);
   set_ac(6);
   set_aggressive(0);
   set_chat_chance (15);
   load_chat("Sebastian says: do re mi faaaaa.\n");
   load_chat("Sebastian plays a short melody on his organ.\n");
   load_chat("Sebastian says: I wish I could listen to my notes.\n");
   load_chat("Sebastian sighs.\n");
   set_chance(10);
   set_spell_dam(random(1)+1);
   set_spell_mess1("Sebastian throws his pentagram at you.");
   set_spell_mess2("Sebastian hurts your ears with a bad note.");
   gold=clone_object("obj/money");
   gold->set_money(100);
   move_object(gold,this_object());
   pentagram=clone_object("players/trix/castle/primonst/pentagram.c");
   move_object(pentagram,this_object());
}

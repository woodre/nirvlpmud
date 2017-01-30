inherit "obj/monster";
 
reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("gangbanger");
   set_race("human");
   set_alias("gang");
   set_alias("member");
   set_short("A viscious gangbanger");
   set_long("\n"+
"  A gang member.  He grew up on the streets and knows his way around.\n"+
"He knows what he likes and what he doesn't like, and he doesn't like you!\n"+
"You see him approach you and pull out a machete!\n");
   set_level(18);
   set_hp(275+random(300));
   set_aggressive(1);
   set_al(-100);
   set_wc(27);
   set_ac(16);
   set_chance(20);
   set_spell_dam(9+random(7));
  set_spell_mess1("Gangbanger takes a piece of your scalp with that slice!");
   set_spell_mess2("Gangbanger shows you his colors.");
   set_chat_chance(2);
  load_chat("Gangbanger tells you: I wouldn't take another step or you'll die!\n");
   load_chat("Gangbanger points and you and cackles with glee.\n");
   gold=clone_object("obj/money");
   gold->set_money(500+random(300));
   move_object(gold,this_object());
   move_object(clone_object("players/pathfinder/detroit/weapons/machete"), this_object());
}

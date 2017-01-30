inherit "obj/monster";
 
reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("crip");
   set_race("human");
   set_alias("gang");
   set_alias("recruit");
   set_short("A new recruit of the Crips");
   set_long("\n"+
"  A new recruit of the Crips.  He has grown up on these streets\n"+
"for most of his years, which don't number more than 15.  He is extremely\n"+
"fierce in his loyalty to his gang and his gang leaders.  He scoffs at your\n"+
"meager presence in his hood.\n");
  set_level(6);
   set_hp(50+random(35));
   set_al(-100);
   set_wc(13);
   set_ac(5);
   set_aggressive(1);
   set_chance(20);
   set_spell_dam(3+random(5));
   set_spell_mess1("Crip stabs you in the back with his knife!\n");
   set_spell_mess2("Crip shows you his gang sign.\n");
   set_chat_chance(2);
   load_chat("Crip tells you: I dare ya to step up.\n");
   load_chat("Crip laughs in your face!\n");
   gold=clone_object("obj/money");
   gold->set_money(random(200)+100);
   move_object(gold,this_object());
   move_object(clone_object("players/pathfinder/detroit/weapons/knife"),this_object());
}


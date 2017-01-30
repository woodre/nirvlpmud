inherit "obj/monster";
 
reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("blood");
   set_race("human");
   set_alias("gang");
   set_alias("recruit");
   set_short("A new recruit of the Bloods");
   set_long("\n"+
"  A new recruit of the Blood's gang.  He has grown up on these streets\n"+
"for most of his years, which don't number more than 15.  He has a fierce\n"+
"loyalty to his gang and his leaders.  To you he doesn't seem like much\n"+
"more than a street punk, but when he isn't alone he is viscious.\n");
   set_level(7);
   set_hp(50+random(40));
   set_al(-100);
   set_wc(14);
   set_ac(5);
   set_aggressive(1);
   set_chance(20);
   set_spell_dam(3+random(5));
   set_spell_mess1("Blood pokes you in the eye with his knife!\n");
   set_spell_mess2("Blood shows you his gang sign.\n");
   set_chat_chance(2);
   load_chat("Blood tells you: I dare ya to step up.\n");
   load_chat("Blood laughs in your face!\n");
   gold=clone_object("obj/money");
   gold->set_money(random(200)+100);
   move_object(gold,this_object());
   move_object(clone_object("players/pathfinder/detroit/weapons/knife"),this_object());
}


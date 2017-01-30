inherit "obj/monster";
 
reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("travel agent");
   set_race("human");
   set_alias("travel");
   set_alias("agent");
   set_short("A travel agent");
   set_long("\n"+
"  A travel agent.  They work long hours to fulfill your needs.  They like\n"+
"to help you find an area and help put you there.  To find out specific\n"+
"information on a certain wizards area just type 'info <wizard>' and you will\n"+
"recieve all the information we currently have.\n");
   set_level(19);
   set_hp(1000);
   set_al(100);
   set_wc(45);
   set_ac(30);
   set_chance(12);
   set_spell_dam(13);
  set_spell_mess1("Agent buries you underneath their paperwork.\n");
   set_spell_mess2("Agent hits you in the head with a brochure.\n");
   set_chat_chance(2);
   load_chat("Agent says: To find out more info on a wiz's area type 'info <wiz>'.\n");
   load_chat("Agent says: I can help you find out more info on a certain wiz's area.\n");
   gold=clone_object("obj/money");
   gold->set_money(random(1000)+1000);
   move_object(gold,this_object());
}

inherit "/players/mizan/closed/FuzzyBeast.c";
reset(arg){
   object gold;
   ::reset(arg);
   if(arg) return;
   set_name("girl");
   set_race("human");
   set_alias("girl");
  short_desc=({
    "A sexy girl lying on a couch",
    "A beautiful girl lying on a couch",
    "A scantily clad girl lying on a couch",
    "A sexy girl, sprawled out on a couch",
    "A terribly attractive girl",
    "A terribly attractive girl lying before you",
    "An enchanting girl lying before you",
  });
  long_desc=({
    "Before you is an utterly beautiful girl spead out on a couch.\n"+
    "You just cannot help but stare at her...\n",
    "Before you is a young girl, scantily clad, lying spread out on a\n"+
    "luxurious couch. Terrifyingly seductive, you are tempted to kiss\n"+
    "and try out other assorted verbs on her... and it takes nearly\n"+
    "superhuman effort and self control to resist...\n",
    "Lying out on a comfy sofa, this young girl is terribly attractive,\n"+
    "and so inviting just being there...\n"
    });
   set_level(13);
   set_hp(195);
   set_al(10);
   set_wc(17);
   set_ac(10);
   set_aggressive(0);
   set_chat_chance (16);
   load_chat("The girl sprawls on the couch.\n");
    load_chat("The girl looks you up and down.\n");
   load_chat("The girl licks her lips.\n");
   set_chance(6);
   set_spell_dam(random(2)+1);
   set_spell_mess1("The girl kicks you.");
  set_spell_mess2("The girl screams at you!\n");
   gold=clone_object("obj/money");
   gold->set_money(650 + random(50));
   move_object(gold,this_object());
  ::reset(arg);
}

inherit "/players/mizan/closed/FuzzyBeast.c";
reset(arg){
   object gold,skirt;
   if(arg) return;
   set_name("girl");
   set_race("human");
   set_alias("girl");
    short_desc=({
    "A dancing girl",
    "A dancing girl (sexy)",
    "A scantily clad dancing girl",
    "A beautiful dancing girl",
    "A dancing girl (sexy)",
    "A girl, swaying to the beat",
    "A dancing girl (beautiful)",
    "A scantily clad girl",
  });
  long_desc=({
    "A dancing girl , she's so sexy in her short miniskirt that you gasp at every\n" +
    "movement of hers.\n"+
    "Before you is a scantily clad girl, her high-cut miniskirt reveals so much of\n"+
    "her legs (and elsewhere) that your imagination is underworked...\n",
    "Every movement she makes captures your undivided attention... You have the\n"+
    "urge to reach out and touch her, kiss her, and other assorted verbs\n"+
    "but... well... That would'nt be good, would it?\n",
    "A beautiful young girl dances here, her every movement capturing your\n"+
    "attention... You wonder if that is a miniskirt she is wearing, or a tourniquet\n"+
    "for the hips...\n",
  });
  ::reset(arg);
   set_level(13);
   set_hp(195);
   set_al(100);
   set_wc(16);
   set_ac(10);
   set_aggressive(0);
   set_chat_chance (4);
  load_chat("The girl sways her hips to the beat.\n");
  load_chat("The girl smiles at you and coos softly.\n");
   load_chat("The girl shakes her body.\n");
   load_chat("The girl winks at you suggestively.\n");
   set_a_chat_chance(35);
   load_a_chat("The girl scratches you.\n");
   load_a_chat("The girl screams: You fucking bastard!!!\n");
   load_a_chat("The girl knees you in the groin.\n");
   gold=clone_object("obj/money");
   gold->set_money(550+random(50));
   move_object(gold,this_object());
   skirt=clone_object("/players/trix/castle/dismonst/skirt.c");
   move_object(skirt,this_object());
}

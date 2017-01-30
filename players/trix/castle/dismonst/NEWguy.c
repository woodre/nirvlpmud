inherit "/players/mizan/closed/FuzzyBeast.c";
reset(arg){
   object gold,xtc;
   if(arg) return;
   set_name("guy");
   set_race("human");
   set_alias("hallucinated");
  short_desc=({
    "A hallucinated guy",
    "A totally smashed guy",
    "A hallucinated guy (stoned)",
    "A totally spaced-out guy",
    "A spaced-out guy",
    "A guy (drugged beyond belief)",
    "A completely stoned guy",
    "A completely smashed guy (stoned like you wouldnt believe)",
    "A hallucinated guy (spaced)",
   });
  long_desc=({
    "This is a guy dancing like a possessed, he's under effect of some\n"+
   "SERIOUSLY powerful acid.\n",
    "This guy is totally, absolutely stoned... You wonder how he keeps dancing...\n",
    "Before you stands a hopelessly drugged, but continuously dancing guy.\n"+
    "I bet you could kick him where the sun doesnt shine, and nothing would\n"+
    "happen...\n",
    "Caught in the hypnotic rhythm of acid techno... this guy looks like he\n"+
    "could dance forever, locked in a glazed, yet happy state.\n",
  });
  ::reset(arg);
   set_level(20);
  set_hp(480+random(60));
   set_al(-10);
   set_wc(30);
   set_ac(17);
   set_aggressive(0);
   set_chat_chance (5);
   load_chat("The guy dances wildly.\n");
  load_chat("The guy falls into a trance with the beat.\n");
  load_chat("The guy seems to be lost in his own little world.\n");
   set_a_chat_chance(20);
   load_a_chat("The guy punches you in the belly.\n");
   load_a_chat("The guy punches your nose.\n");
   gold=clone_object("obj/money");
   gold->set_money(4700+random(75));
   move_object(gold,this_object());
   if (random(10)<=8) {
   xtc=clone_object("/players/trix/castle/dismonst/machine/xtc");
   move_object(xtc,this_object());
   }
}

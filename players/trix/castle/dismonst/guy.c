/*
Changes:
9-19-01 Made some changes to the stats to make it a more viable target,
        fixed some typos, and fixed the spacing a little.
        - Feldegast
*/

inherit "/players/mizan/closed/FuzzyBeast.c";

reset(arg){
   object gold,xtc;
   int me;
   if(arg) return;
   me = random(3);
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
    "A completely smashed guy (stoned like you wouldn't believe)",
    "A hallucinated guy (spaced)",
   });
   long_desc=({
    "This guy is dancing like he's possessed.  He's under the effect of some\n"+
    "SERIOUSLY powerful acid.\n",
    "This guy is totally, absolutely stoned... You wonder how he keeps dancing.\n",
    "Before you stands a hopelessly drugged, but continuously dancing guy.\n"+
    "I bet you could kick him where the sun doesnt shine, and nothing would\n"+
    "happen.\n",
    "Caught in the hypnotic rhythm of acid techno... this guy looks like he\n"+
    "could dance forever, locked in a glazed, yet happy state.\n",
   });
   ::reset(arg);
/* Changed from level 20 to 14+random(3) with corresponding
   changes in stats. -Snow */
   set_level(14+me);
   set_hp(210 + (30*me) );
   set_al(-10);
   set_wc(18 + 2*me);
   set_ac(11 + me);
   if(random(3) == 0)
     set_aggressive(1);
   else
     set_aggressive(0);
   set_chat_chance (5);
   load_chat("The guy dances wildly.\n");
   load_chat("The guy falls into a trance with the beat.\n");
   load_chat("The guy seems to be lost in his own little world.\n");
   set_a_chat_chance(20);
   load_a_chat("The guy punches you in the belly.\n");
   load_a_chat("The guy punches your nose.\n");
   gold=clone_object("obj/money");
   gold->set_money(800 + (me * 50 * (1 + random(4)) ) );
   move_object(gold,this_object());
   if (!random(5)) {
     xtc=clone_object("/players/trix/castle/dismonst/machine/xtc");
     move_object(xtc,this_object());
   }
}

#include "/players/mythos/amon/hb_ag.h"

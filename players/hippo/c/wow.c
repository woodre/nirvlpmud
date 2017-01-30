#include "/players/hippo/bs.h"
inherit "obj/monster";

void reset(int arg){
   ::reset(arg);
set_name("carcinome");
set_alias("wow");
set_short("WOW, a carcinome");
set_long("Wow, what an immense thing you see here.. You can't believe\n"+
   "this is real. Maybe you could try to fight it? It will not\n"+
   "be easy to kill this fellow, though.\n"+
"btw: You can call him WOW, and he has 5000 coins in his pocket.\n");
/* Changed from 40 to 30 (tough but nothing special) -Snow */
set_level(30);
set_ac(35);
set_wc(50);
set_hp(1500);
set_al(-1000);

   money=5000;
set_a_chat_chance(30);
   load_a_chat("YEAH... I'm the best\n");
   load_a_chat("You can't win this fight, silly guy\n");
   load_a_chat("You checked my level and hp before you attacked me?\n");
   load_a_chat("What do you think you are trying to do? Hurt me?\n");
   load_a_chat("I don't think you get this quite clear...\n");
   load_a_chat("When was the last time you saw a doctor?\n");
   load_a_chat("\n"+
   query_name(attacker_ob)+" is attacked by "+
   query_name(kill_ob)+
   "\n");}


#include "/players/mythos/amon/hb_ag.h"

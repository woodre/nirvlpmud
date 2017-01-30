#include "../define.h"
inherit "/obj/monster";

int y;
reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("sardka");
   set_short("A greasy old man");
   set_long(
      "   Wearing an old, wifebeater t-shirt and a pair\n"+
      "of torn brown pants, this old guy has been here\n"+
      "in the village for some time.  He is from a more\n"+
      "civilized age, but he doesn't act like it.  He\n"+
      "is here trying to make his fortune, but isn't\n"+
      "succeeding.\n");
   set_alias("man");
   set_alt_name("old man");
   set_race("human");
   set_gender("male");
   set_level(12);
   GUIDE->calc_stats(12);
   set_hp(GUIDE_HP);
   set_wc(GUIDE_WC);
   set_ac(GUIDE_AC);
   set_chat_chance(5);
   set_a_chat_chance(5);
   load_chat("Sardka grunts and scratches himself.\n");
   load_chat("Sardka grunts, \"See anyding youse likes?\"\n");
   load_chat("Sardka frowns.\n");
   load_chat("Sardka says, \"If ya ain't buyin, get the frig oudda heah!\"\n");
   load_chat("Sardka inspects the glass case.\n");
   load_chat("Sardka gobbles down some nachos.\n");
   load_a_chat("Sardka punches you in the stomach!\n");
   load_a_chat("Sardka kicks you!\n");
   add_money(500+random(200));
   load_a_chat("Sardka says, \"I knew youse wasnt up to no good.\"\n"); }


catch_tell(string str) {
   string msg; object RING, gold; int x;
   if(sscanf(str,"%s gives",msg)) {
      RING = present("v_gold_ring",TO);
      if(RING && !y) {
         x = 3000+random(1000);
         tell_room(USER,
            "Sardka says, \" Thank you! I have been looking for this gold ring\n"+
            "                for years!  It was lost to me some time ago when\n");
         tell_room(USER,
            "                I first moved here, but I never thought anyone\n"+
            "                would help a tightwad like me.  Here, take this\n");
         tell_room(USER,
            "                with my gratitude! \"\n\n");
         command("wear ring",TO);
         tell_room(USER,
            "Sardka takes "+x+" gold coins from his pocket and hands them to you.\n");
         TP->add_money(x);
         y = 1;
         return 1; }
   }
   return 1; }

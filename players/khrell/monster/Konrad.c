#include "/players/khrell/ansi.h"
inherit "/obj/monster";

int tranced;

reset(arg) {
   ::reset(arg);
   if(arg) return;

   set_name(RED+"Konrad Von Carstein"+NORM);
   set_alt_name("konrad");
   set_alias("konrad");
   set_short(RED+"konrad Von Carstein"+NORM);
   set_long("The infamous lord before you is none other than\n"+
            "Konrad, one the most feared vampires of all time.\n"+
            "Ruler of lands in Sylvania, he was known for his\n"+
            "iron rule, and brutal justice. His favorite past time\n"+
            "was to 'sit' peasants on a spike, attach weights then \n"+
            "listen to their tortured screams while he read.\n"+
            "   He has pure white skin, and dark hair that is long,\n"+
            "but pulled back. His piercing green eyes, seem to look\n"+
            "into your very center. Konrad the demon, or the demon\n"+
            "as the peasants called him,\n");
   set_gender("male");
   set_race("vampire");
   set_level(40);
   set_wc(50);
   set_ac(20);
   set_hp(5000);
   set_al(-2000);
   set_heal(5,3);
   set_aggressive(1);
   set_chat_chance(8);
   load_chat(RED+"Konrad"+NORM+" gazes at you with animialistic intent.\n");
   load_chat(RED+"Konrad"+NORM+" says, \"Have you come to feed me?\"\n");
   load_chat(RED+"Konrad"+NORM+" looks at you with a longing hunger.\n");           
   set_a_chat_chance(15);
   load_a_chat(RED+"Konrad"+NORM+" says, \"Soon I shall feed.\"\n");
   load_a_chat(RED+"Konrad"+NORM+" roars, \"I shall add your corpse to my legions of undead!\"\n");
   set_chance(10);
   set_spell_mess1(RED+"Konrad"+NORM+" bites at his attacker's neck,\n\n"+
                   RED+"          B   L   O   O   D \n"+NORM+
                       "sprays all around the room.\n");

   set_spell_mess2(RED+"Konrad"+NORM+" bites at your neck...\n\n"+
                   RED+"          B   L   O   O   D \n"+NORM+
                       "spurts from your throat.\n");
   set_spell_dam(100);
}                     
    




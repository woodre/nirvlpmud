#include "/players/llew/closed/ansi.h"
inherit "/obj/monster";

int tranced;

reset(arg) {
   ::reset(arg);
   if(arg) return;

   set_name(RED+"Vlad"+NORM+" the "+HIR+"Impaler"+NORM);
   set_alt_name("vlad");
   set_alias("dracula");
   set_short(RED+"Vlad"+NORM+" the "+HIR+"Impaler"+NORM);
   set_long("The regal prince before you is none other than\n"+
            "Dracula, the most famous vampire of all time.\n"+
            "Ruler of lands in Romania, he was known for his\n"+
            "iron rule, and swift justice. His favorite punishment\n"+
            "for criminals was to 'sit' them on a spike, and let\n"+
            "gravity slowly impale them.\n"+
            "   He has pure white skin, and dark hair that is long,\n"+
            "but pulled back. His piercing green eyes, seem to look\n"+
            "into your very center. Vlad the Impaler, or Dracula\n"+
            "as the peasants called him,-which means 'Son of the Devil'-\n"+
            "is truly a fearsome foe.\n");
   set_gender("male");
   set_race("vampire");
   set_level(20);
   set_wc(30);
   set_ac(17);
   set_hp(500);
   set_al(-1000);
   set_heal(5,3);
   set_aggressive(1);
   set_chat_chance(8);
   load_chat(RED+"Vlad"+NORM+" gazes down at you from his throne.\n");
   load_chat(RED+"Vlad"+NORM+" says, \"You have come to be sentenced?\"\n");
   load_chat(RED+"Vlad"+NORM+" looks at you with a longing hunger.\n");           
   set_a_chat_chance(15);
   load_a_chat(RED+"Vlad"+NORM+" says, \"Soon I shall feed.\"\n");
   load_a_chat(RED+"Vlad"+NORM+" says, \"I shall put your corpse on a spike in the town square.\"\n");
   set_chance(15);
   set_spell_mess1(RED+"Vlad"+NORM+" bites at his attacker's neck,\n\n"+
                   RED+"          B   L   O   O   D\n\n"+NORM+
                       "sprays all around the room.\n");

   set_spell_mess2(RED+"Vlad"+NORM+" bites at your neck...\n\n"+
                   RED+"          B   L   O   O   D\n\n"+NORM+
                       "spurts from your throat.\n");
   set_spell_dam(35);
}                     
    
heart_beat() {
   ::heart_beat();
   if(attacker_ob && !random(12)) {
      if(!present("dracula dire wolf 3")) {
         tell_room(environment(),name+" summons a "+BOLD+BLK+"Dire Wolf"+NORM+" to tear you to pieces.\n");
         move_object(clone_object("/players/ulath/darkness/monsters/wolf"),environment());
         present("dracula dire wolf")->attack_object(attacker_ob);
      }
   }
   if(attacker_ob && !random(17) && !tranced) {
      attacker_ob->stop_fight();
      attacker_ob->stop_fight();
      tell_room(environment(),name+" transfixes you with his deep, "+GRN+"emerald"+NORM+" eyes.\n");
      tranced++;
   }
   if(tranced) {
      attacker_ob->stop_fight();
      attacker_ob->stop_fight();
      tranced++;
      if(!random(tranced+1) || tranced == 3) tranced = 0;
   }
}




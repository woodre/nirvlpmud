#include "/players/khrell/ansi.h"
#include "/players/khrell/define.h"
inherit "/obj/monster";

int tranced;

reset(arg) {
   ::reset(arg);
   if(arg) return;

   set_name(HIR+"Vardak the Butcher"+NORM);
   set_alt_name("butcher");
   set_alias("vardak");
   set_short(HIR+"Vardak the Butcher"+NORM);
   set_long("The infamous lord before you is none other than\n"+
            "Vardek the butcher, exalted champion of the foul\n"+
            "gods of chaos.  Years ago he battled his way from\n"+
            "his marauder tribe and sought out the gods of his\n"+
            "his people as a rite of passage to manhood. Along \n"+
            "the way he gained many followers in his retinue and\n"+
            "now commands many blood-thirsty followers.  None have\n"+
            "been able to stand against his reaving rampage over\n"+
            "the lands.  And none have been able to defeat him in\n"+
            "single combat.\n");
   set_gender("male");
   set_race("human");
   set_level(28);
   set_ac(30);
   set_hp(1300);
   set_al(-2000);
   set_heal(30,3);
   set_aggressive(2);
move_object(clone_object("/players/khrell/weapons/khorneaxe.c"));
init_command("wield axe"); 
   set_wc(60);  
   set_chat_chance(8);
   load_chat(HIR+"Vardak"+NORM+" gazes at you undisguised hatred.\n");
   load_chat(HIR+"Vardak"+NORM+" says, \"Have you come to die?\"\n");
   load_chat(HIR+"Vardak"+NORM+" looks at you with a longing hunger.\n");           
   set_a_chat_chance(15);
   load_a_chat(HIR+"Vardak"+NORM+" says, \"Soon I shall add your flesh to my standard.\"\n");
   load_a_chat(HIR+"Vardak"+NORM+" roars, \"I will add your corpse to my abbotoir!\"\n");
   set_chance(100);
   set_spell_mess1(HIR+"Vardak"+NORM+" slashes at his attacker,\n\n"+
                   RED+"        ~  B   L   O   O   D ~\n"+NORM+
                       "sprays all around the room.\n");

   set_spell_mess2(HIR+"Vardak"+NORM+" slashes at you...\n\n"+
                   RED+"        ~  B   L   O   O   D ~\n"+NORM+
                       "sprays from the wound.\n");
   set_spell_dam(150);
   set_chance(25);
   set_spell_mess1(HIR+"Vardak"+NORM+" violently chops his axe\n"+
                   "                WITH                               \n"+
                   "     "+HIR+"R "+NORM+RED+"A "+HIR+"G "+NORM+RED+"E"+NORM+BOLD+" ! !"+NORM+"\n");
   set_spell_mess2(HIR+"Vardak"+NORM+" violently chops with his axe!\n");
   set_spell_dam(100);              
}                     
    




#include "/players/languilen/closed/ansi.h"
inherit "obj/monster.c";

reset(arg) {
     int i;
     ::reset(arg);
     if(arg) return;
     i = random(4);

     switch(i){
          case 0: {
               set_name("child");
               set_alias("child");
               set_race("human");
               set_short("A small child");
               set_long(
"This is a very small child who couldn't possibly have come here alone.\n\
There must be an older sibling around who accompanied the child but\n\
became lost in the chaos and confusion of the hall of mirrors.\n");

               set_level(2);
               set_hp(random(10)+25);
               set_al(-10);
               set_wc(6);
               set_ac(3);
/*             set_heal(amt,rate);    */
               set_aggressive(0);

               set_chat_chance(5);
                  load_chat("The child says: Ummmm, maya ma'o bafoom.\n");
               set_a_chat_chance(8);
                  load_a_chat("The child SCREAMS for its mommy! \n");

               add_money(random(25)+35);
               break;
          }
          case 1: {
               set_name("girl");
               set_alias("child");
               set_race("human");
               set_short("A young girl");
               set_long(
"Golden lockets of hair fall upon the delicate shoulders of this whispy\n\
little girl.  Her innocent eyes wide in wonder at the incredible array of\n\
sights and sounds all around her.\n");

               set_level(5);
               set_hp(random(10)+70);
               set_al(-20);
               set_wc(9);
               set_ac(5);
/*             set_heal(amt,rate);   */
               set_aggressive(0);

               set_chat_chance(4);
                  load_chat("The girl asks: Have you seen My little sister?\n");
               set_a_chat_chance(8);
                  load_a_chat("The girl says: I'm gonna tell my big brother and he's gonna beat you up! \n");

               set_chance(10);
               set_spell_dam(4);

               set_spell_mess1(
                  "The girl SCRATCHES her attacker! \n");
               set_spell_mess2(
                  "The girl SCRATCHES at you! \n");

               add_money(random(50)+150);
               break;
          }
          case 2: {
               set_name("boy");
               set_alias("child");
               set_race("human");
               set_short("A young boy");
               set_long(
"Running tirelessly around, stopping only long enough to make faces in\n\
the mirrors, this laughing youngster seems to be having the time of his\n\
life.\n");

               set_level(8);
               set_hp(random(25)+100);
               set_al(-25);
               set_wc(12);
               set_ac(7);
/*             set_heal(amt,rate);  */
               set_aggressive(0);

               set_chat_chance(4);
load_chat("The boy says: The hall of mirrors is great! \n");
               set_a_chat_chance(6);
load_a_chat("The boy says: Oh yeah?  I'll get you for that! \n");

               set_chance(10);
               set_spell_dam(8);

               set_spell_mess1(
                  "The boy KICKS his attacker! \n");
               set_spell_mess2(
                  "The boy KICKS at you! \n");

               add_money(random(100)+250);
               break;
          }
          case 3: {
               set_name("teenager");
               set_alias("teen");
               set_race("human");
               set_short("A Teenager");
               set_long(
"The teen wanders casually about, occasionally laughing at an odd\n\
reflexion.  Far above running around giggleing with the younger kids,\n\
the teenagers seem to gather in groups.  When not around any other\n\
teenagers they seem bored or irritated by thier juniors.\n");

               set_level(10);
               set_hp(random(25)+130);
               set_al(-50);
               set_wc(15);
               set_ac(9);
/*             set_heal(amt,rate);  */
               set_aggressive(0);

               set_chat_chance(4);
                  load_chat("The teenager says: You should dunk someone in the dunk tank! \n");
               set_a_chat_chance(10);
                  load_a_chat("The teenager says: You're in for it now! \n");

               set_chance(10);
               set_spell_dam(5);

               set_spell_mess1(
                  "The teenager cops an attitude! \n");
               set_spell_mess2(
                  "The teenager hits you with attitude! \n");

               add_money(random(40)+380);
               break;
          }
     }
}


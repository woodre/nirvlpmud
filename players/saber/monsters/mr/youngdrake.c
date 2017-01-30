inherit "/obj/monster";
#include "/players/saber/closed/ansi.h"

reset(arg) {
   ::reset(arg);
   if (!arg) {

  object gold;

  gold = clone_object("obj/money");
    gold->set_money(200 + random(500));
    move_object(gold,this_object());
    
     set_name( "sun drake" );
     set_short("A Young Sun Drake");
     set_gender("creature");
     set_alt_name("drake");
     set_race("dragon");
     set_long("The Young Sun Drake is a creature of greyhound size, with golden scales\n"+
              "and molten claws.  It's tail is spiked, and breath emerges hot as the sun.\n");
     set_level(10);
     set_heal(3,20);
     set_ac(8);
     set_wc(14);
     set_hp(150);
     set_al(-500);
     set_aggressive(0);
     set_dead_ob(this_object());
     set_chat_chance(7);
     set_a_chat_chance(11);
     load_chat("The Young Sun Drake drifts on the thermals.\n");
     load_chat("The Young Sun Drake glances down at you.\n");
     load_a_chat("The Young Sun Drake ROARS!!!\n");
     load_a_chat("The Sun Young Drake lashes at you with its tail.\n");
     load_a_chat("The Sun Young Drake buffets you with it's wings.\n");
     set_spell_mess1("The Young Sun Drake breaths "+HIY+BOLD+"FLAME"+NORM+".");
     set_spell_mess2("The Young Sun Drake breaths "+HIY+BOLD+"FLAME"+NORM+" at you.");
     set_chance(15);
     set_spell_dam(15);
   }
  }

monster_died()  {
object ob;
  tell_room(environment(this_object()),
     "\nThe young Sun Drake falls to the ground in a pool of golden blood.\n\n");
  return 0;
        }

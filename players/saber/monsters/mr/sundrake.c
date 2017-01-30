inherit "/obj/monster";
#include "/players/saber/closed/ansi.h"

reset(arg) {
   ::reset(arg);
   if (!arg) {

  object ob;

ob = clone_object("/players/saber/armor/sun_cloak.c");
move_object(ob,this_object());

     set_name( "sun drake" );
     set_short("A Massive Sun Drake");
     set_alias("drake");
     set_race( "dragon");
     set_gender("creature");
     set_heal(5,25);
     set_long("The Sun Drake is a creature of gargantuan size, with golden scales and\n"+
              "molten claws.  It's tail is spiked, and breath emerges hot as the sun.\n");
     set_level(21);
     set_ac(17);
     set_wc(32);
     set_hp(700);
     set_al(-950);
     set_aggressive(0);
     set_dead_ob(this_object());
     set_chat_chance(7);
     set_a_chat_chance(11);
     load_chat("The Sun Drake drifts on the thermals.\n");
     load_chat("The Sun Drake drifts closer to the sun.\n");
     load_chat("The Sun Drake glances down at you.\n");
     load_a_chat("The Sun Drake ROARS!!!\n");
     load_a_chat("The Sun Drake lashes at you with its tail.\n");
     load_a_chat("The Sun Drake buffets you with it's wings.\n");


set_spell_mess1(
"The Sun Drake BREATHS\n"+HIY+""+
"\n  ******************************           ******************************\n"+
"  *****************************  F L A M E  *****************************\n"+
"  ******************************           ******************************\n\n"+NORM);
set_spell_mess2(
"The Sun Drake BREATHS\n"+HIY+""+
"\n  ******************************           ******************************\n"+
"  *****************************  F L A M E  *****************************\n"+
"  ******************************           ******************************\n\n"+NORM);
     set_chance(15);
     set_spell_dam(50);
   }
  }

monster_died()  {
object ob;
  tell_room(environment(this_object()),
   "\nThe Sun Drake staggers back, blood flowing from it's numerous wounds.\n\n"+
   "The Sun Drake drops dead, it's corpse drifting slowly up to the sun.\n\n");
  return 0;
        }

/* Dennis Miller */

#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */

inherit "/obj/monster.c";
object gold, football;    /* Moved object declaration outside of reset()
                            --Rumplemintz */

reset(arg)
{
   ::reset(arg);
   if (arg) return;
   /*   object gold, football;   */
   gold = clone_object("obj/money");
   gold->set_money(random(501) + 1500);
   move_object(gold,this_object());
   football =clone_object("/players/aingeal/casino/treasure/football.c");
   move_object(football,this_object());
   set_name("dennis");
   set_alias("miller");
   set_alt_name("entertainer");
   set_short("Dennis Miller");
   set_race("human");
   set_long("Dennis Miller smirks at the audience, his teeth gleeming\n\
      through the black tuft of hair of his mustache and goatee.\n\
      Dressed in unwrinkled khakis and a black turtleneck sweater, he\n\
      delivers his next stinging, sarcastic quip with cool confidence.\n");
   set_level(17);
   set_ac(13 + random(2));
   set_wc(22 + random(3));
   set_hp(320 + random(31));
   set_al(-1000);
   set_aggressive(0);
   set_chat_chance(10);
   set_a_chat_chance(25);
   set_chance(10);
   set_spell_mess1("\n\tDennis "+RED+"SLICES"+NORM+" his opponent to the bone\n\
      \n\twith his razor-sharp wit!\n");
   set_spell_mess2("\n\tDennis "+RED+"SLICES"+NORM+" you to the bone\n\
      \n\twith his razor-sharp wit!\n");
   set_spell_dam(30);
   load_chat("Dennis says,'Now, I don't want to get off on a rant here, but...'\n");
   load_chat("Dennis rants, 'If religion is the opiate of the masses, then\n\
      religious zealots are the crack addicts.'\n");
   load_chat("Dennis rants, 'These days, truth in media has been pushed\n\
      further into the backseat than loose change during a shuttle launch.'\n");
   load_chat("Dennis stalks across the stage as he rants, \n\
      'The war on drugs is a more frustrating stalmate than\na tug-of-war on ice!\n");
   load_chat("Dennis rants, 'We as Americans don't like being inconvenienced.\n\
      In fact, we are now unwilling to lift a finger unless it's to let\n\
      another driver know what we think of him.\n");
   load_a_chat("Dennis rants, 'You're such a wimp!\n");
   load_a_chat("Dennis ducks out of your way with a sardonic peel of laughter.\n");
   load_a_chat("Dennis falls back into a fighter's stance and shouts, 'Bring it!'\n");
   load_a_chat("Dennis kicks you hard below the belt!\n");
}

#include "/players/softly/closed/ansi.h"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (arg) return;
   move_object(clone_object("/players/softly/point/obj/bkboots.c"),this_object());
   set_name("morgan");
   set_short(BOLD + "Ghost" + NORM + " of Captain Sir Henry Morgan");
   set_alias("ghost");
   set_long("\
  A tall well dressed gentleman with a paunch, Captain Morgan\n\
wears a blue jacket and matching trousers embellished with\n\
golden ornamentation and high glossy black boots..  He wears\n\
long wavy hair and a moustache.\n");
   set_race("ghost");
   set_level(19);
   set_ac(16);
   set_wc(28);
   set_hp(450);
   set_al(-100);
   set_chance(30);
   set_spell_dam(25);
   set_spell_mess1("Morgan lashes out with a broken rum bottle.\n");
   set_spell_mess2("\nMorgan hacks at you with a broken rum\n"+
                   "bottle.  He slices you and your "+HIR+"blood "+NORM+"flows.\n");
   add_money(3300+random(200));   
}

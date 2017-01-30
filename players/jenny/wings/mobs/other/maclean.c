inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "ron maclean" ||  str == "ron" || str == "maclean" || str == "Ron MacLean"; } 

reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_name("Ron MacLean");
   set_race("human");
   set_gender("male");
   set_al(300);
   set_level(11);
   set_hp(165);
   set_wc(15);
   set_ac(9);
   add_money(490+random(20));
   set_short(BOLD+WHT+"Ron MacLean"+NORM);
   set_long(
      "Ron MacLean is a commentator for Hockey Night in Canada.  He is a\n"+
      "Middle-aged man with brown hair and dressed in a black suit.  Ron is\n"+
      "a very knowledgeable hockey person, and has a likeable easy-going\n"+
      "personality that meshes nicely with the outrageous Don Cherry.\n");
}

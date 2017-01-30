inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_name("Cameraman");
   set_alt_name("cameraman");
   set_alias("man");
   set_race("human");
   set_gender("male");
   set_al(50+random(10));
   set_level(8);
   set_hp(110+random(20));
   set_wc(12+random(2));
   set_ac(6+random(2));
   add_money(300+random(100));
   set_short("A cameraman");
   set_long(
      "This is a man who works the television camera.  He is an overweight\n"+
      "guy with dark hair, and wearing a white t-shirt with a mustard stain\n"+
      "on it.\n");
}

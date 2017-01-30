inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("yvette");
    set_alias("girl");
    set_race("human");
    set_al(45);
    set_level(15);
    set_hp(200+random(20));
    set_wc(22);
    set_ac(10);
    set_gender("female");
    set_short(""+BLU+"Yvette"+NORM+"");
    set_long(
      "Yvette is a beautiful foreign exchange student the Bundy's are\n"+
      "hosting in order to collect the $500 per month stipend.  Kelly\n"+
     "doesn't like her because she stole all her boyfriends, but Bud\n"+
     "loves her because she doesn't mind Bud watching her undress.\n"+
     "The Bundy's have this poor thing living in the garage!\n");
  gold=clone_object("obj/money");
  gold->set_money(800+random(400));
  move_object(gold,this_object());
}

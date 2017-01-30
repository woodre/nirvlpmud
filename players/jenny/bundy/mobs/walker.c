inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
   ::reset(arg);
set_move_at_reset();
    if (arg) return;
    set_name("mall walker");
    set_alt_name("walker");
    set_alias("lady");
    set_race("human");
    set_al(12+random(8));
    set_level(12);
    set_hp(170+random(20));
    set_wc(17);
    set_ac(7);
    set_gender("female");
    set_short("A mall walker");
    set_long(
      "This is a mall walker.  An old lady who walks around the\n"+
      "mall for exercise.  She is wearing a ridiculous looking green\n"+
     "jumpsuit.\n");
  gold=clone_object("obj/money");
  gold->set_money(550+random(100));
  move_object(gold,this_object());
}

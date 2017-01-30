inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("jefferson d'arcy");
    set_alt_name("jefferson");
    set_alias("d'arcy");
    set_al(120);
    set_level(20);
    set_hp(510);
    set_wc(29);
    set_race("human");
    set_gender("male");
    set_short(""+CYN+"Jefferson D'Arcy"+NORM+"");
    set_long(
      "Jefferson is Marcy's attractive husband.  He is tall, well built, and\n"+
      "has nice hair.  Jefferson has never had a real job in his life, but his\n"+
     "looks get him by.  He likes to get his nails done, and go to the\n"+
     "nudie bar with Al.\n");
     
MOCO("/players/jenny/bundy/items/jeans.c"),this_object());
init_command("wear jeans");
set_ac(17);
   set_ac_bonus(1);
set_chat_chance(15);
     load_chat(""+HIB+"Jefferson makes a face at Marcy while she isn't looking"+NORM+"\n");
  gold=clone_object("obj/money");
  gold->set_money(2500+random(1500));
  move_object(gold,this_object());
}

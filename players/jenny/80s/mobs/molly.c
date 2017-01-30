inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "molly ringwald" ||  str == "molly" || str == "ringwald" || str == "Molly Ringwald"; } 
reset(arg)
{
   ::reset(arg);
    if (arg) return;
set_name("Molly Ringwald");
    set_race("human");
set_gender("female");
    set_al(75+random(20));
    set_level(12);
    set_hp(170+random(20));
    set_wc(16);
MOCO("/players/jenny/80s/items/swatch.c"),this_object());
init_command("wear swatch");
    set_ac(9+random(2));
   set_ac_bonus(1);
    set_short(BOLD+HIM+"Molly Ringwald"+NORM);
    set_long(
      "Molly Ringwald is a redheaded actress who was prominent in\n"+
      "Several 80's teen movies.  She had staring roles in 'The Breakfast\n"+
     "Club', 'Pretty in Pink', and 'Sixteen Candles'.  She may not have\n"+
     "been in every movie during the 80's, but it seemed that way.\n");
  gold=clone_object("obj/money");
  gold->set_money(300+random(100));
  move_object(gold,this_object());
}

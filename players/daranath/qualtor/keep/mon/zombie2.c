inherit "/obj/monster";

#include "/players/saber/closed/esc.h"
#include <ansi.h>

reset(arg) {
  object gold;
   ::reset(arg);
   if (!arg) {

set_name("Zombie Stablehand");
set_short("Zombie of a former Stablehand");
set_alias("zombie");
set_alt_name("stablehand");
set_race("undead");
set_gender("creature");
set_long("The body of a former stablehand to the king, something happened\n"+
         "and formed a zombie.\n");
set_level(8);
set_ac(7);
set_wc(9 + random(6));
set_hp(130 + random(50));
set_al(-1000);
set_aggressive(0);

gold = clone_object("obj/money");
gold->set_money(random(150)+100);
move_object(gold,this_object());
   }
  }


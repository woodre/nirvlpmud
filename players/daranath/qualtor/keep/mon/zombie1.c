inherit "/obj/monster";

#include "/players/saber/closed/esc.h"
#include <ansi.h>

reset(arg) {
  object gold;
   ::reset(arg);
   if (!arg) {

set_name("Zombie Servant");
set_short("Zombie of a former Servant");
set_alias("zombie");
set_alt_name("servant");
set_race("undead");
set_gender("creature");
set_long("The body of a former servant to the king, something happened\n"+
         "and formed a zombie.\n");
set_level(10);
set_ac(8);
set_wc(12 + random(10));
set_hp(150 + random(50));
set_al(-1000);
set_aggressive(0);

gold = clone_object("obj/money");
gold->set_money(random(300)+300);
move_object(gold,this_object());
   }
  }


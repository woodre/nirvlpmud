inherit "/obj/monster";

#include "/players/saber/closed/esc.h"
#include <ansi.h>

reset(arg) {
  object gold;
   ::reset(arg);
   if (!arg) {

set_name("Hungry Ghoul");
set_short("A ghoul is haunting the area");
set_alias("ghoul");
set_alt_name("hungry ghoul");
set_race("undead");
set_gender("creature");
set_long("The body of a former servant to the king, something happened\n"+
         "and formed a zombie.\n");
set_level(13);
set_ac(10);
set_wc(14 + random(10));
set_hp(200 + random(50));
set_al(-1000);
set_aggressive(1);

gold = clone_object("obj/money");
gold->set_money(random(380)+500);
move_object(gold,this_object());
   }
  }


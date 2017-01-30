inherit "/obj/monster";

#include "/players/saber/closed/esc.h"
#include <ansi.h>

reset(arg) {
  object gold;
   ::reset(arg);
   if (!arg) {

     set_name("ghost");
     set_short("Ghostly form of a Qual'tor Guardsman");
     set_alias("guard");
     set_alt_name("ghost guard");
     set_race("undead");
     set_gender("creature");
     set_long("Another of Qual'tors Guardsmen killed in the severe fighting\n"+
              "during the cities fall, this guard's duty was to keep the\n"+
              "prisoners of the king secure.\n");
     set_level(20);
     set_ac(17);
     set_wc(36 + random(4));
     set_hp(500 + random(200));
     set_al(-1000);
     set_aggressive(0);

     gold = clone_object("obj/money");
     gold->set_money(random(2000)+3500);
     move_object(gold,this_object());
   }
  }


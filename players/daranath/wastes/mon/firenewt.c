#include <ansi.h>
#define ROOT "/players/daranath/wastes/"

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

set_name("Firenewt");
set_alias("lavamon");
set_alt_name("firenewt");
set_race("newt");
set_gender("creature");

set_short(HIR+"Fire"+BLK+BOLD+"newt"+NORM);
set_long("Very small and usually found all about the Gundar Lava Pits, the Fire\n"+
         "newt is known to swarm over its opponent. The bite of the newt gives\n"+
         "a sharp burning sensation, thus giving the creature its name.\n");

set_level(8);
set_ac(7);
set_wc(10 + random(4));
set_hp(100 + random(20));
set_al(-500);
set_aggressive(0);

   }
}

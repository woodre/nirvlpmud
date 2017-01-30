#include "/players/languilen/closed/ansi.h"
#define PAPER_D "/players/languilen/areas/city/objs/np_d.c"
inherit "obj/monster.c";

reset(arg)  {
   ::reset(arg);
   if(arg) return;

   set_name("dumee");
   set_alias("dumie");
   set_alt_name("dummie");
   set_race("human");
   set_short("A Dummy");
   set_long(
"   This is just a stupid dummy made to test things out on.\n");

   set_level( 5 );
   set_hp( 50 );
   set_al( 10 );
   set_wc( 6 );
   set_ac( 6 );
   set_aggressive(0);
   set_dead_ob(this_object());
}

monster_died() {

   PAPER_D->score_kill("4-f");

   return 0;
}


#include "/players/francesco/univ/ansi.h"
inherit "obj/monster.c";
object gold;
reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("johanna");
set_alias("receptionist");
set_race("human");
set_short("Johanna, the receptionist");
set_long(  
  "A very nice girl with blond curled hair and prosperous figure, about 5'9\"\n"+
  "and 110 pounds.  She is working as an in-campus employed at the mere salary\n"+
  "of $1 per hour.  You wonder why she accepted this job.  She might be interested\n"+
  "in a more money-giving job by using her beauty.  Rumors say that she is very good\n"+
  "in sexual related activities.\n");

set_level(10);
set_hp(150);
set_al(0);
set_wc(14);
set_ac(8);
set_aggressive(0);



gold = clone_object("obj/money");
gold->set_money(430);
move_object(gold,this_object());
}


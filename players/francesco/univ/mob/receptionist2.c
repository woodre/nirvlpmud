#include "/players/francesco/univ/ansi.h"
inherit "obj/monster.c";
object gold;
reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("whitefawn");
set_alias("receptionist");
set_race("human");
set_short("Whitefawn, the receptionist");
set_long(  
  "A very nice girl with black straight hair,  blue eyes and medium frame figure.\n"+
  "Her name clearly quotes that her parents are Native American.  She is working as\n"+
  "an in-campus employed at the mere salary of $1 per hour.  You wonder why she\n"+
  "accepted this job.  She is very shy and wont ever accept any job that might be\n"+
  "involved with sexual activities,  regardless the money she could get from it.\n");

set_level(10);
set_hp(150);
set_al(0);
set_wc(14);
set_ac(8);
set_aggressive(0);



gold = clone_object("obj/money");
gold->set_money(435);
move_object(gold,this_object());
}


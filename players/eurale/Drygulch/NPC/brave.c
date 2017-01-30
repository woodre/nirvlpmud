/*  an indian brave  */

inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("brave");
set_race("human");
set_short("an Indian brave");
set_long(
	"  This is one of the many Indian braves of the camp.  He has seen \n"+
	"many war parties and counted many coup. \n");
set_level(14);
set_hp(210);
set_al(0);
set_wc(18);
set_ac(11);
set_aggressive(0);

set_chat_chance(5);
  load_chat("The brave glares at you with ebony eyes. \n");
  load_chat("The braves tenses for whatever comes next. \n");

gold = clone_object("obj/money");
gold->set_money(random(60)+800);
move_object(gold,this_object());
}

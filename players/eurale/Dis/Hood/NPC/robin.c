#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("robin");
set_alias("robin hood");
set_alt_name("hood");
set_race("human");
set_short(HIG+"Robin Hood"+NORM);
set_long(
	"  Robin Hood, otherwise known as Robin of Locksley, is the leader\n"+
	"of a band of outlaws that roam the King's forest.  He is always\n"+
	"dressed in forest green from head to foot.  His charming smile\n"+
	"and eloquent ways make him a favorite of locals here.  Never one\n"+
	"to miss the opportunity to take a little from Prince John and\n"+
	"return it to the people, he is daring as well as dangerous.\n");

  set_hp(650);
  set_level(20);
  set_al(0);
  set_wc(30);
  set_ac(15);
  set_heal(5,4);
  set_aggressive(0);

set_chat_chance(15);
  load_chat("Robin smiles as he searches for valuables...\n");
  load_chat("Robin bows to you.....\n");
  load_chat("Robin says: Tell John and the Sheriff hello!\n");
set_a_chat_chance(15);
  load_a_chat("Robin slaps you hard!!!!! \n");
   load_a_chat("Robin deftly sidesteps your attack....\n");
   load_a_chat("Robin steals something valuable...\n");

gold = clone_object("obj/money");
gold->set_money(4750+random(500));
move_object(gold,this_object());
}

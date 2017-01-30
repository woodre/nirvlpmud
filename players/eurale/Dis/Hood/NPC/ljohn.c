#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("john");
set_alias("little john");
set_race("human");
set_short("Little John");
set_long(
	"  This towering man is Robin Hood's right hand.  He keeps the\n"+
	"peace among the outlaws.  He's honest and loyal to a fault.  His\n"+
	"forest green outfit let's him blend into the scenery.\n");

  set_hp(475);
  set_level(19);
  set_al(0);
  set_wc(28);
  set_ac(16);
  set_aggressive(0);

set_chat_chance(15);
  load_chat("Little John crosses his arms over his huge chest..\n");
set_a_chat_chance(15);
load_a_chat("\n\nLittle John CLUBS you with a huge hand...\n\n");
load_a_chat("Little John smiles as he works you over....\n");

gold = clone_object("obj/money");
gold->set_money(2000);
move_object(gold,this_object());
}

/*  Nellie Cashman  */

#include "defs.h"
inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("nellie");
set_race("human");
set_short("Nellie Cashman");
set_alias("cashman");
set_long(
	"  Nellie Cashman (c.1849-1925)  'The Angel of Tombstone,' anti- \n"+
	"violence peacemaker who ran a boarding house, raised orphans, \n"+
	"campaigned against public hangings and once saved a man from \n"+
	"an angry mob. \n");
set_level(14);
set_hp(210);
set_al(300);
set_wc(18);
set_aggressive(0);

move_object(clone_object("players/eurale/Hotel/OBJ/necklace"),TO);
init_command("wear necklace");
set_ac(12);

set_chat_chance(5);
  load_chat("Nellie closes her eyes and appears to be praying. \n");
  load_chat("Nellie whispers:  Hangings are so barbaric. \n");
  load_chat("Nellie implores:  Won't you help me put a stop to this? \n");

gold = clone_object("obj/money");
gold->set_money(random(50)+650);
move_object(gold,this_object());
}

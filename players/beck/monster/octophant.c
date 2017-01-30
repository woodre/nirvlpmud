inherit "obj/monster";
#include "/players/beck/rangers/defs.h"

reset(arg)
{
object gold;
  ::reset(arg);
  if(arg) return;
set_name("Octophantom");
set_alias("octophantom");
set_short("The Octophantom");
set_long("The Octophantom is one of Lord Zed's evil creatures.\n"+
"It's a cross between an octopus and an elephant.\n");
set_level(20);
set_hp(500);
set_wc(30);
set_ac(17);
set_chat_chance(2);
set_chance(15);
set_spell_dam(10);
set_spell_mess2("Octophantom grabs you and throws you to the ground.\n");
set_al(-800);
set_aggressive(0);
load_chat("The Octophantom cries out: I am so good looking!\n");
load_chat("The Octophantom says: I can't believe how incredibly handsome I am!\n");
gold=clone_object("obj/money");
gold->set_money(random(4000) + 500);
move_object(gold, this_object());
MASTER->add_active_ranger("Octophantom");
}

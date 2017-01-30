inherit "obj/monster";
#include "/players/beck/rangers/defs.h"

reset(arg)
{
object gold, weapon;
  ::reset(arg);
  if(arg) return;
set_name("Stagbeetle");
set_alias("stagbeetle");
set_short("The Stagbeetle");
set_long("The Stagbeetle is on of Lord Zed's evil creatures.\n"+
"It is one of the ugliest things you have ever seen.\n");
set_level(20);
set_hp(525);
set_wc(35);
set_ac(15);
set_aggressive(0);
set_al(-900);
set_chance(15);
set_spell_dam(10);
set_spell_mess2("The stagbeetle catches you in its pincers, and crushes your ribs.\n");
set_chat_chance(2);
set_a_chat_chance(15);
load_chat("The Stagbeetle asks: What's the matter?  Something 'bugging you?\n");
load_chat("The Stagbeetle exclaims:  I'm the unbeatable beetle!\n");
load_a_chat("The Stagbeetle says: My pincers will make power mush out of you!\n");
gold=clone_object("obj/money");
gold->set_money(random(3500) + 1000);
move_object(gold, this_object());
MASTER->add_active_ranger("Stagbeetle");
}

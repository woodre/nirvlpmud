#include "/players/khrell/define.h"
#include <ansi.h>

inherit "/players/vertebraker/closed/std/monster.c";

reset(arg) {
object gold;
  ::reset(arg);
  if(arg) return;
  set_name("monster");
  set_alt_name("monster");
  set_alias("monster");
  set_short("monster");
  set_long(
"This is a monster.\n"+
"He's really mean.\n");
  set_gender("male");
  set_race("monster");
  set_level(1);
  set_wc(1);
  set_ac(1);
  set_hp(200);
  set_al(1);
set_aggressive(0);
  add_money(100);  
move_object(clone_object("/players/khrell/EX/wep.c"));
move_object(clone_object("/players/khrell/EX/armor.c"));
init_command("wear armor");
init_command("wield sword");

set_chat_chance(10);
load_chat("The monster does something for the room to see.\n");

set_a_chat_chance(10);
load_a_chat("This is an emote while in battle to the room.\n");
  set_chance(10);
set_spell_dam(100);
set_spell_mess1( 
"The monster does something for the attacker to see while it's in battle.\n");

set_spell_mess2(
"The monster does something for the room to see while it's in battle.\n");

gold = clone_object("obj/money");
gold->set_money(100);
move_object(gold,this_object());
}

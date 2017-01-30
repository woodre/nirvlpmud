#include "/players/puppy/define.h"

inherit "/obj/monster.c";

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
  set_wc(random(5)+10);
  set_ac(random(1)+10);
  set_hp(100+random(100));
  set_al(1);
  set_aggressive(0);
  set_heal(1,1);
  add_money(1000+random(1000));
  
  
move_object(clone_object("/players/puppy/EX/wep.c"));
move_object(clone_object("/players/puppy/EX/armor.c"));
init_command("wear armor");
init_command("wield sword");

set_chat_chance(10);
load_chat("The monster does something for the room to see.\n");
load_chat("The monster does something for the room to see.\n");
load_chat("The monster does something for the room to see.\n");
load_a_chat("This is an emote while in battle to the room.\n");
  set_chance(5);
  
set_spell_dam(100);
set_spell_mess1( 
"The monster does something for the attacker to see while it's in battle.\n");

set_spell_mess2(
"The monster does something for the room to see while it's in battle.\n");
)

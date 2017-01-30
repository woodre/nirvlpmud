inherit "obj/monster.c";
#include <ansi.h>

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("jumak");
  set_race("creature");
  set_short("A "+HIB+"Jumak"+NORM);
  set_long(
  "  A revolting creature that devours any corpse it may find.\n"+
  "It is the perfect example of a scavenger.  It's long snout\n"+
  "has several sets of razor sharp teeth, perfect for gnawing\n"+
  "through bone.  A disgusting smell eminates from the jumak \n"+
  "making anyone near it gag in disgust.\n");

  set_level(18);
  set_hp(400);
  set_al(0);
  set_ac(15);
  set_wc(26);
  add_money(random(2000)+1500);
  set_aggressive(0);
  set_heart_beat(1);
  set_chance(10);
  set_spell_dam(20);  
  set_spell_mess1(
    "\n      The jumak spits bones from its mouth impaling it's foe.\n");
  set_spell_mess2(
    "\n      The jumak impales you with the bones it spits from its long snout.\n");  

}

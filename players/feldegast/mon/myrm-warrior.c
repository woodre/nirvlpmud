#include "/players/feldegast/defines.h"
#define HIVE_MIND "/players/feldegast/realm/JalHab/hive_mind.c"

inherit MONSTER;

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("myrmidar");
  set_alias("t'lek");
  set_short(HIR+"T'lek"+BLK+" Myrmidar"+NORM);
  set_long(
"The Myrmidar stands on two hind legs, and appears generally human\n\
in shape.  However, sharp spikes and horns protrude from the hard,\n\
overlapping chitinous plates that cover its body.  Six faceted eyes\n\
adorn either side of its hideous face, which ends in a pair of deadly\n\
sharp mandibles.\n"
  );
  set_level(19);
  set_wc(26+random(4));
  set_ac(14+random(4));
  set_hp(450+random(50));
  load_chat(short()+" clicks threateningly at you.\n");
  load_chat(short()+" nudges you forcefully.\n");
  set_chat_chance(4);
  set_dead_ob(this_object());
  HIVE_MIND->register(this_object());
}

/* This averages around 4000 coins. */
void monster_died(object ob)
{
  object corpse;
  corpse=present("corpse",environment());
  move_object(clone_object(HEAL_PATH+"myrm-blood"),corpse); /* 1600 */
  move_object(clone_object(HEAL_PATH+"myrm-heart"),corpse); /* 750 */
  if(!random(2)) move_object(clone_object(HEAL_PATH+"myrm-blood"),corpse); /* 800 */
  if(!random(2)) move_object(clone_object(WEP_PATH+"myrm-spike"),corpse); /* 250 */
  if(!random(3)) move_object(clone_object(ARM_PATH+"myrm-plate"),corpse); /* 250 */
  if(!random(2)) move_object(clone_object(ARM_PATH+"myrm-shield"),corpse); /* 250 */
  write("You skin the myrmidar and make what you can from its carcass.\n");
}

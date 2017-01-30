#include "/players/feldegast/defines.h"

inherit MONSTER;

void reset(int arg)
{
  ::reset(arg);
  if(arg)return;
  set_name("myrmidar");
  set_alias("q'lon");
  set_short(HIY+"Q'lon"+BLK+" Myrmidar"+NORM);
  set_long(
"The Myrmidar stands on two hind legs, and appears generally humanoid\n\
in shape.  However, sharp spikes and horns protrude from the hard,\n\
overlapping chitinous plates that cover its body.  Six faceted eyes\n\
adorn either side of its hideous face, which ends in a pair of deadly\n\
sharp mandibles.  This Myrmidar is slightly smaller and has fewer spikes\n\
adorning its body.\n"
  );
  set_level(17);
  set_wc(24);
  set_ac(14);
  set_hp(350); /* Changed from 425 to 350 to use the new monster guide. 1/10/01 */
  load_chat(short()+" walks around you.\n");
  load_chat(short()+" digs in the earth with its sharp claws.\n");
  set_chat_chance(5);
  set_dead_ob(this_object());
}

/* This averages around 2.1k worth of loot.  */
void monster_died(object ob)
{
  object corpse;
  corpse=present("corpse",environment());
  if(!random(4)) move_object(clone_object(HEAL_PATH+"myrm-blood"),corpse); /* 400 */
  if(!random(2)) move_object(clone_object(HEAL_PATH+"myrm-heart"),corpse); /* 400 */
  if(!random(2)) move_object(clone_object(WEP_PATH+"myrm-spike"),corpse); /* 250 */
  if(!random(2)) move_object(clone_object(WEP_PATH+"myrm-spike"),corpse); /* 250 */
  if(!random(3)) move_object(clone_object(ARM_PATH+"myrm-plate"),corpse); /* 250 */
  if(!random(2)) move_object(clone_object(ARM_PATH+"myrm-shield"),corpse); /* 250 */
  if(!random(4)) move_object(clone_object(HEAL_PATH+"myrm-blood"),corpse); /* 400 */
  write("You skin the myrmidar and make what you can from its carcass.\n");
}

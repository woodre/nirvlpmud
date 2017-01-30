#include "/players/feldegast/defines.h"
#define HIVE_MIND "/players/feldegast/realm/JalHab/hive_mind.c"

inherit MONSTER;

void call_for_help();

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("myrmidar");
  set_alias("t'qik");
  set_short(HIB+"T'Qik"+BLK+" Myrmidar"+NORM);
  set_long(
"The Myrmidar stands on two hind legs, and appears generally human\n\
in shape.  However, sharp spikes and horns protrude from the hard,\n\
overlapping chitinous plates that cover its body.  Six faceted eyes\n\
adorn either side of its hideous face, which ends in a pair of deadly\n\
sharp mandibles.  This myrmidar is much taller and darker colored than\n\
the others.  Also, it might just be your imagination, but you believe\n\
you see some sign of intelligence in its alien eyes.\n"
  );
  set_level(20);
  set_wc(28+random(5)); /* + 0.5 */
  set_ac(17+random(4)); /* +2 */
  set_hp(450+random(80)); /* -10 */

  load_spell(25,30,0,
    short()+" stabs you with its spiked fists.\n",
    short()+" stabs #ATT# with its spiked fists.\n"
  );
  load_spell(30,25,0,
    short()+" kicks you with its clawed feet.\n",
    short()+" kicks #ATT# with its clawed feet.\n"
  );
  set_dead_ob(this_object());
  HIVE_MIND->register(this_object());
}

void heart_beat()
{
  ::heart_beat();
  if(attacker_ob && !random(6)) call_for_help();
}

/* Averages around 5000 coins worth of loot. */
void monster_died(object ob)
{
  object corpse;
  corpse=present("corpse",environment());
  move_object(clone_object(HEAL_PATH+"myrm-heart"),corpse);
  if(!random(2)) move_object(clone_object(HEAL_PATH+"myrm-blood"),corpse);
  if(!random(2)) move_object(clone_object(HEAL_PATH+"myrm-blood"),corpse);
  if(!random(2)) move_object(clone_object(HEAL_PATH+"myrm-blood"),corpse);
  if(!random(2)) move_object(clone_object(HEAL_PATH+"myrm-blood"),corpse);
  if(!random(2)) move_object(clone_object(WEP_PATH+"myrm-spike"),corpse);
  if(!random(2)) move_object(clone_object(WEP_PATH+"myrm-spike"),corpse);
  if(!random(2)) move_object(clone_object(ARM_PATH+"myrm-plate"),corpse);
  if(!random(2)) move_object(clone_object(ARM_PATH+"myrm-shield"),corpse);
  if(!random(2)) move_object(clone_object(ARM_PATH+"myrm-shield"),corpse);
  write("You skin the myrmidar and make what you can from its carcass.\n");
}

void call_for_help()
{
  object ob;
  ob=first_inventory(environment());
  while(ob)
  {
    if(!((int)ob->query_attack()) && (int)ob->id("myrmidar") && ob!=this_object())
    {
      tell_room(environment(),(string)ob->short()+" comes to "+short()+"'s aid.\n");
      ob->attack_object(attacker_ob);
    }
    ob=next_inventory(ob);
  }
}


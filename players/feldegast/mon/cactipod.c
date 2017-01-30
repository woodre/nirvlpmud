#include "/players/feldegast/defines.h"

inherit "obj/monster";

int disguised;

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("cactipod");
  set_alias("cactus");
  set_short(HIG+"Cactus"+NORM);
  set_long("An ordinary looking green cactus with sharp, prickly thorns.\n");
  set_gender(0);
  set_race("plant");
  set_level(14);
  set_wc(16+random(4));
  set_ac(11);
  set_hp(180+random(60));
  set_al(0);
  set_dead_ob(this_object());
  disguised=1;
}

void uncamo()
{
  set_short(GRN+"Cactipod"+NORM);
  set_long(
"  The cactopod appears to be a normal cactus, except that it uses its\n\
needles and varies its internal equilibrium to roll across the sand.\n\
Cactopods are a species of carnivorous plant that have thrived in the\n\
Jal-Hab desert, feeding on snakes, desert rats, and larger prey.\n");
  disguised=0;
}

void heart_beat()
{
  ::heart_beat();
  if(disguised && attacker_ob) uncamo();
}

void monster_died(object it)
{
  int i;
  if(!environment()) return;
  if(!random(2)) {
    tell_room(environment(),
  "You brush the needles off of the cactipod and prepare it for eating.\n");
    move_object(clone_object(HEAL_PATH+"cactus"),environment(this_object()));
  }
  else {
      tell_room(environment(),
GRN+"The cactipod proves its resiliency as its remaining husks stir to life.\n"+NORM);
    for(i=0; i < random(3)+1; i++)
      move_object(clone_object(MON_PATH+"cactipod.c"),environment(this_object()));
  }
}

void init()
{
  if(!random(2) && TP->is_player())
    call_out("ambush",5+random(20),this_player());
}

void ambush(object target)
{
  if(target && !attacker_ob && present(target,environment())) {
    tell_object(target,"The cactus suddenly stirs to life and starts attacking you!\n");
    attack_object(target);
  }
  uncamo();
}

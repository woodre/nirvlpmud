#include <ansi.h>
inherit "/obj/monster";
#define IT capitalize(obj->query_name())

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Tatzlwurm");
  set_alias("tatzlwurm");
  set_short("A Tatzlwurm");
  set_long(
  "The Tatzlwurm is a small but not very intelligent dragon.  Tatzlwurm's\n"+
  "are known for their fierceness and cunning in combat.  The dragon's body\n"+
  "is long and wingless, and the Tatzlwurm can scamper quickly over the\n"+
  "rough mountain terrain.  The Tatzlwurm has three sharp talons on each\n"+
  "foot that it uses to tear at its enemy.\n");
  set_race("dragon");
  set_level(20+random(5));
  set_hp(525+random(275));
  set_wc(30+random(20));
  set_ac(15+random(15));
  set_al(-(500+random(500)));
  set_aggressive(0);
  set_dead_ob(this_object());
  call_out("this_chat", 8);
  message_hit = ({
  "gouges", " with its sharp talons",
  "rips the flesh from", "",
  "springs forwards and sinks its sharp teeth into", "",
  "tears a chunk of flesh from", "",
  "scratches", " with its talons",
  "cuts", "deeply",
  "pokes", " with a sharp claw",
  });
}

id(str) {
  return str == "tatzlwurm" || str == "dragon" || str == "Tatzlwurm" ||
  str == "blacksmith_killer";
}

this_chat() {
  int i;

  if(!environment(this_object())) {
       call_out("this_chat", 10);
       return 1;
  }

  if(this_object()->query_attack()) {
       call_out("this_chat", 10);
       return 1;
  }

  if(present("syrian_blacksmith", environment(this_object())))
       i = random(6);
  else
       i = 6+random(5);

  if(i == 0) tell_room(environment(this_object()),
  "The Tatzlwurm snarls and takes a swipe at the blacksmith.\n");
  if(i == 1) tell_room(environment(this_object()),
  "Tatzlwurm scampers over some rocks and rakes Blacksmith with its talons!\n"+
  "The Syrian Blacksmith cries out in pain!\n");
  if(i == 2) tell_room(environment(this_object()),
  "The Tatzlwurm hisses angrily as it creeps towards the blacksmith.\n");
  if(i == 3) tell_room(environment(this_object()),
  "Tatzlwurm snaps its fierce jaws at the Blacksmith.\n");
  if(i == 4) tell_room(environment(this_object()),
  "The Tatzlwurm leaps at the Blacksmith!\n"+
  "The Blacksmith dives and narrowly avoids the agile dragon.\n");
  if(i == 5) tell_room(environment(this_object()),
  "Tatzlwurm crouches and gets ready to leap at the Blacksmith.\n");

  if(i == 6) tell_room(environment(this_object()),
  "Tatzlwurm looks at you and snarls.\n");
  if(i == 7) tell_room(environment(this_object()),
  "The Tatzlwurm sneers at you.\n");
  if(i == 8) tell_room(environment(this_object()),
  "The Tatzlwurm scampers across the rocky ground.\n");
  if(i == 9) tell_room(environment(this_object()),
  "The Tatzlwurm cuts the air with its razor-sharp talons.\n");
  if(i == 10) tell_room(environment(this_object()),
  "Tatzlwurm looks around for something to kill.\n");

  call_out("this_chat", 6+random(15));
  return 1;
}

/*
 * As usual, I don't like players being able to stop a fight.
 */
stop_fight() {
  if(this_player()->query_level() > 20) {
    ::stop_fight();
    return 1;
  }
  return;
}

/*
 * None of this heal_self crap
 */
heal_self(i) {
  if(i <= 0) {
    return;
  }
  else {
    ::heal_self(i);
  }
  return;
}

/*
 * No modifying stats either!
 */
set_ac(x) {
  if(this_player() != this_object()) { return; }
  ::set_ac(x);
  return 1;
}

set_wc(x) {
  if(this_player() != this_object()) { return; }
  ::set_wc(x);
}

set_heal_rate(x,y) {
  if(this_player() != this_object()) { return; }
  ::set_heal_rate(x,y);
}

monster_died() {
  object bs;

  if(this_player()->query_real_name()) {
    bs = present("syrian_blacksmith", environment(this_object()));
    if(bs) bs->do_savior(this_player());
    write_file("/players/pavlik/ilstkarn/LOG",
    capitalize(this_player()->query_real_name())+" killed the Tatzlwurm. ["+ctime()+"]\n");
  }
  return 0;
}


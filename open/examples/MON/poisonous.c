/*
An example of a poisonous monster using a heart_beat function.
					-Feldegast
*/

#include "/players/feldegast/defines.h"

inherit "/obj/monster";

int venom;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Giant spider");
  set_alt_name("giant spider");
  set_alias("giant");
  set_short("Giant spider");
  set_long(
    "This spider stands as tall as a horse, with giant, spear-like\n"+
    "legs and mandibles like sharp knives.  It's alien, red eyes\n"+
    "stare vacantly at you.  Its venom could drop a grown man in a\n"+
    "matter of minutes.\n"
  );
  set_al(-200);
  set_gender("male");
  set_race("spider");
  set_level(20);
  set_wc(30);
  set_ac(17);
  set_hp(450);

  set_dead_ob(this_object()); /* Specify the object that the monster_died function is in. */

  set_chat_chance(5);
  load_chat("The spider circles you on its lithe and flexible legs.\n");
  load_chat("A giant spider nudges you experimentally.\n");
  set_a_chat_chance(5);
  load_a_chat("Giant spider wounds you with one of its spear-like legs.\n");
  load_a_chat("Giant spider slashes you with its spear-like legs.\n");
  load_a_chat("Giant spider flexes its mandibles hungrily.\n");
  set_chance(15);
  set_spell_mess1(
"The Giant spider slashes its foe mercilessly with its claws.\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"The Giant spider catches you in its claws and slashes you mercilessly.\n"
  ); /* 1ST PERSON */
  set_spell_dam(25);
}

/*
A heart_beat function is called approximately every 2-3 seconds and is
the basis for all combat.  You can make a heart_beat function to have
your monsters do special attacks in the middle of combat.
*/
heart_beat() {
  ::heart_beat(); /* This calls the heart_beat in monster.c to handle attacks. */
  if(attacker_ob) {
    if(attacker_ob->query_attrib("luc")+attacker_ob->query_attrib("sta") <
    random(50) && !venom) {
      move_object(clone_object("/players/feldegast/obj/venom"),attacker_ob);
      say("A Giant Spider grabs "+attacker_ob->query_name()+" swiftly with its claws and bites "+
      attacker_ob->query_objective()+" deeply\n"+
      "with its mandibles, injecting its "+GRN+"venom"+NORM+" into "+attacker_ob->query_possessive()+
      " body.\n");
      venom=1; /* Only one shot of poison. */
    }
  }
}

monster_died() {
  object silk;
  object corpse;
  corpse=present("corpse",environment());
  if(corpse) {
    silk=clone_object("/players/feldegast/obj/spidersilk");
    move_object(silk,this_object());
    say("\nThe giant spider rises high up on its legs, ready to make a final,\n"+
        "desperate strike, when it shudders and collapses to the ground,\n"+
        "tangling itself in its own webbing in the process.\n");
  }
}

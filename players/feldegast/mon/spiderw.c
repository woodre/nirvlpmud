/*
File: spiderw.c
Author: Feldegast
Date: 5-7-98
Revised: 2-24-02
Description:
  A giant spider with a web attack.  Found in the
spider cave in Caladon.
*/

#include "/players/feldegast/defines.h"

inherit "/obj/monster";

int web;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("webspinner spider");
  set_alt_name("giant spider");
  set_alias("webspinner");
  set_short(YEL+"Webspinner"+BOLD+BLK+" spider"+NORM);
  set_long(
    "This spider stands as tall as a horse, with giant, spear-like\n"+
    "legs and mandibles like sharp knives.  It's alien, red eyes\n"+
    "stare vacantly at you.  Its venom could drop a grown man in a\n"+
    "matter of minutes.\n"
  );
  set_al(0);
  set_gender("male");
  set_race("spider");
  set_level(19);
  set_wc(28);
  set_ac(15);
  set_hp(450);
  set_al(0);
  set_dead_ob(this_object());
  set_aggressive(1);
  set_chat_chance(5);
  load_chat("The spider circles you on its lithe and flexible legs.\n");
  load_chat("A giant spider nudges you experimentally.\n");
  set_a_chat_chance(5);
  load_a_chat("The spider wounds you with one of its spear-like legs.\n");
  load_a_chat("The spider slashes you with its spear-like legs.\n");
  load_a_chat("The spider flexes its mandibles hungrily.\n");
  set_chance(15);
  set_spell_mess1(
    "The giant spider slashes its foe mercilessly with its claws.\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
    "The giant spider catches you in its claws and slashes you mercilessly.\n"
  ); /* 1ST PERSON */
  set_spell_dam(25);
}

heart_beat() {
  ::heart_beat();
  if(attacker_ob) {
    if(attacker_ob->query_attrib("luc")+attacker_ob->query_attrib("sta") < random(45) &&
       !web && !present("web_token", attacker_ob)) 
    {
      move_object(clone_object("/players/feldegast/obj/web_token.c"),attacker_ob);
      say(YEL+"\nThe webspinner spider grasps "+attacker_ob->query_name()+" with its claws.\n"+
          "A stream of webs shoot from its spinnerets, binding "+attacker_ob->query_name()+" in webs!\n\n"+NORM);
      web=0;
    }
  }
}

monster_died() {
  object silk;
  silk=clone_object("/players/feldegast/obj/spidersilk");
  move_object(silk,this_object());
  say("\nThe giant spider rises high up on its legs, ready to make a final,\n"+
      "desperate strike, when it shudders and collapses to the ground,\n"+
      "tangling itself in its own webbing in the process.\n");
}

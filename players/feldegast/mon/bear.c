/*
File: bear.c
Author: Feldegast @ Nirvana
Date: 02-13-02
Description:
  A bear that resides in Caladon.
*/

inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("bear");
  set_alt_name("grizzly");
  set_alias("grizzly bear");
  set_short("Grizzly bear");
  set_long(
"This is a huge grizzly bear with thick brown fur and a ferocious\n\
expression on its face.  It has many scars and one of its ears is\n\
missing.  This beast is clearly an unusually mean and aggressive\n\
creature.\n"
  );
  set_gender("male");
  set_race("critter");
  set_level(17);
  set_wc(22+random(4));
  set_ac(12+random(4));
  set_hp(325+random(50));
  set_al(-50);
  set_dead_ob(this_object());
  set_chat_chance(5);
  load_chat("Grizzly bear bellows ferociously at you.\n");
  set_a_chat_chance(6);
  load_a_chat("The Grizzly bear rises up on its hind legs and swats at you with\n"+
              "its deadly sharp claws.\n");
  set_chance(8);
  set_spell_mess1(
"The Grizzly mauls its opponent with sharp claws and pointy teeth.\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"The Grizzly bear mauls you with its sharp claws and shiny teeth.\n"
  ); /* 1ST PERSON */
  set_spell_dam(10);
}
monster_died(ob) {
  object hide;
  hide=clone_object("/players/feldegast/equip/bear_hide.c");
  move_object(hide,ob);
}

#include "defs.h"

inherit "/obj/monster.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("berenor");
  set_alias("moonaxe");
  set_alt_name("brigand");
  set_short("Berenor Moonaxe");
  set_long(
    "Berenor Moonaxe is a fierce looking dwarven brigand with gaping\n"+
    "black teeth and a mangy red beard.  His left eye moves independant\n"+
    "of the right one and the right one doesn't look too sane either.\n"
  );
  set_gender("male");
  set_race("dwarf");
  set_level(15);
  set_hp(225);
  set_al(-250);
  set_chat_chance(4);
  load_chat("Berenor sings: Two wenches and a dwarf, sitting upon a wharf...\n");
  load_chat("Berenor sings: The left one kisses the right one,\n"+
            "\tthe dwarf kisses the lower one.\n");
  load_chat("Berenor sings: The left one says OH! The right one says NO!\n"+
            "\tThe dwarf says SO!\n");
  load_chat("Berenor sings: Oh!  No!  So!\n");
  load_chat("Berenor drinks some more ale.\n");
  load_chat("Berenor sings: SOMEthing someTHING SOME-THING!\n");
  set_a_chat_chance(25);
  load_a_chat("Berenor takes a sip of ale and then spits it in your face.\n");
  load_a_chat("Berenor backhands you across the face!\n");
  load_a_chat("Berenor takes a huge swipe at you with his axe.\n");
  load_a_chat("Berenor waves his axe about drunkenly.\n");
  load_a_chat("Berenor conks you over the head with his tankard.\n");
  move_object(clone_object(HEAL_PATH+"tankard.c"),this_object()); /* 300 coins */
  move_object(clone_object(WEP_PATH+"halfaxe.c"),this_object()); /* 600 coins */
  init_command("wield axe");
  add_money(random(50));
  set_wc(20);
  set_ac(12);
}


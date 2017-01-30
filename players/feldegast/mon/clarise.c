/*
Name: clarise.c
Author: Feldegast / Dave Sampson @ nirvana.mudservices.com
Date: 10/25/01
Description:
  A resident of the Tower of Ravens.
*/

#include "defs.h"

int harmed;
int hello;

inherit MONSTER;

void reset(int arg)
{
  object key;
  ::reset(arg);
  if(arg) return;
  set_name("clarise");
  set_alias("mage");
  set_short(HIY+"Clarise"+NORM);
  set_long(
"  Clarise is an apparently young woman with honey-colored hair\n"+
"and blue eyes.  She wears a low-cut summer dress with flowers\n"+
"on it.  She appears to be afraid.\n"
  );
  set_gender("female");
  set_race("human");
  set_al(-250);
  set_level(18);
  set_wc(26);
  set_ac(13);
  set_hp(400);
  set_ac_bonus(2);
  set_chat_chance(5);

  /* Corny. */
  load_chat("Clarise says: Oh MY, you look so STRONG!\n");
  load_chat("Clarise says: Would you PLEASE kill the evil woman at the top of this tower?\n");
  load_chat("Clarise bats her eyelashes at you.\n");
  load_chat("Clarise says: They kidnapped me and FORCED me to come here!  Please help!\n");
  load_a_chat("Clarise's hair whips around her head.\n");
  load_a_chat("Clarise's hands glow with power.\n");

  load_spell(25,10,0, /* 10% chance of 25 hit_player damage */
    "\nClarise strikes you with a powerful "+HIM+"energy bolt"+NORM+"!\n\n",
    "\nClarise strikes #ATT# with a powerful "+HIM+"energy bolt"+NORM+"!\n\n"
  );

  load_spell(15, 8, 2, /* 8% chance of 15 sp damage */
    "\nClarise kisses you deeply, sucking life energy from your body.\n\n",
    "\nClarise kisses #ATT# deeply, drawing energy.\n\n"
  );
  key = clone_object("/obj/treasure");
  key->set_id("clarisse_door");
  key->set_alias("key");
  key->set_short("A steel key");
  key->set_weight(1);
  key->set_value(5);
  key->set_long("It is an ordinary looking key made out of steel.\n");
  move_object(key, this_object());
}

void heart_beat()
{
  ::heart_beat();
  if(!harmed && attacker_ob)
  {
    harmed = 1;
    set_short(HIR+"Clarise"+NORM + " the Apprentice Sorceress");
    say("Clarise says: Idiot.  We could've been good together.\n");
    set_chat_chance(0);
  }
}

void init()
{
  ::init();
  if(!hello)
  {
    call_out("hello", 1);
    hello = 1;
  }
}

void hello()
{
  say("Clarise looks startled to see you at first, and then her expression\n"+
      "turns into a wide smile.\n");
}

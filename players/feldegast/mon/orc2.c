/*
File: orc2.c
Author: Feldegast
Date: 3/17/02
Description:
  An orc from the orc encampment in Caladon.
*/

#include "defs.h"

inherit MONSTER;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  switch(random(3))
  {
    case 0: move_object(clone_object(ARM_PATH+"shield.c"),this_object());
            init_command("wear shield"); /* 200 */
            break;
    case 1: move_object(clone_object(ARM_PATH+"helmet2.c"),this_object());
            init_command("wear helmet"); /* 125 */
            break; 
    /* 1/3 chance of nothing. */
  }
  move_object(clone_object(ARM_PATH+"leather.c"),this_object());
  init_command("wear armor"); /* 300 */
  move_object(clone_object(WEP_PATH+"spear.c"),this_object());
  init_command("wield spear"); /* Value = 600 */
  set_name("orcish hunter");
  set_alt_name("hunter");
  set_short("Orcish Hunter");
  set_long(
    "Orcs are hideous, humanoid creatures with thick, hairy hides, squat\n"+
    "bodies and teeth protruding from their mouths.  They are intelligent,\n"+
    "but only barely so, having a strong tribal system, and some basic\n"+
    "tool-working ability.  This particular orc is a hunter.  Orc hunters\n"+
    "are the warriors and scouts of their tribe, frequently raiding human\n"+
    "settlements, and on rare occasions organizing in large groups for war.\n"
  );
  set_gender("male");
  set_race("orc");
  set_level(17);
  set_wc(24);
  set_ac(11);
  set_ac_bonus(2); /* Armor */
  set_hp(350);
  set_al(-350);
  set_chat_chance(3);
  load_chat("The Orcish Hunter waves his spear at you threateningly.\n");
  load_chat("An orc passes gas.\n");
  load_chat("The Orcish Hunter leaps about in an agitated manner.\n");
  load_chat("The Orcish Hunter growls low.\n");
  add_money(random(2000));
}

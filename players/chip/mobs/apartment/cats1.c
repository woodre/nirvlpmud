/*
 *    File: /players/chip/mobs/apartment/cats1.c
 *    Function: NPC
 *    Author(s): Chip@Nirvana
 *    Copyright: Copyright (c) 2008 Chip
 *               All Rights Reserved
 *    Source: 5/31/08
 *    Notes:
 *
 *
 *    Change History:
 */

#include "/sys/lib.h"

#include <ansi.h>
inherit "obj/monster";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("the cats");
  set_race("feline");
  set_alias("cats");
  set_short(""+HIW+"A small group of aggressive cats"+NORM+"");
  set_long(
         "These large stray cats seem to think together as one when they hunt\n"+
         "for their food. You notice them all simultaneously staring at you\n"+
         "with that hungry look in their eyes.\n");
  set_level(20);
  set_hp(400 + random (200));
  set_ac(16 + random (8));
  set_wc(28 + random (14));
  set_al(-1000);
  set_aggressive(1);
  set_heal(8,2);
  set_chat_chance(10);
  load_chat("The cats slink around you on all sides.\n");
  load_chat("You suddenly become very uncomfortable around the crazed felines.\n");
  load_chat("Your sense of security leaves you suddenly.\n");
  set_chance(20);
  set_spell_dam(random (15) + 18);
  set_spell_mess2("The cats pounce on you, their claws ripping into your face and eyes!\n");
  set_spell_mess1("The cats pounce on their prey, claws ripping into their face and eyes!\n");
  move_object("/players/chip/items/apartment/animalcollar.c");
  set_dead_ob(this_object());
  }
monster_died()
   {
      int furclumps;
      furclumps = random(5) + 2; 
      while (furclumps > 0)
      {
         move_object(clone_object("/players/chip/items/apartment/furclumps.c"), this_object());
         furclumps--;
      }
   }

/*
 *    File: /players/chip/mobs/apartment/dog2.c
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
  set_name("pitbull");
  set_race("canine");
  set_alias("dog");
  set_short(""+HIR+"A rabid pitbull"+NORM+"");
  set_long(
         "Foam surrounds this large, violent dog's mouth, an indication that he\n"+
         "is infected with the rabies virus. Aside from that, he seems to have\n"+
         "the mange as well, his fur all matted down...what is left of it.\n");
  set_level(20);
  set_hp(400 + random (200));
  set_ac(16 + random (8));
  set_wc(28 + random (14));
  set_al(-1000);
  set_aggressive(1);
  set_heal(8,2);
  set_chat_chance(10);
  load_chat("The pitbull growls deeply.\n");
  load_chat("You suddenly become very uncomfortable around the beast.\n");
  load_chat("The pitbull tears some flesh away from a dead body, and eats it.\n");
  set_chance(20);
  set_spell_dam(random (15) + 18);
  set_spell_mess2("The diseased canine lunges at you, his jaws snapping into your throat!\n");
  set_spell_mess1("The diseased canine lunges at his enemy, his jaws snapping into their throat!\n");
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

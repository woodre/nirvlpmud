/*
 *    File: /players/chip/mobs/apartment/felon2.c
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
  set_name("felon");
  set_race("human");
  set_alias("felon");
  set_short(""+HIB+"A huge, cold, murderous felon"+NORM+"");
  set_long(
         "Looking into the eyes of this heartless killer, you see\n"+
         "absolutely no emotion nor remorse. As he stares back, you\n"+
         "notice his eyes glaze over and you begin to get nervous.\n");
  set_level(20);
  set_hp(400 + random (200));
  set_ac(16 + random (8));
  set_wc(28 + random (14));
  set_al(-1000);
  set_aggressive(1);
  set_heal(8,2);
  set_chat_chance(10);
  load_chat("You see something shiny in the felon's wasteband...\n");
  load_chat("The felon flashes his pistol to you as a warning.\n");
  set_chance(20);
  set_spell_dam(random (15) + 18);
  set_spell_mess2("Your skull rips open violently as the felon unloads his .45 in it.\n");
  set_spell_mess1("The felon unloads his .45 into his foe's skull, ripping it apart.\n");
  move_object("/players/chip/items/apartment/brokenshank.c");
  set_dead_ob(this_object());
  }
monster_died()
   {
      int cigarettes;
      cigarettes = random(5) + 2; 
      while (cigarettes > 0)
      {
         move_object(clone_object("/players/chip/items/apartment/cigarette.c"), this_object());
         cigarettes--;
      }
   }

/*
 *    File: /players/chip/mobs/apartment/psycho1.c
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
  set_name("psychopath");
  set_race("human");
  set_alias("psychopath");
  set_short(""+HIG+"A schitzophrenic psychopath"+NORM+"");
  set_long(
         "There is no fear nor emotion in this man's eyes. He has no\n"+
         "expression on his face one moment, then is either highly\n"+
         "angered or giddy like a schoolgirl the next. Crazy much?\n");
  set_level(20);
  set_hp(400 + random (200));
  set_ac(16 + random (8));
  set_wc(28 + random (14));
  set_al(-1000);
  set_aggressive(1);
  set_heal(8,2);
  set_chat_chance(10);
  load_chat("The psychopath stands still, just smiling into nothingness.\n");
  load_chat("You are startled as the psychopath suddenly bursts into an angry, screaming rage.\n");
  set_chance(20);
  set_spell_dam(random (15) + 18);
  set_spell_mess2("The psychopath sticks you with a syringe full of thorazine.\n");
  set_spell_mess1("The psychopath sticks his enemy with a thorazine syringe.\n");
  move_object("/players/chip/items/apartment/silvchain.c");
  set_dead_ob(this_object());
  }
monster_died()
   {
      int tablets;
      tablets = random(5) + 2; 
      while (tablets > 0)
      {
         move_object(clone_object("/players/chip/items/apartment/lithium.c"), this_object());
         tablets--;
      }
   }

   status id(string arg) { return ( arg == "psycho" || arg == "psychopath" ); }
   
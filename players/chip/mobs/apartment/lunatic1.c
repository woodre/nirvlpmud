/*
 *    File: /players/chip/mobs/apartment/lunatic1.c
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
  set_name("lunatic");
  set_race("human");
  set_alias("inmate");
  set_short(""+HIG+"An escaped asylum inmate"+NORM+"");
  set_long(
         "His eyes keep swimming around in his head, due to the meds\n"+
         "he has been forced on at the asylum before his big escape.\n"+
         "His grin is mischevious, and his straightjacket is broken.\n");
  set_level(20);
  set_hp(400 + random (200));
  set_ac(16 + random (8));
  set_wc(28 + random (14));
  set_al(-1000);
  set_aggressive(1);
  set_heal(8,2);
  set_chat_chance(10);
  load_chat("The lunatic cackles loudly, for no apparent reason.\n");
  load_chat("You feel unsafe as the whacked out inmate stares at you with an evil grin.\n");
  set_chance(20);
  set_spell_dam(random (15) + 18);
  set_spell_mess2("The crazy escapee bites your arm as hard as he can.\n");
  set_spell_mess1("The crazed lunatic bites his enemy's arm extremely hard.\n");
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

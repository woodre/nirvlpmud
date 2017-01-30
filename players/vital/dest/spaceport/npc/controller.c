/******************************************************************************
 *  File:           controller.c
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 1997 Vital@Nirvana
 *                  All Rights Reserved.
 *  Source:         Started 2001.03.06
 *  Notes:
 *  Change History: 2003.09.11; 2005.10.22 [strict_type'd and fixed ids]
 *****************************************************************************/
#pragma strict_types
#include <ansi.h>
#include "/players/vital/dest/include/spaceport.h"

inherit "/players/vital/closed/std/monster.c";

void add_stuff();

void
reset(status arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("spaceport controller");
  set_alt_name("computer");
  set_race("machine");
  set_alias("controller");
  set_short();
  set_long(format("This large, robotic figure blends in with the background \
so well that it is almost invisible. It is responsible for the maintenance \
and processes of keeping the machinery under N.U.T.S."));
  set_level(24);
  set_attrib("str",18);
  set_attrib("pie",18);
  set_attrib("wil",18);
  set_attrib("int",18);
  set_assist(SPNPC + "nanobot.c", 5, 6, 100);
  set_chance(random(25) + 25);
  set_spell_mess1("Controller " + BLINK + HIY + "pulses " + NORM + " with electricity.\n\n");
  set_spell_mess2(HIR + "Spa" + HIW + "rks" + NORM + " fly!\n\t\t" + BLINK + " Phhhzzzzt" + NORM + "\n\t\t\t\t" + HIY + "Bling!" + NORM + "\n");
  set_spell_dam(random(15) + 5);
  set_chat_chance(random(15) + 10);
  load_chats( (
  {
    "The Controller notices a light blinking and adjusts a console.\n",
    "The Controller beeps softly and then goes silent.\n",
    "The Controller scans your brainwave patterns.\n"
  }) );
  set_a_chat_chance(60);
  load_a_chats( 
  ({
    "The Controller yells: \"Stop It!\"\n",
    "The Controller arcs eletricity around the room from wire to wire.\n",
    "The Controller screams: \"You will ruin everything!\"\n",
    "The pistons shudder and the sparks fly.\n"
  }) );
  set_info(format("This computer has actually designed other computers. \
The computers and equipment that it designed are of a fantastic value \
and quality.\n"));
  add_stuff();
  command("invisible");
}

void
add_stuff()
{
  object a, b;
  a = clone_object(SPOBJ + "chit.c");
  a->set_value(4500 + random(1000));
  move_object(a, this_object());
  b = clone_object(SPWEAPON + "super_pda.c");
  move_object(b, this_object());
}

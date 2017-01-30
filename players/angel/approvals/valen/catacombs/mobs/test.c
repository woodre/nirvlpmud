/*                                                                    *
 *    File: valen  /players/valen/area/catacombs/mobs/test.c          *
 *    Function:         mob                                           *
 *    Author(s):        valen@Nirvana                                 *
 *    Copyright:        Copyright (c) 2009 valen                      *
 *                              All Rights Reserved.                  *
 *    Source:           08/09/09                                      *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "obj/monster";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("Anakin");
  set_alt_name("figure"); /*any additional names you wish players to ues*/
  set_race("action figure");
  set_alias("anakin");
  set_short("Anakin");
  set_long("  Anakin Skywalker transforms before your eyes into legendary\n"+
"bad guy Darth Vader. The basic action figure is of pre-dark side\n"+
"Anakin and while he�s not the most finely detailed figure ever\n"+
"made, there is still a glint of menace in his eyes. Anakin come\n"+
"with a head, interchangeable hands, tunic, two belts, pants, sash,\n"+
"two pairs of boots, two lightsabers, Vader head, Vader armor,\n"+
"shoulder plates, headgear, undercloak, cape and gloves.\n");
  set_level(21);
  set_hp(560 + random (100));
  set_ac(20 + random (9));  /*use mud mod levels and can be flexible*/    
  set_wc(38 + random (9));  /*raise one lower another or I like to*/
  set_al(0);                /*use random to make things diff all of the time*/   
  set_chat_chance(15);
  load_chat(query_name()+" says, \"Come over to the "+HIB+"Dark Side!"+NORM+"\n");
  load_chat("You feel the presence of the force move through you!\n");
  add_spell("saber","#MN# slices his light $HR$saber$N$ through you.\n",
                     "#MN# slices his light $HR$saber$N$ through #TN#.\n",
                     50,60,"other|fire");     /*basic spell*/
}
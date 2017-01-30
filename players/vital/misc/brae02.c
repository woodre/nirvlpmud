/******************************************************************************
 *  File:           brae.c
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 1997 Vital@Nirvana
 *                  All Rights Reserved.
 *  Source:         Started 11/30/01
 *  Notes:          	
 *  Change History: 
 *****************************************************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
inherit "/obj/monster.c";

reset(arg)
{
    ::reset(arg);
    if(arg) return;
    set_name("brae");
    set_alias("dragon");
    set_short("A "+RED+"brae"+NORM);
    set_long("\
  This dragon is the smallest of all the various types known. It is \n\
often no bigger than a hedgehog, and is covered in distinctive flames \n\
that dance across its body.\n");
    set_level(36);
    set_wc(25);
    set_hp(10);
    set_info("The "+RED+"brae"+NORM+" is wonderful pet for people in colder climates.\n");
    set_dead_ob(this_object());
}

monster_died()
{
    object corpse, nail;
    corpse = present("corpse", environment());
    corpse->set_name(RED+"brae"+NORM);
    corpse->set_value(6);
    say("The "+RED+"brae"+NORM+" shudders and collapses.\n");
    nail = CO("/players/vital/closed/std/obj.c");
    nail->set_name("nail");
    nail->set_short(RED+"brae"+NORM+" "+HIW+"nail"+NORM);
    nail->set_long("\
  This little "+RED+"red "+HIW+"nail"+NORM+" is a vicious looking \n\
implement. It is a good thing it is not attached to a living brae.\n");
    nail->set_value(25+random(100));
    nail->set_info("\
  The nails of the brae are sought by some shops for \n\
medicinal and arms manufacturing.\n");
    MO(nail,corpse);
    return 1;
}

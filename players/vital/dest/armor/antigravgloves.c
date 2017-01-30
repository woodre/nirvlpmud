/*
 *  antigravgloves.c
 *  Nirvana Development
 *
 *  Created by Vital on Wed Dec 11 2002.
 *  Copyright (c) 2002 by VitalCode.
 *  All rights reserved.
 */

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/dest/include/spaceport.h"

inherit "/obj/armor.c";

string *ids;

reset(arg)
{
    ::reset(arg);
    if(arg) return;
    set_name("antigrav gloves");
    set_alias("antigrav");
    set_type("ring"); /* armor, helmet, boots, ring, amulet, shield, misc */
    set_id( ({ name, alias, type, "antigrav gloves", "gloves", "grav gloves", "gravgloves", "glove", }) );
    set_short("AntiGrav Gloves");
    set_long("  These are the Anitoda Corp. AntiGrav Gloves. They have been designed with the \n\
discriminating fighter in mind and provide an extreme level of protection\n\
in a deceptively comfortable package.\n");
    set_info("This is a very nice pair of gloves.\n");
    set_ac(1);
    set_value(3000+random(3000));
    set_weight(0);
}

int do_special(object owner)
{
    
}

void set_id(string *new_ids)
{
    ids = new_ids;
}

int
id(string str)
{
    if(!ids) ids = ({ });
    return (member_array(str, ids) >= 0);
}

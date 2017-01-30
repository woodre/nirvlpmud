/******************************************************************************
 *	File:			angel_glow.c
 *	Function:		main armor with other|fire resistance
 *	Author(s):		Vital@Nirvana
 *	Copyright:		Copyright (c) 2003 v-Dev Code Factory
 *					All Rights Reserved.
 *	Source:			2/1/04
 *	Notes:			
 *	Change History:
 *****************************************************************************/

#pragma combine_strings
#pragma strict_types

#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/color/include/color_armors.h"

inherit "obj/armor";

string *ids;

void set_id(string *new_ids);
int do_special_res(object owner);
void check_armors(object owner);
int set_resistance(object owner);
int query_resistance();

void
reset(status arg)
{
    if(arg) return;
    ::reset(arg);
    set_name("Angel Glow");
    set_alias("glow");
    set_id( ({
        name, alias, "angel glow", "fire01", "red_armor_01",
    }) );
    set_short("Angel Glow");
    set_long("\
  This is the residual glow of a Seraphim, the great Angel of Fire. \n\
It possesses some of the greatest power in the universe and when \n\
used properly, it can provide the owner with great protection and \n\
blessing. When worn it endows upon the bearer his or her own right-\n\
eous glow.\n");
    set_ac(3);     /* By itself this will not be a great armor */
    set_info("This is the last remaining glow of the Seraphim. May \
it protect\nyou well from danger. The legends say that together the\
armors of\nthe angels can walk through fire.\n");
    set_type("armor");
    set_res(5);
    set_special("do_special");
    set_params("other|fire",3,0,"do_special_res");
    set_weight(1); /* Can't really imagine a heavy glow */
    set_value(1020+random(555));
}

int
do_special(object owner)
{
    if ( !random(10) )
    {
        write("The glow around you intensifies and then subsides.\n");
        return 2;
    }
    if ( !random(50) )
    {
        write("You are completely wrapped in the safety of the angel glow.\n");
        return 4;
    }
}

void 
set_id(string *new_ids)
{
    ids = new_ids;
}

int
do_special_res(object owner)
{
    int x;
    check_armors(owner);
    x = set_resistance(owner);

    switch (x)
    {
        case 0:
            return 0000;
        case 1..2:
            return 0101;
        case 3..4:
            return 0204;
        case 5..6:
            return 0305;
        case 7:
            return 0407;
        default:
            return 0000;
    }
}

void
check_armors(object owner)
{
    string *junk;
    int x;
    object test;
    
    junk = REDARMORS;
    x = 0;
    owner = 0;
    
    FOREACH(junk, x)
    {
        if ( test = present( junk[x], owner ) && test->query_worn())
            set_bit(GlobalArmorBit, x);
/*         else */
/*             if ( (x > 0) && (intp(x)) ) clear_bit(GlobalArmorBit, x); */
    }
}

int
set_resistance(object owner)
{
    string *junk;
    int x, y;

    junk = REDARMORS;
    x = 0;
    y = 0;

    while ( x < 7 )
    {
        if ( test_bit(GlobalArmorBit, x) ) y++;
        ++x;
    }
    return y;
}

void
extra_look()
{
    if (environment() == this_player())
      write("You are surrounded by a powerful angelic glow.\n");
    else write(environment()->query_name() + " is surrounded by\
a powerful, angelic glow.\n");
}

int
query_resistance() { return res; }

string
short()
{
    string tmp_short;
    if (!short_desc)
	    return 0;
    if(!this_player()) return short_desc;
        tmp_short = short_desc;
    if (call_other(this_player(), "query_level", 0) > 30)
    {
        tmp_short = tmp_short + "  < ac " + ac + ", "
            +type +", res "+res+" "+protect+">";
    }
    if (worn)
        return tmp_short + " (worn)";
    return tmp_short;
}

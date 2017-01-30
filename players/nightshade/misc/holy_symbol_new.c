inherit "obj/armor";
#include <ansi.h>

/******************************************************************************
 * Program: holy_symbol_new.c
 * Path: /players/nightshade/misc/
 * Type: Armor / Treasure
 * Created: September 2014 by Karash
 *
 * Purpose: A holy symbol made of gold hanging on a chain, which can be worn as
 *          a necklace.  The symbol is an image of the sun.
 *
 * History:
 *          
 ******************************************************************************/


reset(arg)
{
::reset(arg);
if(arg) return;
set_type("necklace");
set_name("symbol");
SetMultipleIds(({"holy symbol"}));
set_short(HIY+"Holy Symbol"+NORM);
set_long("A gold ornament in the shape of the sun rising above rolling hills. It is\n\
the symbol of Lathander, god of light, and hangs from a gold chain.\n");
set_ac(0);
set_weight(1);
set_value(250);
}


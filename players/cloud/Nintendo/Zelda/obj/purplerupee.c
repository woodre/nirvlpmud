/*
 *  Purple Rupee
 *  /Nintendo/Zelda/obj/purplerupee.c
 *  Cloud 2010
 */
 
#include "/obj/ansi.h";
inherit "obj/treasure";

reset(arg)  
{
	if(arg) return;

   	set_name("purple_rupee");
   	set_alias("rupee");
   	set_short(""+HIM+"A Purple Rupee"+NORM+"");
   	set_long("A shimmering, purple gem. It looks very valuable.\n");
   	set_weight(1);
   	set_value(1);
}

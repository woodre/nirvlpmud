/*
 *  Green Rupee
 *  /Nintendo/Zelda/obj/greenrupee.c
 *  Cloud 2010
 */
 
#include "/obj/ansi.h";
inherit "obj/treasure";

reset(arg)  
{
	if(arg) return;

   	set_name("green_rupee");
   	set_alias("rupee");
   	set_short(""+HIG+"A Green Rupee"+NORM+"");
   	set_long("A shimmering, green gem. It looks valuable.\n");
   	set_weight(1);
   	set_value(1);
}

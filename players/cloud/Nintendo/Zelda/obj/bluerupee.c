/*
 *  Blue Rupee
 *  /Nintendo/Zelda/obj/bluerupee.c
 *  Cloud 2010
 */
 
#include "/obj/ansi.h";
inherit "obj/treasure";

reset(arg)  
{
	if(arg) return;

   	set_name("blue_rupee");
   	set_alias("rupee");
   	set_short(""+HIB+"A Blue Rupee"+NORM+"");
   	set_long("A shimmering, blue gem. It looks valuable.\n");
   	set_weight(1);
   	set_value(1);
}

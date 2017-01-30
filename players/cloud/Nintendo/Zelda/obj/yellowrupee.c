/*
 *  Yellow Rupee
 *  /Nintendo/Zelda/obj/yellowrupee.c
 *  Cloud 2010
 */
 
#include "/obj/ansi.h";
inherit "obj/treasure";

reset(arg)  
{
	if(arg) return;

   	set_name("yellow_rupee");
   	set_alias("rupee");
   	set_short(""+HIY+"A Yellow Rupee"+NORM+"");
   	set_long("A shimmering, yellow gem. It looks valuable.\n");
   	set_weight(1);
   	set_value(1);
}

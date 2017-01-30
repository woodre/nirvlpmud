/*
 *  Hylian Shield
 *  /obj/shield.c
 *  Cloud 2010
 *	Very Rare Drop Rate                                      
 */
#include "/obj/ansi.h"
inherit "obj/armor";
reset(arg)
{
	if(arg) return;
   	::reset(arg);
   	set_name("shield");
   	set_short(""+HIB+"Hylian "+HIW+"Shield"+NORM+"");
   	set_alias("shield");
   	set_long("The edges of the shield shine with a bright white.\n"+
   			 "Three small, yellow triangles decorate the top while a \n"+
   			 "magnificent red coat of arms is presented in the center. \n"+
   			 "Bright blue fills in the rest of this large shield.\n");
   	set_type("shield");
   	set_ac(2);
   	set_weight(2);
   	set_value(3000);
}






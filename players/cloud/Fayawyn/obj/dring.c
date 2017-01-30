/*
 *  Dusty Ring
 *  /obj/dring.c
 *  Cloud 2009
 *	!VERY RARE DROP!
 *                                                 
 */
#include "/obj/ansi.h"
inherit "obj/armor";
reset(arg)
{
	if(arg) return;
   	::reset(arg);
   	set_name("dusty ring");
   	set_short(""+HIK+"Dusty Ring"+NORM+"");
   	set_alias("ring");
   	set_long("Made completely of dust, the ring swirls around in a perfect cirle.\n");
   	set_type("ring");
   	set_ac(1);
   	set_weight(1);
   	set_value(5000);
}


do_special(owner)
{
	if(!worn) 
	{
		return;	
	}
	
    if(owner->query_level() > 10)
    {
	    int X;
    	X=random(100);
    	if (X <14)
    	{
     		tell_object(owner, ""+HIK+"The ring swirls around your finger."+NORM+"\n");
			owner->add_spell_point(random(5) + 10);
    	}
	}
	
	else
	{
		return;
	}
	
}


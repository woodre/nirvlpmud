/*
 *  Links Tunic
 *  /obj/tunic.c
 *  Cloud 2012
 *	Very Rare Drop Rate  
 *	Level 15 Require For Special                                    
 */
#include "/obj/ansi.h"
inherit "obj/armor";
reset(arg)
{
	if(arg) return;
   	::reset(arg);
   	set_name("tunic");
   	set_short(""+HIG+"Green Tunic"+NORM+"");
   	set_alias("tunic");
   	set_long("A green hooded tunic that fits around your chest.\n"+
   	         "It shimmers with a faint golden aura.\n");
   	set_type("chest");
   	set_ac(2);
   	set_weight(2);
   	set_value(3000);
}

do_special(owner)
{
	if(!worn) 
	{
		return;	
	}
	
    if(owner->query_level() > 15)
    {
	    int X;
    	X=random(100);
    	if (X <14)
    	{
     		tell_object(owner, "\n\t"+HIY+"/-/-/ The aura around your tunic flashes brightly /-/-/"+NORM+"\n\n");
			owner->add_spell_point(random(5) + 10);
    	}
	}
	
	else
	{
		return;
	}
	
}





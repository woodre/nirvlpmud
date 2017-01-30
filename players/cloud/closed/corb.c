/*
 *  Cloud's Orb of Darkness
 *	Wiz Wep
 *  Cloud 2009
 *	/closed/corb.c
 *	
 *	
 *  
*/

#include "/obj/ansi.h"
 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("Orb");
    set_alias("orb");
    set_short(""+HIW+"Cloud's "+HIM+"Orb "+NORM+"of "+HIK+"darkness"+NORM+"");
    set_long("An "+HIK+"orb"+NORM+" made of swirling "+HIM+"purple mist"+NORM+". Energy radiates\n" +
    		 "from the orb, constently creating small gusts of "+HIC+"wind"+NORM+".\n");
    set_class(200);
    set_weight(1);
    set_value(1);
}